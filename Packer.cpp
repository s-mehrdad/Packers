﻿// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,14.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Surround.h"


#define DELAY_ONE 202
#define DELAY_TWO 302
#define DELAY_THREE 502
#define DELAY_FOUR 602


//std::mutex m;
//std::condition_variable cv;
struct queueFeed QF, blinkA, blinkB, packed, ready, NuLL;

//bool sorted { false };
//bool needFeed { true };
//bool readyFlag { false };
//struct queueFeed QF, NuLL;
//std::list<queueFeed> bufferAllOne;
//std::list<queueFeed> bufferAllTwo;
//std::list<queueFeed> bufferTemp;
//std::list<queueFeed>* bufferPtr { &bufferAllTwo };


Packer::Packer (unsigned char quickReSeed) {
  // random first placement
  id = quickReSeed;
  address = this;
  count++;

  // different packer types can be added
  blinkA.set2 (DELAY_ONE, u8" ", F_bWHITE);
  moves[0] = blinkA;
  blinkB.set2 (DELAY_TWO, u8"☻", F_bWHITE);
  moves[1] = blinkB;
  packed.set2 (DELAY_THREE, u8"▪", F_bWHITE);
  moves[2] = packed;
  ready.set2 (DELAY_FOUR, u8"☻", F_bWHITE);
  moves[3] = ready;

  int y { 0 };
  int x { 0 };
  srand ((unsigned int)time (NULL) + quickReSeed);
  do {
    y = rand () % (19 - 3) + 3;
    x = rand () % (89 - 3) + 3;
  } while (y % 2 == 0 || x % 2 == 0);
  gotoXY (x, y); ColourCout (u8"☻", F_bWHITE);
  position.X = x;
  position.Y = y;

  // random direction
  int d { 0 };
  //srand ((unsigned int)time (NULL) + quickReSeed);
  d = (rand () % (1111 - 20) + 20);
  if (d % 2 == 0) {
    RchanceL = true;
  }
  else {
    RchanceL = false;
  }

  // random state
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


void Packer::moveCout () {
  //added: making packers independent
  //add: mode and age and other things so they seems more smart
  //do {
  //  if (moves.size () < 4) {
  //    if (RchanceL == true) {
  //      if (position.X != 87) {
  //        blinkA.set (DELAY_ONE, u8" ", F_bWHITE, position);
  //        moves.insert (moves.begin (), blinkA);
  //        position.X += 2;
  //        blinkB.set (DELAY_TWO, u8"☻", F_bWHITE, position);
  //        moves.insert (moves.begin (), blinkB);
  //        //Area::yellow (position);
  //        //Area::green (position);
  //        packed.set (DELAY_THREE, u8"▪", F_bWHITE, position);
  //        moves.insert (moves.begin (), packed);
  //        ready.set (DELAY_FOUR, u8"☻", F_bWHITE, position);
  //        moves.insert (moves.begin (), ready);
  //        //Area::green (position);
  //      }
  //      else
  //        RchanceL = false;
  //    }
  //    else
  //      if (position.X != 3) {
  //        blinkA.set (DELAY_ONE, u8" ", F_bWHITE, position);
  //        moves.insert (moves.begin (), blinkA);
  //        position.X -= 2;
  //        blinkB.set (DELAY_TWO, u8"☻", F_bWHITE, position);
  //        moves.insert (moves.begin (), blinkB);
  //        //Area::yellow (position);
  //        //Area::green (position);
  //        packed.set (DELAY_THREE, u8"▪", F_bWHITE, position);
  //        moves.insert (moves.begin (), packed);
  //        ready.set (DELAY_FOUR, u8"☻", F_bWHITE, position);
  //        moves.insert (moves.begin (), ready);
  //        //Area::green (position);
  //      }
  //      else
  //        RchanceL = true;

  //  }
  //  else
  //    //bufferAllOne.insert (bufferAllOne.end (), this->moves.begin (), this->moves.end ());

  //  readyFlag = false;

  //  //wait for the awakening signal
  //  {
  //    std::unique_lock<std::mutex> lk (m);
  //    cv.wait (lk, [] { return readyFlag; });
  //  }

  //} while (true);
};
void Packer::movementCout (void) {
  //size_t size { 0 };

  //bufferAllOne.insert (bufferAllOne.begin (), NuLL);
  //size = bufferAllOne.size ();

  //do {
  //  readyFlag = false;
  //  //for (int i = 0; i < size; i++) {
  //  //  if (bufferPtr->size () >= 32) {
  //  //    for (int j = 0; j < 31; j++) {
  //  //      bufferTemp.insert (bufferTemp.begin (), bufferPtr->back ());
  //  //      bufferPtr->pop_back ();
  //  //    }
  //  //    bufferTemp.sort ();
  //  //    bufferAllTwo.insert (bufferAllTwo.end (), bufferTemp.begin (), bufferTemp.end ());
  //  //    bufferTemp.erase (bufferTemp.begin (), bufferTemp.end ());
  //  //  }
  //  //}
  //  //bufferPtr = &bufferAllTwo;
  //  //bufferAllOne = bufferAllTwo;

  //  bufferAllOne.sort ();
  //  bufferAllTwo = bufferAllOne;
  //  bufferAllOne.erase (bufferAllOne.begin (), bufferAllOne.end ());

  //  // awakening signal to constant running thread
  //  //{
  //  //  std::lock_guard<std::mutex> lk (m);
  //  //  readyFlag = true;
  //  //  cv.notify_all ();
  //  //}

  //  for (int i = 0; i < size - 1; i++) {
  //    GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  //    SetConsoleCursorPosition (consoleOutput, bufferPtr->front ().position);
  //    SetConsoleTextAttribute (consoleOutput, bufferPtr->front ().colour);
  //    std::cout << bufferPtr->front ().str;
  //    if (((i + 1) % 4) == 0)
  //      std::this_thread::sleep_for (std::chrono::milliseconds (bufferPtr->front ().delay));
  //    bufferPtr->pop_front ();
  //  }

  //  //  // wait for the awakening signal
  //  //  //{
  //  //  //  std::unique_lock<std::mutex> lk (m);
  //  //  //  cv.wait (lk, [] { return sorted; });
  //  //  //}
  //  //  //needFeed = false;
  //  //  size = bufferPtr->size ();
  //  //  for (int i = 0; i < size; i++) {
  //  //    if (bufferPtr->size () >= 32) {
  //  //      for (int j = 0; j < 31; j++) {
  //  //        bufferTemp.insert (bufferTemp.begin (), bufferPtr->back ());
  //  //        bufferPtr->pop_back ();
  //  //      }
  //  //      bufferTemp.sort ();
  //  //      bufferAllTwo.insert (bufferAllTwo.end (), bufferTemp.begin (), bufferTemp.end ());
  //  //      bufferTemp.erase (bufferTemp.begin (), bufferTemp.end ());
  //  //    }
  //  //  }
  //  //  bufferPtr = &bufferAllTwo;
  //  //  bufferAllOne = bufferAllTwo;
  //  //  while (bufferPtr->size () > 1) {
  //  //    for (int i = 0; i < 31; i++) {
  //  //      GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  //  //      SetConsoleCursorPosition (consoleOutput, bufferPtr->front ().position);
  //  //      SetConsoleTextAttribute (consoleOutput, bufferPtr->front ().colour);
  //  //      std::cout << bufferPtr->front ().str;
  //  //      if (((i + 1) % 8) == 0)
  //  //        std::this_thread::sleep_for (std::chrono::milliseconds (bufferPtr->front ().delay));
  //  //      bufferPtr->pop_front ();
  //  //    }
  //  //  }

  //    //bufferPtr = &bufferAllOne;
  //    //bufferAllTwo = bufferAllOne;
  //    //while (bufferPtr->size () > 1) {
  //    //  for (int i = 0; i < 31; i++) {
  //    //    GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  //    //    SetConsoleCursorPosition (consoleOutput, bufferPtr->back ().position);
  //    //    SetConsoleTextAttribute (consoleOutput, bufferPtr->back ().colour);
  //    //    std::cout << bufferPtr->back ().str;
  //    //    if (((i + 1) % 8) == 0)
  //    //      std::this_thread::sleep_for (std::chrono::milliseconds (bufferPtr->back ().delay));
  //    //    bufferPtr->pop_back ();
  //    //  }
  //    //}

  //  //  bufferPtr->pop_front ();
  //  //  sorted = false;
  //  //  needFeed = true;
  //} while (true);
};
void Packer::addToQueues (unsigned short mode, std::string strCharacter, WORD Colour, COORD position) {
  //QF.delay = mode;
  //QF.str = strCharacter;
  //QF.colour = Colour;
  //QF.position = position;

  //bufferAllOne.insert (bufferAllOne.begin (), QF);

  //if (bufferAllOne.size () >= 31 && ((bufferAllOne.size () + 1) % 8) == 0 && needFeed == true) {

  //  bufferAllTwo = bufferAllOne;
  //  bufferAllOne.erase (bufferAllOne.begin (), bufferAllOne.end ());

  //  QF.delay = 2000;
  //  QF.str = "NULL";
  //  QF.colour = 0x00;
  //  QF.position.X = 0;
  //  QF.position.X = 0;
  //  bufferAllTwo.insert (bufferAllTwo.end (), QF);

  //  bufferAllTwo.sort ();

  //  // awakening signal to constant running thread
  //  {
  //    std::lock_guard<std::mutex> lk (m);
  //    sorted = true;
  //    cv.notify_one ();
  //  }
  //}
};
void Packer::hMovement (std::list<Packer> input) {
  //for (int i = 0; i < 320; i++) {
  //  if (input.front ().RchanceL == true) {
  //    if (input.front ().position.X != 87) {
  //      //Packer::addToQueues (DELAY_ONE, u8" ", F_bWHITE, input.front ().position);
  //      //Packer::addToQueues (DELAY_TWO, u8"☻", F_bWHITE, input.front ().position);
  //      //Packer::addToQueues (DELAY_THREE, u8"▪", F_bWHITE, input.front ().position);
  //      //Packer::addToQueues (DELAY_FOUR, u8"☻", F_bWHITE, input.front ().position);
  //      blinkA.set (DELAY_ONE, u8" ", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), blinkA);
  //      input.front ().position.X += 2;
  //      blinkB.set (DELAY_TWO, u8"☻", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), blinkB);
  //      //Area::yellow (position);
  //      //Area::green (position);
  //      packed.set (DELAY_THREE, u8"▪", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), packed);
  //      ready.set (DELAY_FOUR, u8"☻", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), ready);
  //      input.emplace_back (input.front ());
  //      input.pop_front ();
  //      //Area::green (position);
  //    }
  //    else
  //      input.front ().RchanceL = false;
  //  }
  //  else
  //    if (input.front ().position.X != 3) {
  //      blinkA.set (DELAY_ONE, u8" ", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), blinkA);
  //      input.front ().position.X -= 2;
  //      blinkB.set (DELAY_TWO, u8"☻", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), blinkB);
  //      //Area::yellow (position);
  //      //Area::green (position);
  //      packed.set (DELAY_THREE, u8"▪", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), packed);
  //      ready.set (DELAY_FOUR, u8"☻", F_bWHITE, input.front ().position);
  //      bufferAllOne.insert (bufferAllOne.begin (), ready);
  //      input.emplace_back (input.front ());
  //      input.pop_front ();
  //      //Area::green (position);
  //    }
  //    else
  //      input.front ().RchanceL = true;
  //}
};