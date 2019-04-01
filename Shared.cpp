﻿// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#include "pch.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"
#include "Tale.h"


struct Loading::loadingBar
{
  std::string characters [9] { u8"L", u8"O", u8"A", u8"D", u8"I", u8"N", u8"G", u8"#", u8" " };
  //std::string copywrite { u8"  ©: ʆϒʅ" }; // for fonts with more characters
  std::string copywrite { u8"  ©: }Y{" };
  WORD colourOne { B_bBLUE | F_bWHITE };
  WORD colourTwo { B_BLACK | F_bGREEN };
  WORD colourThree { B_BLACK | F_bWHITE };
  COORD startPoint { SCREEN_W - 13, SCREEN_H - 2 };
  unsigned char speed { 1 };
  void inserter ()
  {
    COORD position { startPoint };
    for ( unsigned char i = 0; i < 7; i++ )
    {
      Inserter::colourInserter ( characters [i], colourOne, position );
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 * speed ) );
      position.X += 1;
    }
    for ( unsigned char i = 1; i <= 3; i++ )
    {
      Inserter::colourInserter ( characters [7], colourTwo, position );
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 150 * speed ) );
      Inserter::colourInserter ( characters [8], colourTwo, position );
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
    }
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 * speed ) );
    Inserter::colourInserter ( copywrite, colourThree, startPoint );
  }
} _loadingBar;


Loading::Loading ( unsigned char mode )
{
  // set
  _loadingBar.speed = mode;

  // cout
  _loadingBar.inserter ();
  //std::thread tOne ( inserter );
  //tOne.join ();
};


void Loading::newSetter ( void )
{
  //TODO add: new setter
  //TODO add: new couter
};


void Loading::clear ( unsigned char count )
{
  COORD temp { 0,0 };
  Inserter::colourInserter ( u8"                                                    ", F_WHITE, temp );
  for ( unsigned char i = 0; i < count; i++ )
  {
    Inserter::colourInserter ( u8"                                                    ", F_WHITE );
  }
}