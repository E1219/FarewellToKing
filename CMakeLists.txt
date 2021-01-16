cmake_minimum_required (VERSION 3.13.4)
project (farewell_to_king)

subdirs(src test)
set(HEADERS "${CMAKE_SOURCE_DIR}/include")
include_directories(${HEADERS})

option (BUILD_SHARED "Build farewell_to_king as a shared library." OFF)
option (BUILD_STATIC "Build farewell_to_king as a static library." ON)
option (INCLUDE_STR "Build farewell_to_king_strings, includes operations to generate formatted strings." ON)

option (BUILD_TEST "Build executable to test Farewell to King." ON)
option (BUILD_DEBUG "Build Farewell to King with debug symbols enabled." ON)

if(NOT (BUILD_SHARED OR BUILD_STATIC))
  message(FATAL_ERROR "BUILD_STATIC and/or BUILD_SHARED must specified to build Farewell to King")
endif ()

if(BUILD_DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
endif(BUILD_DEBUG)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

install (FILES ${HEADERS}/farewell_to_king.h ${HEADERS}/farewell_to_king_types.h ${HEADERS}/farewell_to_king_mask.h ${HEADERS}/farewell_to_king_board.h  ${HEADERS}/farewell_to_king_bitops.h DESTINATION include)