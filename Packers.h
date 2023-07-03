
// ===========================================================================
/// <summary>
/// Packers.h
/// Packers
/// created by Mehrdad Soleimanimajd on 13.04.2019
/// </summary>
/// <created>ʆϒʅ, 13.04.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#ifndef PACKERS_H
#define PACKERS_H

#ifndef UNICODE
#define UNICODE
#endif // UNICODE


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN // rarely-used stuff exclusion
#endif // WIN32


#include <iostream>
#include <string>
//#include <codecvt>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else ifdef __APPLE__
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#endif // _WIN32
//#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <atomic>
#include <list>
#include <stdexcept>

#include "Tale.h"


#define FONT_SIZEx              10
#define FONT_SIZEy              18
//#define FONT_NAME               "Lucida Console"
//#define FONT_NAME               "Cascadia Code Light"
//#define FONT_NAME               "Courier New"
#define FONT_NAME               L"Consolas"
//#define FONT_NAME               "NSimSun"
//#define FONT_NAME               "Raster Fonts"
#define SCREEN_L                2
#define SCREEN_T                2
#define SCREEN_H                44
//? danger:
#define SCREEN_W                90
//! if you choose the next value less than 100, you are on your own, since the packers don't have enough to chew! :)
#define BACKGROUND_COLOUR       RGB (50,50,50)


// loading delay
#define LOAD_ONE                1
#define LOAD_TWO                5


// used mode: chew-forward going!
//? danger: too much quickness gives them the chance chewing the future of this generation too!
//!? avoid equal values
#define DELAY_ONE               101
#define DELAY_TWO               401
#define DELAY_THREE             302
#define DELAY_FOUR              102


#ifdef _WIN32
// colour system
#define F_BLACK                 0x0000
#define F_BLUE                  0x0001
#define F_GREEN                 0x0002
#define F_CYAN                  0x0003
#define F_RED                   0x0004
#define F_PURPLE                0x0005
#define F_YELLOW                0x0006
#define F_WHITE                 0x0007
#define F_bBLACK                0x0008
#define F_bBLUE                 0X0009
#define F_bGREEN                0x000A
#define F_bCYAN                 0x000B
#define F_bRED                  0x000C
#define F_bPURPLE               0x000D
#define F_bYELLOW               0x000E
#define F_bWHITE                0x000F

#define B_BLACK                 0x0000
#define B_BLUE                  0x0010
#define B_GREEN                 0x0020
#define B_CYAN                  0x0030
#define B_RED                   0x0040
#define B_PURPLE                0x0050
#define B_YELLOW                0x0060
#define B_WHITE                 0x0070
#define B_bBLACK                0x0080
#define B_bBLUE                 0X0090
#define B_bGREEN                0x00A0
#define B_bCYAN                 0x00B0
#define B_bRED                  0x00C0
#define B_bPURPLE               0x00D0
#define B_bYELLOW               0x00E0
#define B_bWHITE                0x00F0

#else ifdef __APPLE__
// ANSI escape sequences
// F: forground, B: background, b: bright
//#define F_BLACK(prm)            "\033["+std::to_string(prm)+"m"
#define F_BLACK                 "\033[30m"
#define F_RED                   "\033[31m"
#define F_GREEN                 "\033[32m"
#define F_YELLOW                "\033[33m"
#define F_BLUE                  "\033[34m"
#define F_PURPLE                "\033[35m"
#define F_CYAN                  "\033[36m"
#define F_WHITE                 "\033[37m"
#define F_bBLACK                "\033[90m"
#define F_bRED                  "\033[91m"
#define F_bGREEN                "\033[92m"
#define F_bYELLOW               "\033[93m"
#define F_bBLUE                 "\033[94m"
#define F_bPURPLE               "\033[95m"
#define F_bCYAN                 "\033[96m"
#define F_bWHITE                "\033[97m"

#define B_BLACK                 "\033[40m"
#define B_RED                   "\033[41m"
#define B_GREEN                 "\033[42m"
#define B_BLUE                  "\033[43m"
#define B_YELLOW                "\033[44m"
#define B_PURPLE                "\033[45m"
#define B_CYAN                  "\033[46m"
#define B_WHITE                 "\033[47m"
#define B_bBLACK                "\033[100m"
#define B_bRED                  "\033[101m"
#define B_bGREEN                "\033[102m"
#define B_bYELLOW               "\033[103m"
#define B_bBLUE                 "\033[104m"
#define B_bPURPLE               "\033[105m"
#define B_bCYAN                 "\033[106m"
#define B_bWHITE                "\033[107m"


#define E_cursorON              "\033[?25h"
#define E_cursorOFF             "\033[?25l"
#endif // _WIN32

extern bool runningOne;
extern bool runningTwo;
extern unsigned char menuState;
extern bool involved;
extern TheNarrator theNarrator;


#endif //PACKERS_H
