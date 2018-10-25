

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"

#define DELAY_ONE 202
#define DELAY_TWO 302
#define DELAY_THREE 502
#define DELAY_FOUR 602

std::mutex m;
std::condition_variable cv;
bool ready1 { false };
bool ready2 { true };

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


void Packer::movementColourCout (std::list<queueFeed> input, unsigned short delay) {
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


void Packer::sortToQueues (void) {
  //added:
  //-- already suspended constant running thread

  //add:
  // 1. for 8 packer in a 200 i-loop and currently 4 move each: 6400 movement
  // 2. the i of the i-loop is also needed
  // small to big delay consideration
  //while (size) {
  //  for (size_t i = 1; i <= 8; i++) {

  //    if (i == 8 && size > 1) {
  //      i = 1;
  //    }
  //  }
  //}


  do {
    // next expression: so it don't go through without a good reason:
    if (ready1 == true) {
      ready2 = false;

      while (bufferAllTwo.size () > 1) {
        if (bufferAllTwo.front ().delay == DELAY_ONE) {
          bufferSelOne.insert (bufferSelOne.begin (), bufferAllTwo.front ());
          bufferAllTwo.pop_front ();
        }
        else
          if (bufferAllTwo.front ().delay == DELAY_TWO) {
            bufferSelTwo.insert (bufferSelTwo.begin (), bufferAllTwo.front ());
            bufferAllTwo.pop_front ();
          }
          else
            if (bufferAllTwo.front ().delay == DELAY_THREE) {
              bufferSelThree.insert (bufferSelThree.begin (), bufferAllTwo.front ());
              bufferAllTwo.pop_front ();
            }
            else
              if (bufferAllTwo.front ().delay == DELAY_FOUR) {
                bufferSelFour.insert (bufferSelFour.begin (), bufferAllTwo.front ());
                bufferAllTwo.pop_front ();
              }
              else
                bufferAllTwo.emplace_back ();
      }

      Packer::movementColourCout (bufferSelOne, DELAY_ONE);
      bufferSelOne.erase (bufferSelOne.begin (), bufferSelOne.end ());

      Packer::movementColourCout (bufferSelTwo, DELAY_TWO);
      bufferSelTwo.erase (bufferSelTwo.begin (), bufferSelTwo.end ());

      Packer::movementColourCout (bufferSelThree, DELAY_THREE);
      bufferSelThree.erase (bufferSelThree.begin (), bufferSelThree.end ());

      Packer::movementColourCout (bufferSelFour, DELAY_FOUR);
      bufferSelFour.erase (bufferSelFour.begin (), bufferSelFour.end ());

      ready2 = true;
    }

    // wait for the awakening signal
    {
      std::unique_lock<std::mutex> lk (m);
      cv.wait (lk, [] { return ready1; });
    }

    //add: condition (user involvement choice)
  } while (true);

  // send back data (maybe for good wishes in the end of the program! :) )
  //{
  //  std::lock_guard<std::mutex> lk (m);
  //  //processed = true;
  //}
  //cv.notify_one ();

};


void Packer::addToQueues (std::string strCharacter, WORD Colour, COORD position, unsigned short mode) {
  QF.str = strCharacter;
  QF.colour = Colour;
  QF.position = position;
  QF.delay = mode;

  if (bufferAllOne.size () < 500)
    bufferAllOne.insert (bufferAllOne.begin (), QF);
  else {

    // next expression: for the one lost movement in case that the condition is true:
    bufferAllOne.insert (bufferAllOne.begin (), QF);
    bufferAllTwo = bufferAllOne;
    if (bufferAllTwo.size () == 501 && ready2 == true) {
      QF.str = "NULL";
      QF.colour = 0x00;
      QF.position.X = 0;
      QF.position.X = 0;
      QF.delay = 0;
      bufferAllTwo.insert (bufferAllTwo.end (), QF);
    }

    // awakening signal to constant running thread
    {
      std::lock_guard<std::mutex> lk (m);
      ready1 = true;
    }
    cv.notify_one ();

    std::this_thread::sleep_for (std::chrono::milliseconds (50));
    bufferAllOne.erase (bufferAllOne.begin (), bufferAllOne.end ());
    ready1 = false;
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