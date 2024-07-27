# build2 Package for Lua

This project is a [build2](https://build2.org) package repository that provides access to [Lua](https://lua.org/home.html), a powerful, efficient, lightweight, embeddable scripting language.
It supports procedural programming, object-oriented programming, functional programming, data-driven programming, and data description.

## Usage
Make sure to add the stable section of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch this package.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If the stable section of `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/lua.git

Add the respective dependency in your project's `manifest` file to make the package available for import.

    depends: liblua ^5.4.7
    depends: lua ^5.4.7

Then use the following line in your `buildfile` to import the library.

    import lua = liblua%lib{lua}
    import luac = lua%exe{lua}

## Configuration
There are no configuration options available.

## Issues and Notes
- Lua's source code for releases is not provided as a git repository and needs to be hard-copied into the `upstream` directory from [here](https://lua.org/download.html).
- Lua's test suite for releases is not provided as a git repository and needs to be hard-copied into the `upstream-tests` directory from [here](https://www.lua.org/tests/).
- The `LICENSE` file was hard-copied from [Lua's website](https://lua.org/license.html).

## Contributing
Thank you in advance for your help and contribution to keep this package up-to-date.
Please, file an issue on [GitHub](https://github.com/build2-packaging/lua/issues) for questions, bug reports, or to recommend updating the package version.
If you're making a pull request to fix bugs or update the package version yourself, refer to the [`build2` Packaging Guidelines](https://build2.org/build2-toolchain/doc/build2-toolchain-packaging.xhtml#core-version-management).
