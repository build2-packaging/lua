#include <iostream>
#include <memory>

#ifdef LUA_COMPILED_AS_CXX
#include <lua.h>      // Basic Lua API
#include <lauxlib.h>  // Abstraction Layer for Lua API
#include <lualib.h>   // Functions to Open Lua Libraries
#else
#include <lua.hpp>  // Complete C++ Lua API
#endif

static int accumulate(lua_State* L) {
  const int n = lua_gettop(L);
  double result = 0;
  for (int i = 1; i <= n; ++i) result += luaL_checknumber(L, i);
  lua_pushnumber(L, result);
  return 1;
}

int main(int argc, char** argv) {
  // Create RAII-enabled Lua state via `std::unique_ptr`.
  auto state = std::unique_ptr<lua_State, decltype(&lua_close)>(  //
      luaL_newstate(), &lua_close);
  if (!state) {
    std::cerr << "Failed to create Lua state.\n";
    return -1;
  }
  auto L = state.get();

  // Open all available standard Lua libraries.
  luaL_openlibs(L);

  // Register C function in Lua state.
  lua_register(L, "accumulate", accumulate);

  // Use command-line arguments as Lua test files.
  for (int i = 1; i < argc; ++i) {
    // Execute Lua script to register its functions.
    if (luaL_dofile(L, argv[i]) != LUA_OK) {
      std::cerr << lua_tostring(L, -1) << std::endl;
      lua_pop(L, 1);  // Pop error message.
      return 1;
    }
    // Get the script's global `test` function.
    lua_getglobal(L, "test");
    // Ensure it actually is a function.
    if (!lua_isfunction(L, -1)) {
      lua_pop(L, 1);  // Pop global variable on the stack.
      std::cerr << argv[i] << ": 'test' must be available as function.\n";
      return 1;
    }
    // Call the global test function from this side.
    if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
      std::cerr << argv[i] << ": " << lua_tostring(L, -1) << std::endl;
      lua_pop(L, 1);  // Pop error message.
      return 1;
    }
  }
}
