// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.04.2019</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#ifndef PACKERS_H
#define PACKERS_H

#ifndef UNICODE
#define UNICODE
#endif


#if WIN32
#define WIN32_LEAN_AND_MEAN // rarely-used stuff exclusion
#endif // WIN32


#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
//#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>

#include "Tale.h"


#define FONT_SIZEx              18
#define FONT_SIZEy              22
#define FONT_NAME               L"NSimSun"
//#define FONT_NAME               L"Consolas"
//#define FONT_NAME               L"Lucida Console"
//#define FONT_NAME               L"Courier New"
#define SCREEN_L                2
#define SCREEN_T                2
#define SCREEN_H                41 // use odd values
//? danger:
//! if you choose the next value less than 100, you are on your own, since the packers don't have enough to chew! :)
#define SCREEN_W                111 // additionally use odd values
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


extern bool runningOne;
extern bool runningTwo;
extern unsigned char menuState;
extern bool involved;
extern Narrator theNarrator;


#endif //PACKERS_H
