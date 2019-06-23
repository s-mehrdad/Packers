// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.04.2019</created>
/// <changed>ʆϒʅ,23.06.2019</changed>
// ********************************************************************************

// Packers.h : Include file for standard system include files,
// or project specific include files.

#pragma once


#ifndef PACKERS_H
#define PACKERS_H


#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>


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
#define DELAY_ONE               52
#define DELAY_TWO               102
#define DELAY_THREE             202
#define DELAY_FOUR              302


extern bool runningOne;
extern bool runningTwo;
extern unsigned char menuState;
extern bool MenusFlag;


#endif //PACKERS_H
