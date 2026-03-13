#include <stdio.h>

#include <lua.h>      // Basic Lua API
#include <lauxlib.h>  // Abstraction Layer for Lua API
#include <lualib.h>   // Functions to Open Lua Libraries

static int accumulate(lua_State* L) {
  const int n = lua_gettop(L);
  double result = 0;
  for (int i = 1; i <= n; ++i) result += luaL_checknumber(L, i);
  lua_pushnumber(L, result);
  return 1;
}

int main(int argc, char** argv) {
  // Create new Lua state to run scripts in.
  lua_State* L = luaL_newstate();
  if (L == NULL) {
    fprintf(stderr, "Failed to create Lua state.\n");
    return 1;
  }

  // Open all available standard Lua libraries.
  luaL_openlibs(L);

  // Register C function in Lua state.
  lua_register(L, "accumulate", accumulate);

  int error = 0;

  // Use command-line arguments as Lua test files.
  for (int i = 1; i < argc; ++i) {
    // Execute Lua script to register its functions.
    error = luaL_dofile(L, argv[i]);
    if (error != LUA_OK) {
      fprintf(stderr, "%s\n", lua_tostring(L, -1));
      lua_pop(L, 1);  // Pop error message.
      break;
    }
    // Get the script's global `test` function.
    lua_getglobal(L, "test");
    // Ensure it actually is a function.
    if (!lua_isfunction(L, -1)) {
      lua_pop(L, 1);  // Pop global variable on the stack.
      fprintf(stderr, "%s: 'test' must be available as function.\n", argv[i]);
      error = 1;
      break;
    }
    // Call the global test function from this side.
    error = lua_pcall(L, 0, 0, 0);
    if (error != LUA_OK) {
      fprintf(stderr, "%s: %s\n", argv[i], lua_tostring(L, -1));
      lua_pop(L, 1);  // Pop error message.
      break;
    }
  }

  // Clean up Lua state at the end of the program.
  lua_close(L);

  return error;
}
