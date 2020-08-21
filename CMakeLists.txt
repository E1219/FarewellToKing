cmake_minimum_required (VERSION 2.8.4)
project (farewell_to_king)

subdirs(src test)
set(HEADERS "${CMAKE_SOURCE_DIR}/include")
include_directories(${HEADERS})

option (INCLUDE_STR "Build farewell_to_king_strings, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test Farewell to King." OFF)

install (FILES ${HEADERS}/farewell_to_kings.h ${HEADERS}/farewell_to_kings_types.h ${HEADERS}/FarewellToKingMask.h ${HEADERS}/FarewellToKingBoard.h  DESTINATION include)
