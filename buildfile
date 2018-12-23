./: manifest lib{liblua} exe{lua} exe{luac}


###################################################
# General

# Public headers listed in makefile:
lua_public_headers = lua.h luaconf.h lualib.h lauxlib.h lua.hpp

# hxx{*} : install = false # Only install headers that are explicitely installed 
exe{*} : install = bin/  # All executables should be installed

###################################################
# Lua library (for embedding in C/C++ projects):

lib{liblua} : src/cxx{ * -luac.c -lua.c } src/hxx{*} src/hxx{$lua_public_headers}

liba{liblua}: cxx.export = true
libs{liblua}: cxx.export.poptions += -DLUA_BUILD_AS_DLL
objs{*}: cxx.poptions += -DLUA_BUILD_AS_DLL

liba{liblua}: src/hxx{lua.hpp} :
{
    install = include/lua/
}
    
cxx.poptions =+ "-I$out_root" "-I$src_root" 

###################################################
# Lua interpreter:

exe{lua} : src/cxx{lua.c} libs{liblua}

###################################################
# Lua compiler:

exe{luac} : src/cxx{luac.c} liba{liblua} 
