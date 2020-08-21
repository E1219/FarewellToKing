cmake_minimum_required (VERSION 2.8.4)

add_library (farewell_to_king SHARED farewell_to_king.c FarewellToKingMask.c FarewellToKingBoard.c)

if(INCLUDE_STR)
    add_library (farewell_to_king_strings SHARED FarewellToKingStr.c)
    install (TARGETS farewell_to_king_strings DESTINATION lib)
    install (FILES ${HEADERS}/FarewellToKingStr.h DESTINATION include)
endif (INCLUDE_STR)

install (TARGETS farewell_to_king DESTINATION lib)
