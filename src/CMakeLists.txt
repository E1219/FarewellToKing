cmake_minimum_required (VERSION 2.8.4)

add_library (farewelltoking SHARED FarewellToKing.c FarewellToKingMask.c FarewellToKingBoard.c)

if(INCLUDE_STR)
    add_library (farewelltokingstr SHARED FarewellToKingStr.c)
    install (TARGETS farewelltokingstr DESTINATION lib)
    install (FILES ${HEADERS}/FarewellToKingStr.h DESTINATION include)
endif (INCLUDE_STR)

install (TARGETS farewelltoking DESTINATION lib)
