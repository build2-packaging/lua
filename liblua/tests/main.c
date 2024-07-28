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

  // Clean up Lua state at the end of the program.
  //
  lua_close(L);

  return 0;
}
