cmake_minimum_required (VERSION 3.13.4)

if (BUILD_TEST)
    add_executable (farewell_to_king_test farewell_to_king_test.c)
    target_link_libraries (farewell_to_king_test farewell_to_king farewell_to_king_strings)
    install (TARGETS farewell_to_king_test DESTINATION bin)
endif (BUILD_TEST)

