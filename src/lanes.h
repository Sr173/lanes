﻿#if !defined( __lanes_h__)
#define __lanes_h__ 1

#include "platform.h"

#if (defined PLATFORM_WIN32) || (defined PLATFORM_POCKETPC)
#define LANES_API __declspec(dllexport)
#else
#define LANES_API
#endif // (defined PLATFORM_WIN32) || (defined PLATFORM_POCKETPC)

#define LANES_VERSION_MAJOR 3
#define LANES_VERSION_MINOR 14
#define LANES_VERSION_PATCH 0

#define LANES_MIN_VERSION_REQUIRED(MAJOR, MINOR, PATCH)     ((LANES_VERSION_MAJOR>MAJOR) || (LANES_VERSION_MAJOR==MAJOR && (LANES_VERSION_MINOR>MINOR || (LANES_VERSION_MINOR==MINOR && LANES_VERSION_PATCH>=PATCH))))
#define LANES_VERSION_LESS_THAN(MAJOR, MINOR, PATCH)        ((LANES_VERSION_MAJOR<MAJOR) || (LANES_VERSION_MAJOR==MAJOR && (LANES_VERSION_MINOR<MINOR || (LANES_VERSION_MINOR==MINOR && LANES_VERSION_PATCH<PATCH))))
#define LANES_VERSION_LESS_OR_EQUAL(MAJOR, MINOR, PATCH)    ((LANES_VERSION_MAJOR<MAJOR) || (LANES_VERSION_MAJOR==MAJOR && (LANES_VERSION_MINOR<MINOR || (LANES_VERSION_MINOR==MINOR && LANES_VERSION_PATCH<=PATCH))))
#define LANES_VERSION_GREATER_THAN(MAJOR, MINOR, PATCH)     ((LANES_VERSION_MAJOR>MAJOR) || (LANES_VERSION_MAJOR==MAJOR && (LANES_VERSION_MINOR>MINOR || (LANES_VERSION_MINOR==MINOR && LANES_VERSION_PATCH>PATCH))))
#define LANES_VERSION_GREATER_OR_EQUAL(MAJOR, MINOR, PATCH) ((LANES_VERSION_MAJOR>MAJOR) || (LANES_VERSION_MAJOR==MAJOR && (LANES_VERSION_MINOR>MINOR || (LANES_VERSION_MINOR==MINOR && LANES_VERSION_PATCH>=PATCH))))

extern int LANES_API luaopen_lanes_core( lua_State* L);

// Call this to work with embedded Lanes instead of calling luaopen_lanes_core()
extern void LANES_API luaopen_lanes_embedded( lua_State* L, lua_CFunction _luaopen_lanes);

typedef void(*new_lua_state_callback)(lua_State* from, lua_State* new_s);

extern void LANES_API lua_lanes_set_create_callback(new_lua_state_callback callback);


#endif // __lanes_h__