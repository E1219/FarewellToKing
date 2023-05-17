/*
 farewell_to_king_version.h
 FarewellToKing - Chess Library
 Edward Sandor
 January 2021
 
 Defines Fly by Knight version
*/

#ifndef _FAREWELL_TO_KING_VERSION_H_
#define _FAREWELL_TO_KING_VERSION_H_

#define FAREWELL_TO_KING_VERSION_STR_BASE "1.2.0"

#ifdef FTK_DEBUG_BUILD
#define FAREWELL_TO_KING_VERSION_STR FAREWELL_TO_KING_VERSION_STR_BASE " <debug "__DATE__ " " __TIME__">"
#else
#define FAREWELL_TO_KING_VERSION_STR FAREWELL_TO_KING_VERSION_STR_BASE
#endif



#define FAREWELL_TO_KING_NAME "Farewell to King"
#define FAREWELL_TO_KING_NAME_VER "Farewell to King " FAREWELL_TO_KING_VERSION_STR
#define FAREWELL_TO_KING_AUTHOR "Edward Sandor"
#define FAREWELL_TO_KING_CONTACT "farewelltoking@sandorlaboratories.com"

#define FAREWELL_TO_KING_INTRO FAREWELL_TO_KING_NAME " version " FAREWELL_TO_KING_VERSION_STR " by " FAREWELL_TO_KING_AUTHOR " <" FAREWELL_TO_KING_CONTACT ">"

#endif //_FAREWELL_TO_KING_VERSION_H_
