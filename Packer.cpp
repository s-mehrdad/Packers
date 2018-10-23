

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"

#define DELAY_ONE 202
#define DELAY_TWO 302
#define DELAY_THREE 502
#define DELAY_FOUR 602

struct queueFeed QF;
std::list<queueFeed> bufferAllOne;
std::list<queueFeed> bufferAllTwo;
std::list<queueFeed> bufferSelOne;
std::list<queueFeed> bufferSelTwo;
std::list<queueFeed> bufferSelThree;
std::list<queueFeed> bufferSelFour;


Packer::Packer (unsigned char quickReSeed) {
  // random first placement
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


void Packer::addToQueues (std::string strCharacter, WORD Colour, COORD position, unsigned short mode) {
  QF.str = strCharacter;
  QF.colour = Colour;
  QF.position = position;
  QF.delay = mode;

  if (bufferAllOne.size () < 500)
    bufferAllOne.insert (bufferAllOne.begin (), QF);
  else {
    //add: sort iteration for second list (probably all sorting in another function)
    bufferAllTwo.insert (bufferAllTwo.begin (), QF);

    QF.str = "NULL";
    QF.colour = 0x00;
    QF.position.X = 0;
    QF.position.X = 0;
    QF.delay = 0;
    bufferAllOne.insert (bufferAllOne.begin (), QF);
    while (bufferAllOne.size () > 1) {
      if (bufferAllOne.front ().delay = DELAY_ONE) {
        bufferSelOne.insert (bufferSelOne.begin (), bufferAllOne.front ());
        bufferAllOne.pop_front ();
      }
      else
        if (bufferAllOne.front ().delay = DELAY_TWO) {
          bufferSelTwo.insert (bufferAllTwo.begin (), bufferAllOne.front ());
          bufferAllOne.pop_front ();
        }
        else
          if (bufferAllOne.front ().delay = DELAY_THREE) {
            bufferSelThree.insert (bufferSelThree.begin (), bufferAllOne.front ());
            bufferAllOne.pop_front ();
          }
          else
            if (bufferAllOne.front ().delay = DELAY_FOUR) {
              bufferSelFour.insert (bufferSelFour.begin (), bufferAllOne.front ());
              bufferAllOne.pop_front ();
            }
            else
              bufferAllOne.emplace_back ();
    }

    Packer::PackerP (bufferSelOne, DELAY_ONE);
    bufferSelOne.erase (bufferSelOne.begin (), bufferSelOne.end ());

    Packer::PackerP (bufferSelTwo, DELAY_TWO);
    bufferSelTwo.erase (bufferSelTwo.begin (), bufferSelTwo.end ());

    Packer::PackerP (bufferSelThree, 452);
    bufferSelThree.erase (bufferSelThree.begin (), bufferSelThree.end ());

    Packer::PackerP (bufferSelFour, DELAY_THREE);
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
    unsigned char D { 0 };
    srand ((unsigned int)time (NULL));
    D = (rand () % (5 - 1) + 1);
    for (int i = 0; i < D; i++) {
      if (input.size () != 0) {
        GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
        SetConsoleCursorPosition (consoleOutput, input.front ().position);
        SetConsoleTextAttribute (consoleOutput, input.front ().colour);
        std::cout << input.front ().str;
        input.pop_front ();
      }
    }
    std::this_thread::sleep_for (std::chrono::milliseconds (delay));
  }
};


void Packer::hMovement (std::list<Packer> input) {
  for (int i = 0; i < 200; i++) {
    if (input.front ().RchanceL == true) {
      if (input.front ().position.X != 87) {
        Packer::addToQueues (u8" ", F_bWHITE, input.front ().position, DELAY_ONE);
        input.front ().position.X += 2;
        Packer::addToQueues (u8"☻", F_bWHITE, input.front ().position, DELAY_TWO);
        //Area::yellow (position);
        //Area::green (position);
        Packer::addToQueues (u8"▪", F_bWHITE, input.front ().position, DELAY_THREE);
        Packer::addToQueues (u8"☻", F_bWHITE, input.front ().position, DELAY_FOUR);
        input.emplace_back (input.front ());
        input.pop_front ();
        //Area::green (position);
      }
      else
        input.front ().RchanceL = false;
    }
    else
      if (input.front ().position.X != 3) {
        Packer::addToQueues (u8" ", F_bWHITE, input.front ().position, DELAY_ONE);
        input.front ().position.X -= 2;
        Packer::addToQueues (u8"☻", F_bWHITE, input.front ().position, DELAY_TWO);
        //Area::yellow (position);
        //Area::green (position);
        Packer::addToQueues (u8"▪", F_bWHITE, input.front ().position, DELAY_THREE);
        Packer::addToQueues (u8"☻", F_bWHITE, input.front ().position, DELAY_FOUR);
        input.emplace_back (input.front ());
        input.pop_front ();
        //Area::green (position);
      }
      else
        input.front ().RchanceL = true;
    std::this_thread::sleep_for (std::chrono::milliseconds (200));
  }
};