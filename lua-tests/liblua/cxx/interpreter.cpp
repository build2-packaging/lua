#include <iostream>
#include <memory>

// Complete C++ Lua API
//
#include <lua.hpp>

using namespace std;

int main(int argc, char **argv) {
  // Create new Lua state to run scripts in.
  // Use `unique_ptr` to make it RAII capable.
  //
  auto state =
      unique_ptr<lua_State, decltype(&lua_close)>(luaL_newstate(), &lua_close);
  if (!state) {
    cerr << "ERROR: Failed to create Lua state." << endl;
    return -1;
  }
  auto L = state.get();

  // Open all available standard Lua libraries.
  //
  luaL_openlibs(L);

  // Execute string to enable basic testing
  // for standard Lua test scripts.
  //
  if (luaL_dostring(L, "_U=true")) {
    cerr << "ERROR: Failed to set test variable." << endl;
    return -1;
  }

  // Execute all Lua scripts given as command-line arguments.
  //
  for (int i = 1; i < argc; ++i) {
    auto error = luaL_dofile(L, argv[i]);
    if (!error)
      continue;
    cerr << "ERROR: Failed to run script '" << argv[i] << "'." << endl;
    return -1;
  }
}
