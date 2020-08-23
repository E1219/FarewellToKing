cmake_minimum_required (VERSION 3.16.3)
project (farewell_to_king)

subdirs(src test)
set(HEADERS "${CMAKE_SOURCE_DIR}/include")
include_directories(${HEADERS})

option (INCLUDE_STR "Build farewell_to_king_strings, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test Farewell to King." ON)

install (FILES ${HEADERS}/farewell_to_king.h ${HEADERS}/farewell_to_king_types.h ${HEADERS}/farewell_to_king_mask.h ${HEADERS}/farewell_to_king_board.h  DESTINATION include)
