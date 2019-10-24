./: manifest lib{liblua} exe{lua} exe{luac}


###################################################
# General


exe{*} : install = bin/  # All executables should be installed

###################################################
# Lua library (for embedding in C/C++ projects):

lib{liblua} : src/cxx{ * -luac.c -lua.c } src/hxx{*}

liba{liblua}: cxx.export = true
libs{liblua}: cxx.export.poptions += -DLUA_BUILD_AS_DLL
objs{*}: cxx.poptions += -DLUA_BUILD_AS_DLL

cxx.poptions =+ "-I$out_root" "-I$src_root/src"

###################################################
# Lua interpreter:

exe{lua} : src/cxx{lua} libs{liblua}

###################################################
# Lua compiler:

exe{luac} : src/cxx{luac} liba{liblua} 

#########
# Install
include_dir = include/lua/

# Public headers listed in makefile:
lua_public_headers = lua.h luaconf.h lualib.h lauxlib.h lua.hpp

# We only install public headers.
# TODO: find a better way to do it.
for public_header : src/hxx{*}
    $public_header@./src/ : install = false

for public_header : src/hxx{$lua_public_headers}
    $public_header@./src/ : install = $include_dir

