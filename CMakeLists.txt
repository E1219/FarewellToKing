cmake_minimum_required (VERSION 2.8.4)
project (FarewellToKing)

subdirs(src test)
set(HEADERS "${CMAKE_SOURCE_DIR}/include")
include_directories(${HEADERS})

option (INCLUDE_STR "Build farewelltokingstr, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test farewelltoking." OFF)

install (FILES ${HEADERS}/FarewellToKing.h ${HEADERS}/FarewellToKingDef.h ${HEADERS}/FarewellToKingMask.h ${HEADERS}/FarewellToKingBoard.h  DESTINATION include)
