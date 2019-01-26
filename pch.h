// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,26.01.2019</changed>
// ********************************************************************************

#pragma once


#ifndef PCH_H
#define PCH_H


#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>


#define FONT_SIZEa              10
#define FONT_SIZEb              20
#define FONT_NAME               L"Consolas"
#define SCREEN_L                15
#define SCREEN_T                15
#define SCREEN_H                32 // use odd values
#define SCREEN_W                120 // the same
#define BACKGROUND_COLOUR       RGB (50,50,50)


// used mode: chew-forward going!
//? danger: too much quickness gives them the chance chewing the future of this generation too!
#define DELAY_ONE               52
#define DELAY_TWO               102
#define DELAY_THREE             202
#define DELAY_FOUR              302


//#define F_BLACK                 0x00
//#define F_BLUE                  0x01
//#define F_GREEN                 0x02
//#define F_CYAN                  0x03
//#define F_RED                   0x04
//#define F_PURPLE                0x05
//#define F_YELLOW                0x06
//#define F_WHITE                 0x07
//#define F_bBLACK                0x08
//#define F_bBLUE                 0X09
//#define F_bGREEN                0x0a
//#define F_bCYAN                 0x0b
//#define F_bRED                  0x0c
//#define F_bPURPLE               0x0d
//#define F_bYELLOW               0x0e
//#define F_bWHITE                0x0f
//
//#define B_BLACK                 0x00
//#define B_bBLUE                 0X30
//  0: Black // 1: Blue  //  2 : Green  //  3 : Cyan  //  4 : Red  //  5 : Purple  //  6 : Yellow  //  7 : White  //  8 : bright black  //  9 : Bright blue  //  10 : Bright green  //  11 : Bright cyan  //  12 : Bright red  //  13 : Bright purple  //  14 : Bright yellow  //  15 : Bright white


extern HANDLE consoleOutput;
extern CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;

extern bool running;
extern unsigned char menusSelection;
extern bool MenusFlag;


struct eventFeed
{
    unsigned short delay;
    std::string str;
    WORD colour;
    COORD position;
    eventFeed ()
    {
        delay = 2000;
        str = "NULL";
        colour = 0x00;
        position = { 0,0 };
    }
    eventFeed ( unsigned short mode, std::string Str, WORD Colour, COORD Position ) : delay ( mode ), str ( Str ), colour ( Colour ), position ( Position ) {}
    eventFeed ( unsigned short mode, std::string Str, WORD Colour ) :delay ( mode ), str ( Str ), colour ( Colour ) {}

    bool operator< ( const eventFeed &a ) const
    {
        return ( delay < a.delay );
    }
};


#endif //PCH_H