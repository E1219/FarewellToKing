cmake_minimum_required (VERSION 3.13.4)

add_library (farewell_to_king SHARED farewell_to_king.c farewell_to_king_mask.c farewell_to_king_board.c farewell_to_king_bitops.c)

if(INCLUDE_STR)
    add_library (farewell_to_king_strings SHARED farewell_to_king_strings.c)
    target_link_libraries (farewell_to_king_strings farewell_to_king)
    install (TARGETS farewell_to_king_strings DESTINATION lib)
    install (FILES ${HEADERS}/farewell_to_king_strings.h DESTINATION include)
endif (INCLUDE_STR)

install (TARGETS farewell_to_king DESTINATION lib)
