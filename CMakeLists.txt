cmake_minimum_required (VERSION 3.26)
project (farewell_to_king)

option (INCLUDE_STR "Build farewell_to_king_strings, includes operations to generate formatted strings." ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DFTK_DEBUG_BUILD")

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(farewell_to_king_source src/farewell_to_king.c
                            src/farewell_to_king_bitops.c
                            src/farewell_to_king_board.c
                            src/farewell_to_king_mask.c)
if(INCLUDE_STR)
  list(APPEND farewell_to_king_source src/farewell_to_king_strings.c)
endif()

add_library(farewell_to_king STATIC ${farewell_to_king_source})
target_include_directories(farewell_to_king PRIVATE include)

add_library(farewell_to_king_shared SHARED ${farewell_to_king_source})
target_include_directories(farewell_to_king_shared PRIVATE include)

add_executable(farewell_to_king_test test/farewell_to_king_test.c)
target_link_libraries(farewell_to_king_test farewell_to_king)