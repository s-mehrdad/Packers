﻿

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"


struct queueFeed QF;
std::list<queueFeed> bufferAllOne;
std::list<queueFeed> bufferAllTwo;
std::list<queueFeed> bufferSelOne;
std::list<queueFeed> bufferSelTwo;
std::list<queueFeed> bufferSelThree;
std::list<queueFeed> bufferSelFour;


Packer::Packer (unsigned short quickReSeed) {
  // random first placement
  int y { 0 };
  int x { 0 };
  srand ((unsigned int)time (NULL) + quickReSeed);
  do {
    y = rand () % (19 - 3) + 3;
    x = rand () % (89 - 3) + 3;
  } while (y % 2 == 0 || x % 2 == 0);
  gotoXY (x, y); ColourCout (u8"☻", 0x0f);
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


void Packer::addToQueues (std::string strCharacter, WORD Colour, COORD position, unsigned char mode) {
  QF.str = strCharacter;
  QF.colour = Colour;
  QF.position = position;
  QF.mode = mode;

  //102 204 354 454

  if (bufferAllOne.size () < 500)
    bufferAllOne.insert (bufferAllOne.begin (), QF);
  else {
    //add: sort iteration for second list (probably all sorting in another function)
    bufferAllTwo.insert (bufferAllTwo.begin (), QF);

    QF.str = "NULL";
    QF.colour = 0x00;
    QF.position.X = 0;
    QF.position.X = 0;
    QF.mode = 0;
    bufferAllOne.insert (bufferAllOne.begin (), QF);
    while (bufferAllOne.size () > 1) {
      if (bufferAllOne.front ().mode = 102) {
        bufferSelOne.insert (bufferSelOne.begin (), bufferAllOne.front ());
        bufferAllOne.pop_front ();
      }
      else
        if (bufferAllOne.front ().mode = 204) {
          bufferSelTwo.insert (bufferAllTwo.begin (), bufferAllOne.front ());
          bufferAllOne.pop_front ();
        }
        else
          if (bufferAllOne.front ().mode = 354) {
            bufferSelThree.insert (bufferSelThree.begin (), bufferAllOne.front ());
            bufferAllOne.pop_front ();
          }
          else
            if (bufferAllOne.front ().mode = 454) {
              bufferSelFour.insert (bufferSelFour.begin (), bufferAllOne.front ());
              bufferAllOne.pop_front ();
            }
            else
              bufferAllOne.emplace_back ();
    }

    Packer::PackerP (bufferSelOne, 102);
    bufferSelOne.erase (bufferSelOne.begin (), bufferSelOne.end ());

    Packer::PackerP (bufferSelTwo, 204);
    bufferSelTwo.erase (bufferSelTwo.begin (), bufferSelTwo.end ());

    Packer::PackerP (bufferSelThree, 354);
    bufferSelThree.erase (bufferSelThree.begin (), bufferSelThree.end ());

    Packer::PackerP (bufferSelFour, 454);
    bufferSelFour.erase (bufferSelFour.begin (), bufferSelFour.end ());
  }
};

void Packer::PackerP (std::list<queueFeed> input, unsigned short delay) {
  QF.str = "NULL";
  QF.colour = 0x00;
  QF.position.X = 0;
  QF.position.X = 0;
  input.insert (input.end (), QF);
  while (input.size () > 1) {
    GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
    SetConsoleCursorPosition (consoleOutput, input.front ().position);
    SetConsoleTextAttribute (consoleOutput, input.front ().colour);
    std::cout << input.front ().str;
    input.pop_front ();
    std::this_thread::sleep_for (std::chrono::milliseconds (delay));
  }
};


//void Packer::hQuickMovement (std::list<Packer> input, unsigned char mode) {
//  if (input.size () != 0) {
//    short modeToMilliS { 1 };
//    switch (mode) {
//    case 1:
//      modeToMilliS = 500;
//      break;
//    case 2:
//      modeToMilliS = 400;
//      break;
//    case 3:
//      modeToMilliS = 200;
//      break;
//    case 4:
//      modeToMilliS = 1000;
//      break;
//    }
//    for (int i = 0; i < 100; i++) {
//      if (input.front ().RchanceL == true) {
//        if (input.front ().position.X != 87) {
//          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
//          input.front ().position.X += 2;
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
//          //Area::yellow (position);
//          //Area::green (position);
//          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
//          input.emplace_back (input.front ());
//          input.pop_front ();
//          //Area::green (position);
//        }
//        else
//          input.front ().RchanceL = false;
//      }
//      else
//        if (input.front ().position.X != 3) {
//          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
//          input.front ().position.X -= 2;
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
//          //Area::yellow (position);
//          //Area::green (position);
//          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
//          input.emplace_back (input.front ());
//          input.pop_front ();
//          //Area::green (position);
//        }
//        else
//          input.front ().RchanceL = true;
//      std::this_thread::sleep_for (std::chrono::milliseconds (200));
//    }
//  }
//};


void Packer::hNormalMovement (std::list<Packer> input, unsigned char mode) {
  //  short modeToMilliS { 1 };
  //  switch (mode) {
  //  case 1:
  //    modeToMilliS = 500;
  //    break;
  //  case 2:
  //    modeToMilliS = 400;
  //    break;
  //  case 3:
  //    modeToMilliS = 200;
  //    break;
  //  case 4:
  //    modeToMilliS = 1000;
  //    break;
  if (input.size () != 0) {
    for (int i = 0; i < 200; i++) {
      if (input.front ().RchanceL == true) {
        if (input.front ().position.X != 87) {
          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
          input.front ().position.X += 2;
          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
          //Area::yellow (position);
          //Area::green (position);
          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
          input.emplace_back (input.front ());
          input.pop_front ();
          //Area::green (position);
        }
        else
          input.front ().RchanceL = false;
      }
      else
        if (input.front ().position.X != 3) {
          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
          input.front ().position.X -= 2;
          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
          //Area::yellow (position);
          //Area::green (position);
          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
          input.emplace_back (input.front ());
          input.pop_front ();
          //Area::green (position);
        }
        else
          input.front ().RchanceL = true;
      std::this_thread::sleep_for (std::chrono::milliseconds (200));
    }
  }
};


//void Packer::hSlowMovement (std::list<Packer> input, unsigned char mode) {
//  if (input.size () != 0) {
//    short modeToMilliS { 1 };
//    switch (mode) {
//    case 1:
//      modeToMilliS = 500;
//      break;
//    case 2:
//      modeToMilliS = 400;
//      break;
//    case 3:
//      modeToMilliS = 200;
//      break;
//    case 4:
//      modeToMilliS = 1000;
//      break;
//    }
//    for (int i = 0; i < 100; i++) {
//      if (input.front ().RchanceL == true) {
//        if (input.front ().position.X != 87) {
//          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
//          input.front ().position.X += 2;
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
//          //Area::yellow (position);
//          //Area::green (position);
//          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
//          input.emplace_back (input.front ());
//          input.pop_front ();
//          //Area::green (position);
//        }
//        else
//          input.front ().RchanceL = false;
//      }
//      else
//        if (input.front ().position.X != 3) {
//          Packer::addToQueues (u8" ", 0x0f, input.front ().position, 102);
//          input.front ().position.X -= 2;
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 204);
//          //Area::yellow (position);
//          //Area::green (position);
//          Packer::addToQueues (u8"▪", 0x0f, input.front ().position, 354);
//          Packer::addToQueues (u8"☻", 0x0f, input.front ().position, 454);
//          input.emplace_back (input.front ());
//          input.pop_front ();
//          //Area::green (position);
//        }
//        else
//          input.front ().RchanceL = true;
//      std::this_thread::sleep_for (std::chrono::milliseconds (200));
//    }
//  }
//};
