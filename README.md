# build2 Package Repository for Lua

This is a [build2](https://build2.org) package repository for the [Lua](https://lua.org/home.html) scripting language.
Lua is intended to be used both as an embeddable language for any program that needs one, and as a lightweight and efficient stand-alone language.

This repository is a community-maintained effort and is not officially endorsed by the Lua authors.

## Packages

| Package | Summary | Status |
|---|---|---|---|
| **[`liblua`](liblua/PACKAGE-README.md)** | Lua C/C++ Library | [![cppget.org](https://img.shields.io/website/https/cppget.org/liblua.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/liblua) [![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/liblua.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/liblua) |
| **[`lua`](lua/PACKAGE-README.md)** | Lua Interpreter and Compiler | [![cppget.org](https://img.shields.io/website/https/cppget.org/lua.svg?down_message=offline&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online)](https://cppget.org/lua) [![queue.cppget.org](https://img.shields.io/website/https/queue.cppget.org/lua.svg?down_message=empty&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=orange&up_message=running)](https://queue.cppget.org/lua) |

## Usage
If you want to use one of the Lua packages in your `build2`-based project, add an appropriate repository manifest to your project's `repositories.manifest` and refer to the accompanying package descriptions.

### `repositories.manifest`
To be able to fetch this repository's packages, add one of the following prerequisites to your project's `repositories.manifest`.

**Option A: `cppget.org` (Recommended)**

Based on your project's stability requirements, choose either the [`stable` section](https://cppget.org/?about#pkg%3Acppget.org%2Fstable) for thoroughly tested versions or the [`testing` section](https://cppget.org/?about#pkg%3Acppget.org%2Ftesting) for the latest releases before they are marked as stable.
For example:

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

**Option B: Git Repository**

    :
    role: prerequisite
    location: https://github.com/build2-packaging/lua.git

## Development Setup
The development setup for this repository uses the standard `bdep`-based workflow.
For guidance on package maintenance, please see [The `build2` Toolchain Introduction](https://build2.org/build2-toolchain/doc/build2-toolchain-intro.xhtml), [The `build2` Build System Manual](https://build2.org/build2/doc/build2-build-system-manual.xhtml), and [The `build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml).

First, clone the repository via SSH or HTTPS.

    git clone --recurse https://github.com/build2-packaging/lua.git  # HTTPS
    git clone --recurse git@github.com:build2-packaging/lua.git      # SSH

Inside the repository's directory, initialize your build configuration.

    bdep init -C @gcc cc config.cxx=g++ config.install.root=../.install config.dist.root=../.dist

Afterwards, use `b` or `bdep` to build, test, install, and distribute the packages.

## Issues and Notes
- **Upstream Sources:** Lua's source code and test suite are not available as versioned Git repositories. They are manually copied into the `upstream/` and `upstream-tests/` directories from the [official download](https://lua.org/download.html) and [testing](https://www.lua.org/tests/) pages. The `LICENSE` file is also copied from the [Lua website](https://lua.org/license.html). For each version update, it is recommended to directly delete the `upstream/` and `upstream-tests/` directories and move the newly downloaded sources to these locations.

- **Packaging Decisions:**
    - The `lua` and `luac` executables are kept in a single `lua` package to simplify maintenance and maintain backward compatibility.
    - Documentation files are only installed with the `lua` package to prevent redundancy.

- **Testing Limitations:**
    - Upstream does not provide a comprehensive test suite for the C library; therefore, the `liblua` package only includes basic smoke tests.
    - The `luac` executable in the `lua` package is built but not extensively tested due to a lack of upstream tests.
    - The `lua-tests` package executes only the basic Lua script tests. The complete or internal test suite is not used as it is expected to fail by design in this build context (see [here](https://www.lua.org/tests/)).
    - On Windows (MSVC/Clang), the basic tests are known to fail in unoptimized builds, likely due to an intentional stack overflow test.

- **Metadata:** Currently, the `lua` and `luac` executables in the `lua` package do not provide any `build2` metadata.

## Contributing
Contributions are welcome and greatly appreciated!
Please start by [opening an issue](https://github.com/build2-packaging/lua/issues) to report a bug, suggest an improvement, or request a version update.
This helps us coordinate efforts and avoid duplicate work.
You are then welcome to submit a [pull request](https://github.com/build2-packaging/lua/pulls) that references the issue.
For guidance on package maintenance, please see the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml).
