./: manifest lib{liblua} exe{lua} exe{luac}

###################################################
# Lua library (for embedding in C/C++ projects):

lib{liblua} : src/cxx{ * -luac.c -lua.c } src/hxx{*}

cxx.poptions =+ "-I$out_root" "-I$src_root" 

objs{*}: cxx.poptions += -DLUA_BUILD_AS_DLL
libs{liblua}: cxx.export.poptions += -DLUA_BUILD_AS_DLL

# Public headers listed in makefile:
lua_public_headers = lua.h luaconf.h lualib.h lauxlib.h lua.hpp

{hxx}{$lua_public_headers}: install = include/lua/
{hxx}{*}: install.subdirs = true

###################################################
# Lua interpreter:

exe{lua} : src/cxx{lua.c} libs{liblua}


###################################################
# Lua compiler:

exe{luac} : src/cxx{luac.c} liba{liblua} 


