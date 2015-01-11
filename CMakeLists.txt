cmake_minimum_required (VERSION 2.8.4)
project (FlyByKnightLib)

option (INCLUDE_STR "Build flybyknightlibstr, includes operations to generate formatted strings." ON)
option (BUILD_TEST "Build executable to test flybyknightlib." OFF)

add_library (flybyknightlib flyByKnightLib.c flyByKnightLibMask.c flyByKnightLibBoard.c)

if(INCLUDE_STR)
    add_library (flybyknightlibstr flyByKnightLibStr.c)
    set (ADDITIONAL_BIN ${ADDITIONAL_BIN} flybyknightlibstr)
    set (ADDITIONAL_INCLUDE ${ADDITIONAL_INCLUDE} flyByKnightLibStr.h)
endif (INCLUDE_STR)

if (BUILD_TEST)
    add_executable (flybyknightlibtest flyByKnightLibTest.c)
    target_link_libraries (flybyknightlibtest flybyknightlib flybyknightlibstr)
    set (ADDITIONAL_BIN ${ADDITIONAL_BIN} flybyknightlibtest)
endif (BUILD_TEST)

install (TARGETS flybyknightlib ${ADDITIONAL_BIN} DESTINATION bin)
install (FILES flyByKnightLib.h flyByKnightLibMask.h flyByKnightLibBoard.h ${ADDITIONAL_INCLUDE} DESTINATION include)
