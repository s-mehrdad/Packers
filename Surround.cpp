

#include "pch.h"
#include "Surround.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"


struct Surround::titelBar {
  std::string titelSentence { u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)" };
  DWORD colour { F_bBLUE };
  COORD startPoint { 7,0 };
} _titleBar;


struct Surround::menus {

  struct agesChoices {
    std::string title { u8"Packing speed:" };
    std::string options[5] {
      u8"  Stone age." ,
      u8"  Middle age..." ,
      u8"  Advanced age........." ,
      u8"  Hollow age.      . .            ." ,
      u8"  Dirty age (packers of packers contest!)" };
    DWORD colour { F_bWHITE };
    COORD startPoint { 3,20 };
    unsigned char selected { 0 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
      COORD startPoint { 2,21 };
    } _selectionSign;
  } _ageChoices;

  struct characterChoices {
    std::string title { u8"Character Choices:" };
    std::string options[2] {
      u8"  ☺  " ,
      u8"    ☻" };
    DWORD colour { F_bWHITE };
    COORD startPoint { 35,20 };
    unsigned char selected { 0 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
      COORD startPoint { 40,21 };
    } _selectionSign;
  } _characterChoices;

  struct dangerAreaChoices {
    std::string title { u8"  Danger area:" };
    std::string options[3] {
      u8"  Involve me!",
      u8"  Let me furnish! :)",
      u8"  Let's hit the road!" };
    DWORD colour { F_bWHITE };
    COORD startPoint { 65,21 };
    unsigned char selected { 0 };
    struct selectionSign {
      std::string sign { u8"->" };
      DWORD colour { F_bRED };
      COORD startPoint { 64,22 };
    } _selectionSign;
  } _dangerAreaChoices;

}_menus;


struct Surround::guideBar {

  COORD startPoint { 6,27 };

  struct signs {
    std::string parts[3] {
      u8"♣:",
      u8"☻:",
      u8"▪:" };
    DWORD colourOne { F_bGREEN };
    DWORD colourTwo { F_bWHITE };
  } _signs;

  struct guides {
    std::string parts[3] {
      u8" healthy resources",
      u8" beloved packers",
      u8" already packed",
    };
    DWORD colour { F_bBLUE };
  } _guides;

} _GuideBar;


struct Surround::statusBar {

  std::string title { u8"status->>" };
  DWORD colour { F_bWHITE };
  COORD startPoint { 91,3 };

  struct packers {
    std::string str { u8"packers: " };
    DWORD colourOne { F_PINK };
    //add: count setter for new packers
    unsigned char count { 0 };
    DWORD colourTwo { F_bBLUE };
    COORD startPoint { 91,5 };
  } _packers;

  struct age {
    std::string str { u8"age: " };
    DWORD colourOne { F_bWHITE };
    //add: age setter + user choice for start age
    unsigned char id { 0 }; //Stone age
    DWORD colourTwo { F_bBLUE };
    COORD startPoint { 91,7 };
  } _age;

  struct resources {
    std::string str { u8"resources>" };
    DWORD colour { F_PINK };
    COORD startPoint { 91,10 };
    struct healthy {
      std::string str { u8"healthy: " };
      DWORD colourOne { F_bGREEN };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,12 };
    } _healthy;
    struct renewed {
      std::string str { u8"renewed: " };
      DWORD colourOne { F_YELLOW };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,15 };
    } _renewed;
    struct vanished {
      std::string str { u8"vanished: " };
      DWORD colourOne { F_RED };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,18 };
    } _vanished;
  } _resources;

  struct packages {
    std::string str { u8"packages> " };
    DWORD colourOne { F_bWHITE };
    COORD startPoint { 91,21 };
    struct have {
      std::string str { u8"have: " };
      DWORD colourOne { F_PINK };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD point { 91,23 };
    } _have;
    struct need {
      std::string str { u8"need: " };
      DWORD colourOne { F_PINK };
      //add: random need setter in constructor
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD point { 91,26 };
    } _need;
  } _packages;
} _statusBar;


Surround::Surround () {
  // set
  _statusBar._packers.count = Packer::count;

  // cout
  allCouter ();
};


