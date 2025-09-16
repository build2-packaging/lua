# lua - An Embeddable Scripting Language

This is the `build2` package for the Lua scripting language.
Lua is intended to be used both as an embeddable language for any program that needs one, and as a lightweight and efficient stand-alone language.
The package provides the Lua interpreter and compiler.

## Usage
To use `lua` in your project, add the following configurations to the respective files after you have gained access to a `build2` package repository that contains it.

### `manifest`
To make `lua` available for import, add the following (build-time) dependency to the `manifest` of each package in your project that requires it, adjusting the version constraint as appropriate.

    depends: lua ^5.4.8

### `buildfile` and Importable Targets
To import the interpreter and compiler, use the following declarations in your `buildfile`.

    import lua = lua%exe{lua}        # Interpreter
    import luac = lua%exe{luac}      # Compiler

For compatibility with earlier package versions, `lib{lua}` from the `liblua` package can also be imported from the `lua` package directly.
This is deprecated and should not be used for new projects.

    import liblua = lua%lib{lua}

## Configuration

### Use of GNU `readline` for Lua Interpreter
The use of the GNU `readline` library for the Lua interpreter is disabled by default to reduce importation issues during CI runs.
If `readline` is available on your target platform, it is recommended to enable it to improve editing capabilities on the Lua command line.

    config [bool] config.lua.readline ?= false
