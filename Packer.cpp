// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,01.12.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Surround.h"


// different packer types can be added
struct eventFeed blinkA (DELAY_ONE, u8" ", F_bWHITE);
struct eventFeed blinkB (DELAY_TWO, u8"☻", F_bWHITE);
struct eventFeed packed (DELAY_THREE, u8"▪", F_bWHITE);
struct eventFeed ready (DELAY_FOUR, u8"☻", F_bWHITE);


Packer::Packer (unsigned char quickReSeed) {
  id = quickReSeed;
  address = this;
  count++;

  //rand function seed provider + quick reseeding
  srand ((unsigned int)time (NULL) + quickReSeed);

  //add: change made by packers in their surround
  moves[0] = blinkA;
  moves[1] = blinkB;
  moves[2] = packed;
  moves[3] = ready;

  // random beginning position
  do {
    position.X = rand () % (89 - 3) + 3;
    position.Y = rand () % (19 - 3) + 3;
  } while (position.X % 2 == 0 || position.Y % 2 == 0);
  colourInserter (u8"☻", F_bWHITE, position);

  // random direction
  int d { 0 };
  d = (rand () % (1111 - 20) + 20);
  if (d % 2 == 0) {
    RchanceL = true;
  }
  else {
    RchanceL = false;
  }

  // random state
  //can be omitted (going to far for a console game?! :) )
  int s { 0 };
  s = (rand () % 3 + 1);
  if (s == 1)
    state = 1000; // normal
  if (s == 2)
    state = 2000; // not in the mood
  if (s == 3)
    state = 3000; // tired
};


//add:
//Packer (//userchoice) :Sign () {};


unsigned char Packer::count { 0 };


void Packer::colourInserter (std::string str, WORD colour, COORD pos) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleCursorPosition (consoleOutput, pos);
  SetConsoleTextAttribute (consoleOutput, colour);
  std::cout << str;
};