cmake_minimum_required (VERSION 3.13.4)

set (FTK_SOURCE_FILES farewell_to_king.c farewell_to_king_mask.c farewell_to_king_board.c farewell_to_king_bitops.c)
set (FTK_STRINGS_SOURCE_FILES farewell_to_king_strings.c)

add_library(farewell_to_king_obj OBJECT ${FTK_SOURCE_FILES})
add_library(farewell_to_king_strings_obj OBJECT ${FTK_STRINGS_SOURCE_FILES})

if(BUILD_SHARED)
    set_directory_properties(TARGET farewell_to_king_obj         PROPERTY POSITION_INDEPENDENT_CODE 1)
    set_directory_properties(TARGET farewell_to_king_strings_obj PROPERTY POSITION_INDEPENDENT_CODE 1)

    add_library (farewell_to_king_shared SHARED $<TARGET_OBJECTS:farewell_to_king_obj>)
    install (TARGETS farewell_to_king_shared DESTINATION lib)

    if(INCLUDE_STR)
        add_library (farewell_to_king_strings_shared SHARED $<TARGET_OBJECTS:farewell_to_king_strings_obj>)
        target_link_libraries (farewell_to_king_strings_shared farewell_to_king_shared)
        install (TARGETS farewell_to_king_strings_shared DESTINATION lib)
        install (FILES ${HEADERS}/farewell_to_king_strings.h DESTINATION include)
    endif (INCLUDE_STR)
endif (BUILD_SHARED)

if(BUILD_STATIC)
    add_library (farewell_to_king_static STATIC $<TARGET_OBJECTS:farewell_to_king_obj>)
    install (TARGETS farewell_to_king_static DESTINATION lib)

    if(INCLUDE_STR)
        add_library (farewell_to_king_strings_static STATIC $<TARGET_OBJECTS:farewell_to_king_strings_obj>)
        target_link_libraries (farewell_to_king_strings_static farewell_to_king_static)
        install (TARGETS farewell_to_king_strings_static DESTINATION lib)
        install (FILES ${HEADERS}/farewell_to_king_strings.h DESTINATION include)
    endif (INCLUDE_STR)
endif (BUILD_STATIC)