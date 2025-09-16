# liblua - Lua's C/C++ API, Auxiliary Library, and Standard Libraries

Lua is a powerful, efficient, lightweight, embeddable scripting language.
This is the `build2` package for the Lua library.
It provides access to Lua's C/C++ API (the set of C functions available to the host program to communicate with Lua), its auxiliary library (several convenient functions to interface C with Lua), and its standard libraries (useful Lua functions that are implemented in C through the C API).

## Usage
To use `liblua` in your project, add the following configurations to the respective files after you have gained access to a `build2` package repository that contains it.

### `manifest`
To make `liblua` available for import, add the following dependency to the `manifest` of each package in your project that requires it, adjusting the version constraint as appropriate.

    depends: liblua ^5.4.8

### `buildfile`
To import the contained library, use the following declaration in your `buildfile`.

    import liblua = liblua%lib{lua}

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
