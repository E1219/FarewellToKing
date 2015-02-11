cmake_minimum_required (VERSION 2.8.4)
project (FarewellToKing)

option (INCLUDE_STR "Build farewelltokingstr, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test farewelltoking." OFF)

add_library (farewelltoking FarewellToKing.c FarewellToKingMask.c FarewellToKingBoard.c)

if(INCLUDE_STR)
    add_library (farewelltokingstr FarewellToKingStr.c)
    set (ADDITIONAL_BIN ${ADDITIONAL_BIN} farewelltokingstr)
    set (ADDITIONAL_INCLUDE ${ADDITIONAL_INCLUDE} FarewellToKingStr.h)
endif (INCLUDE_STR)

if (BUILD_TEST)
    add_executable (farewelltokingtest FarewellToKingTest.c)
    target_link_libraries (farewelltokingtest farewelltoking farewelltokingstr)
    set (ADDITIONAL_BIN ${ADDITIONAL_BIN} farewelltokingtest)
endif (BUILD_TEST)

install (TARGETS farewelltoking ${ADDITIONAL_BIN} DESTINATION bin)
install (FILES FarewellToKing.h FarewellToKingMask.h FarewellToKingBoard.h ${ADDITIONAL_INCLUDE} DESTINATION include)
