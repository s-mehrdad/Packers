// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.04.2019</created>
/// <changed>ʆϒʅ,12.06.2022</changed>
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
#include <WinNls.h>
#include <winnt.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>

#include "Tale.h"


#define FONT_SIZEx              10
#define FONT_SIZEy              18
#define FONT_NAME               L"Consolas"
//#define FONT_NAME               L"Lucida Console"
//#define FONT_NAME               L"Courier New"
#define SCREEN_L                5
#define SCREEN_T                5
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
#define DELAY_TWO               201
#define DELAY_THREE             202
#define DELAY_FOUR              102


// colour system
#define F_BLACK                 0x00
#define F_BLUE                  0x01
#define F_GREEN                 0x02
#define F_CYAN                  0x03
#define F_RED                   0x04
#define F_PURPLE                0x05
#define F_YELLOW                0x06
#define F_WHITE                 0x07
#define F_bBLACK                0x08
#define F_bBLUE                 0X09
#define F_bGREEN                0x0A
#define F_bCYAN                 0x0B
#define F_bRED                  0x0C
#define F_bPURPLE               0x0D
#define F_bYELLOW               0x0E
#define F_bWHITE                0x0F

#define B_BLACK                 0x00
#define B_BLUE                  0x10
#define B_GREEN                 0x20
#define B_CYAN                  0x30
#define B_RED                   0x40
#define B_PURPLE                0x50
#define B_YELLOW                0x60
#define B_WHITE                 0x70
#define B_bBLACK                0x80
#define B_bBLUE                 0X90
#define B_bGREEN                0xA0
#define B_bCYAN                 0xB0
#define B_bRED                  0xC0
#define B_bPURPLE               0xD0
#define B_bYELLOW               0xE0
#define B_bWHITE                0xF0


//extern HWND viewConsoleWindowPub;
//extern HANDLE viewConsoleOutputPub;

extern bool runningOne;
extern bool runningTwo;
extern unsigned char menuState;
extern bool involved;
extern Narrator theNarrator;


#endif //PACKERS_H
