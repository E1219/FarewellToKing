cmake_minimum_required (VERSION 2.8.4)

if (BUILD_TEST)
    add_executable (farewelltokingtest FarewellToKingTest.c)
    target_link_libraries (farewelltokingtest farewelltoking farewelltokingstr)
    install (TARGETS farewelltokingtest DESTINATION bin)
endif (BUILD_TEST)

