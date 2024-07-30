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

  // Clean up Lua state at the end of the program.
  //
  lua_close(L);
}
