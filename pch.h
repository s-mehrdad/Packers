// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,03.02.2019</changed>
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
//? danger:
//! if you choose the next value less than 100, you are on your own, since the packers don't have enough to chew! :)
#define SCREEN_W                120 // the same
#define BACKGROUND_COLOUR       RGB (50,50,50)


// used mode: chew-forward going!
//? danger: too much quickness gives them the chance chewing the future of this generation too!
#define DELAY_ONE               52
#define DELAY_TWO               102
#define DELAY_THREE             202
#define DELAY_FOUR              302


extern HANDLE consoleOutput;
extern CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;

extern bool runningOne;
extern bool runningTwo;
extern unsigned char menusSelection;
extern bool MenusFlag;


#endif //PCH_H