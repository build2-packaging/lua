# liblua - Lua's C/C++ API, Auxiliary Library, and Standard Libraries

Lua is a powerful, efficient, lightweight, embeddable scripting language.
This is the `build2` package for the Lua library.
It provides access to Lua's C/C++ API (the set of C functions available to the host program to communicate with Lua), its auxiliary library (several convenient functions to interface C with Lua), and its standard libraries (useful Lua functions that are implemented in C through the C API).
It does not include the standalone Lua interpreter or compiler.

## Usage
To use `liblua` in your project, add the following configurations to the respective files after you have gained access to a `build2` package repository that contains it.

### `manifest`
To make `liblua` available for import, add the following dependency to the `manifest` of each package in your project that requires it, adjusting the version constraint as appropriate.

    depends: liblua ^5.4.8

### `buildfile`
To import the contained library, use the following declaration in your `buildfile`.

    import liblua = liblua%lib{lua}

Lua's library can be used in both C and C++ projects and, thus, it might be necessary to explicitly nominate the rule that should be used to search for the library in the installed case with an immediate importation.
For C/C++ libraries the two rule options are `c.link` and `cxx.link` and users should match them to the language of their project (see [here](https://github.com/build2/HOWTO/blob/master/entries/convey-additional-information-with-exe-lib.md)).

    import! [rule_hint=c.link] liblua = liblua%lib{lua}    # C Project
    import! [rule_hint=cxx.link] liblua = liblua%lib{lua}  # C++ Project

### C/C++ Header Inclusion
Finally, include the necessary Lua headers in your source code.

**For C:**
```c
#include <lua.h>      // C API
#include <lauxlib.h>  // Auxiliary Library
#include <lualib.h>   // Standard Libraries
```

**For C++:**
```c++
#include <lua.hpp>
```
