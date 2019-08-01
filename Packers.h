// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.04.2019</created>
/// <changed>ʆϒʅ,24.07.2019</changed>
// ********************************************************************************

#ifndef PACKERS_H
#define PACKERS_H

#if WIN32
#define WIN32_LEAN_AND_MEAN // rarely-used stuff exclusion
#endif // WIN32


#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>

#include "Tale.h"


#define FONT_SIZEa              15
#define FONT_SIZEb              15
//#define FONT_NAME               L"Consolas"
#define FONT_NAME               L"Lucida Console"
#define SCREEN_L                5
#define SCREEN_T                5
#define SCREEN_H                45 // use odd values
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


extern bool runningOne;
extern bool runningTwo;
extern unsigned char menuState;
extern bool involved;
extern Narrator theNarrator;


#endif //PACKERS_H
