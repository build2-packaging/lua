./ : manifest lib{liblua} exe{lua} exe{luac} tests/

./ : doc/doc{**} doc{README}

# Don't install tests.
#
tests/: install = false


###################################################
# Lua library (for embedding in C/C++ projects):

lib{liblua} : src/cxx{ * -luac.c -lua.c } src/hxx{* lua.hpp}

# TODO: ask why these lines are necessary?
liba{liblua}: cxx.export = true # Have to be mentionned otherwise it's not exported??
libs{liblua}: cxx.export = true # Have to be mentionned otherwise it's not exported??

if ($cxx.target.class == 'windows')
{
    libs{liblua}: 
    {
        # TODO: report that using cc here makes includes dir not exported/imported.
        cxx.export.poptions += -DLUA_BUILD_AS_DLL
        c.export.poptions += -DLUA_BUILD_AS_DLL
    }
    objs{*}: cxx.poptions += -DLUA_BUILD_AS_DLL
}

dirs_to_include = "-I$out_root/src" "-I$src_root/src"

cxx.poptions =+ $dirs_to_include

# TODO: report that changing cc by cxx here makes includes dir not exported/imported.
lib{liblua} : cc.export.poptions =+ $dirs_to_include

###################################################
# Lua interpreter:

exe{lua} : src/cxx{lua} libs{liblua}

###################################################
# Lua compiler:

exe{luac} : src/cxx{luac} liba{liblua} 

###############
# Install Setup
include_dir = include/

# Public headers listed in makefile:
lua_public_headers = lua.h luaconf.h lualib.h lauxlib.h lua.hpp

# We only install public headers.
# TODO: find a better way to do it.
for public_header : src/hxx{*}
    $public_header@./src/ : install = false

for public_header : src/hxx{$lua_public_headers}
    $public_header@./src/ : install = $include_dir


# All executables should be installed
exe{*} : install = bin/
