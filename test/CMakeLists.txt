cmake_minimum_required (VERSION 3.13.4)

if (BUILD_TEST)
    add_executable (farewell_to_king_test farewell_to_king_test.c)

    if (BUILD_SHARED)
        target_link_libraries (farewell_to_king_test farewell_to_king_shared farewell_to_king_strings_shared)
    else ()
        target_link_libraries (farewell_to_king_test farewell_to_king_static farewell_to_king_strings_static)
    endif ()

    install (TARGETS farewell_to_king_test DESTINATION bin)
endif (BUILD_TEST)

