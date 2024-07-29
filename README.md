# build2 Package for Lua

This project is a [build2](https://build2.org) package repository that provides access to [Lua](https://lua.org/home.html), a powerful, efficient, lightweight, embeddable scripting language.
It supports procedural programming, object-oriented programming, functional programming, data-driven programming, and data description.

[![Official](https://img.shields.io/website/https/www.lua.org?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online)](https://www.lua.org/)
[![build2](https://img.shields.io/website/https/github.com/build2-packaging/lua.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online)](https://github.com/build2-packaging/lua)

[![cppget.org](https://img.shields.io/website/https/cppget.org/liblua.svg?down_message=offline&label=liblua+cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/liblua)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/liblua.svg?down_message=empty&down_color=blue&label=liblua+queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/liblua)

[![cppget.org](https://img.shields.io/website/https/cppget.org/lua.svg?down_message=offline&label=lua+cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/lua)
[![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/lua.svg?down_message=empty&down_color=blue&label=lua+queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/lua)

## Usage
Make sure to add the stable section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch the packages.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/lua.git

Add the respective dependencies in your project's `manifest` file to make the required packages available for import.

    depends: liblua ^5.4.7  # C Library for Embedding Lua
    depends: lua ^5.4.7     # Lua Interpreter and Compiler

Then use the following lines in your `buildfile` to import library and executables.

    import liblua = liblua%lib{lua}  # Library
    import luac = lua%exe{luac}      # Compiler
    import lua = lua%exe{luac}       # Interpreter

For backwards compatibility to earlier package versions, use the following line to import `lib{lua}` from the `lua` package directly.
This is deprecated and should not be used for new projects.

    import liblua = lua%lib{lua}

## Configuration

### Use of GNU `readline` for Lua Interpreter
The use of the GNU `readline` library for the Lua interpreter is disabled by default to reduce importation issues during CI runs.
If `readline` is available on your target platform, it is recommended to enable it to improve editing capabilities on the Lua command line.

    config [bool] config.lua.readline ?= false

## Issues and Notes
- Lua's source code for releases is not provided as a git repository and needs to be hard-copied into the `upstream` directory from [here](https://lua.org/download.html).
- Lua's test suite for releases is not provided as a git repository and needs to be hard-copied into the `upstream-tests` directory from [here](https://www.lua.org/tests/).
- The `LICENSE` file was hard-copied from [Lua's website](https://lua.org/license.html).
- Lua's compiler and interpreter have not been split into separate packages to reduce complexity and importation issues. In most cases, interpreter and compiler will be used together at the same time anyway.
- There are no sophisticated upstream tests for Lua's C library. As such, we only provide two smoke tests.
- So far, the Lua compiler `luac` is only compiled and not further tested. There are also no real upstream tests for it.
- The tests package does not run Lua's complete or internal test suites as these are expected to fail for various reasons as stated [here](https://www.lua.org/tests/). Instead, only the basic tests based on Lua scripts are executed.
- Lua's basic tests fail for unoptimized builds on Windows with MSVC and Clang. This is most likely caused by an intentional stack overflow in the basics tests scripts that might not be properly caught.

## Contributing
Thank you in advance for your help and contribution to keep this package up-to-date.
Please, file an issue on [GitHub](https://github.com/build2-packaging/lua/issues) for questions, bug reports, or to recommend updating the package version.
If you're making a pull request to fix bugs or update the package version yourself, refer to the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml#core-version-management).
