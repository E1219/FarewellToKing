cmake_minimum_required (VERSION 3.13.4)
project (farewell_to_king)

subdirs(src test)
set(HEADERS "${CMAKE_SOURCE_DIR}/include")
include_directories(${HEADERS})

option (INCLUDE_STR "Build farewell_to_king_strings, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test Farewell to King." ON)
option (BUILD_DEBUG "Build Farewell to King with debug symbols enabled." ON)

if(BUILD_DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
endif(BUILD_DEBUG)

install (FILES ${HEADERS}/farewell_to_king.h ${HEADERS}/farewell_to_king_types.h ${HEADERS}/farewell_to_king_mask.h ${HEADERS}/farewell_to_king_board.h  ${HEADERS}/farewell_to_king_bitops.h DESTINATION include)