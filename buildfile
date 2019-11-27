./ : manifest lib{lua} exe{lua} exe{luac} tests/

./ : doc/doc{**} doc{README}

# Don't install tests.
#
tests/: install = false


###################################################
# Lua library (for embedding in C/C++ projects):

lib{lua} : src/c{ * -luac.c -lua.c } src/{h hxx}{*}

# TODO: ask why these lines are necessary?
liba{lua}: cc.export = true # Have to be mentionned otherwise it's not exported??
libs{lua}: cc.export = true # Have to be mentionned otherwise it's not exported??

if ($cc.target.class == 'windows')
{
    libs{lua}: 
    {
        # TODO: report that using cc here makes includes dir not exported/imported.
        cxx.export.poptions += -DLUA_BUILD_AS_DLL
        c.export.poptions += -DLUA_BUILD_AS_DLL
    }
    objs{*}: c.poptions += -DLUA_BUILD_AS_DLL
}
else
{
    cc.libs += -lm
}

dirs_to_include = "-I$out_root/src" "-I$src_root/src"

cc.poptions =+ $dirs_to_include

lib{lua} : cc.export.poptions =+ $dirs_to_include

###################################################
# Lua interpreter:

exe{lua} : src/c{lua} libs{lua}

###################################################
# Lua compiler:

exe{luac} : src/c{luac} liba{lua} 

###############
# Install Setup
include_dir = include/

# Public headers listed in makefile:
lua_public_c_headers = lua luaconf lualib lauxlib
lua_public_cxx_headers = lua

# We only install public headers.
h{*}: install = false

for public_header : src/h{$lua_public_c_headers} src/hxx{$lua_public_cxx_headers}
  $public_header@./src/ : install = $include_dir


# All executables should be installed
exe{*} : install = bin/
