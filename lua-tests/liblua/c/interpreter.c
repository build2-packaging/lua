#include <stdio.h>
#include <string.h>

// Basic Lua API
//
#include <lua.h>

// Practicable Abstraction Layer for Lua API
//
#include <lauxlib.h>

// Functions to Open Lua Libraries
//
#include <lualib.h>

int main(int argc, char **argv) {

  // Create new Lua state to run scripts in.
  //
  lua_State *L = luaL_newstate();
  if (L == NULL) {
    fprintf(stderr, "ERROR: Failed to create Lua state.\n");
    return -1;
  }

  // Open all available standard Lua libraries.
  //
  luaL_openlibs(L);

  // Execute string to enable basic testing
  // for standard Lua test scripts.
  //
  int result = luaL_dostring(L, "_U=true");

  // Execute all Lua scripts given as command-line arguments.
  //
  for (int i = 1; i < argc; ++i) {
    int error = luaL_dofile(L, argv[i]);
    if (error)
      fprintf(stderr, "ERROR: Failed to run script '%s'.", argv[i]);
    result += error;
  }

  // Clean up Lua state at the end of the program.
  //
  lua_close(L);

  return result;
}
