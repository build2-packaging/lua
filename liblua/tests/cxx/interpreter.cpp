#include <iostream>

// Complete C++ Lua API
//
#include <lua.hpp>

using namespace std;

int main(int argc, char **argv) {
  // Create new Lua state to run scripts in.
  //
  lua_State *L = luaL_newstate();
  if (L == NULL) {
    cerr << "ERROR: Failed to create Lua state." << endl;
    return -1;
  }

  // Open all available standard Lua libraries.
  //
  luaL_openlibs(L);

  // Execute string to enable basic testing
  // for standard Lua test scripts.
  //
  luaL_dostring(L, "_U=true");

  // Execute all Lua scripts given as command-line arguments.
  //
  int result = 0;
  for (int i = 1; i < argc; ++i) {
    auto error = luaL_dofile(L, argv[i]);
    if (error)
      cerr << "ERROR: Failed to run script '" << argv[i] << "'." << endl;
    result |= error;
  }

  // Clean up Lua state at the end of the program.
  //
  lua_close(L);

  return result;
}