void Surround::allCouter (void) {

  COORD position { 0,0 };

  // titleBar
  colourInserter (_titleBar.titelSentence, _titleBar.colour, _titleBar.startPoint);

  // ageChoicesMenu
  colourInserter (_menus._ageChoices.title, _menus._ageChoices.colour, _menus._ageChoices.startPoint);
  position = _menus._ageChoices.startPoint;
  for (char i = 0; i < 5; i++) {
    colourInserter (_menus._ageChoices.options[i], _menus._ageChoices.colour, position);
    position.X += 1;
  }
  colourInserter (_menus._ageChoices._selectionSign.sign, _menus._ageChoices._selectionSign.colour, _menus._ageChoices._selectionSign.startPoint);

  // characterCoicesMenu
  colourInserter (_menus._characterChoices.title, _menus._characterChoices.colour, _menus._characterChoices.startPoint);
  position = _menus._characterChoices.startPoint;
  position.X = _menus._characterChoices.startPoint.X + 1;
  colourInserter (_menus._characterChoices.options[0], _menus._characterChoices.colour, position);
  position.Y = _menus._characterChoices.startPoint.Y + 5;
  colourInserter (_menus._characterChoices.options[1], _menus._characterChoices.colour, position);
  colourInserter (_menus._characterChoices._selectionSign.sign, _menus._characterChoices._selectionSign.colour, _menus._characterChoices._selectionSign.startPoint);

  // dangerAreaChoicesMenu
  colourInserter (_menus._dangerAreaChoices.title, _menus._dangerAreaChoices.colour, _menus._dangerAreaChoices.startPoint);
  position = _menus._dangerAreaChoices.startPoint;
  for (char i = 0; i < 3; i++) {
    colourInserter (_menus._dangerAreaChoices.options[i], _menus._dangerAreaChoices.colour, position);
    position.X += 1;
  }
  colourInserter (_menus._dangerAreaChoices._selectionSign.sign, _menus._dangerAreaChoices._selectionSign.colour, _menus._dangerAreaChoices._selectionSign.startPoint);

  // guideBar
  position = _GuideBar.startPoint;
  for (char i = 0; i < 3; i++) {
    position.Y += (pow (6, i) + 30);
    if (i = 0)
      colourInserter (_GuideBar._signs.parts[i], _GuideBar._signs.colourOne, position);
    else
      colourInserter (_GuideBar._signs.parts[i], _GuideBar._signs.colourTwo, position);
    position.Y = _menus._characterChoices.startPoint.Y + 2;
    colourInserter (_GuideBar._guides.parts[i], _GuideBar._guides.colour, position);
  }

  // statusBar
  colourInserter (_statusBar.title, _statusBar.colour, _statusBar.startPoint);
  position = _statusBar._packers.startPoint;
  colourInserter (_statusBar._packers.str, _statusBar._packers.colourOne, position);
  position.Y += 9;
  colourInserter (std::to_string(_statusBar._packers.count), _statusBar._packers.colourTwo, position);
  position = _statusBar._age.startPoint;
  colourInserter (_statusBar._age.str, _statusBar._age.colourOne, position);
  position.X += 1;
  colourInserter (_statusBar._age.str, _statusBar._age.colourTwo, position);



  struct resources {
    std::string str { u8"resources>" };
    DWORD colour { F_PINK };
    COORD startPoint { 91,10 };
    struct healthy {
      std::string str { u8"healthy: " };
      DWORD colourOne { F_bGREEN };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,12 };
    } _healthy;
    struct renewed {
      std::string str { u8"renewed: " };
      DWORD colourOne { F_YELLOW };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,15 };
    } _renewed;
    struct vanished {
      std::string str { u8"vanished: " };
      DWORD colourOne { F_RED };
      //add: default count in different ages (constructor)
      unsigned int count { 0 };
      DWORD colourTwo { F_bBLUE };
      COORD Point { 91,18 };
    } _vanished;
  } _resources;

};


void Surround::colourInserter (std::string str, WORD colour, COORD pos) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleCursorPosition (consoleOutput, pos);
  SetConsoleTextAttribute (consoleOutput, colour);
  std::cout << str;
};


void Surround::newSetter (void) {
  //add: new setter
  //add: new couter
};