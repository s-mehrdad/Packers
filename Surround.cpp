// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,14.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Surround.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"


struct Surround::titelBar {
  std::string titelSentence { u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)" };
  WORD colour { F_bBLUE };
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
    WORD colour { F_bWHITE };
    COORD startPoint { 3,20 };
    unsigned short selected { 300 };
    struct selectionSign {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 1,21 };
    } _selectionSign;
  } _ageChoices;

  struct characterChoices {
    std::string title { u8"Character Choices:" };
    std::string options[2] {
      u8"  ☺  " ,
      u8"    ☻" };
    WORD colour { F_bWHITE };
    COORD startPoint { 35,20 };
    unsigned short selected { 200 };
    struct selectionSign {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 39,21 };
    } _selectionSign;
  } _characterChoices;

  struct dangerAreaChoices {
    std::string title { u8"  Danger area:" };
    std::string options[3] {
      u8"  Involve me!",
      u8"  Let me furnish! :)",
      u8"  Let's hit the road!" };
    WORD colour { F_bWHITE };
    COORD startPoint { 65,20 };
    unsigned short selected { 100 };
    struct selectionSign {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 63,21 };
    } _selectionSign;
  } _dangerAreaChoices;
}_menus;


struct Surround::guideBar {
  COORD startPoint { 3,27 };
  struct signs {
    std::string parts[3] {
      u8"♣:",
      u8"☻:",
      u8"▪:" };
    WORD colourOne { F_bGREEN };
    WORD colourTwo { F_bWHITE };
  } _signs;
  struct guides {
    std::string parts[3] {
      u8" healthy resources",
      u8" beloved packers",
      u8" already packed",
    };
    WORD colour { F_bBLUE };
  } _guides;
} _GuideBar;


struct Surround::statusBar {
  std::string title { u8"status->>" };
  WORD colour { F_bWHITE };
  COORD startPoint { 91,3 };

  struct packers {
    std::string str { u8"packers: " };
    WORD colourOne { F_bPURPLE };
    //add: count setter for new packers
    unsigned char count { 0 };
    WORD colourTwo { F_bBLUE };
    COORD point { 91,5 };
  } _packers;

  struct age {
    std::string str { u8"age: " };
    WORD colourOne { F_bPURPLE };
    //add: age setter + user choice for start age
    unsigned char id { 0 };
    std::string ages[5] {
      u8"Stone age" ,
      u8"Middle age" ,
      u8"Advanced age" ,
      u8"Hollow age" ,
      u8"Dirty age" };
    WORD colourTwo { F_bBLUE };
    COORD point { 91,7 };
  } _age;

  struct resources {
    std::string str { u8"resources>" };
    WORD colour { F_bPURPLE };
    COORD startPoint { 91,10 };
    struct healthy {
      std::string str { u8"healthy: " };
      WORD colourOne { F_bGREEN };
      //add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { 91,12 };
    } _healthy;
    struct renewed {
      std::string str { u8"renewed: " };
      WORD colourOne { F_YELLOW };
      //add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { 91,14 };
    } _renewed;
    struct vanished {
      std::string str { u8"vanished: " };
      WORD colourOne { F_RED };
      //add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { 91,16 };
    } _vanished;
  } _resources;

  struct packages {
    std::string str { u8"packages> " };
    WORD colour { F_bPURPLE };
    COORD startPoint { 91,18 };
    struct have {
      std::string str { u8"have: " };
      WORD colourOne { F_bPURPLE };
      //add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { 91,20 };
    } _have;
    struct need {
      std::string str { u8"need: " };
      WORD colourOne { F_bPURPLE };
      //add: random need setter in constructor
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { 91,23 };
    } _need;
  } _packages;
} _statusBar;


Surround::Surround (unsigned char mode) {
  // set
  _statusBar._packers.count = Packer::count;
  _statusBar._age.id = mode;

  // cout
  guidesCouter ();
  dangerMenuCouter ();
  otherMenusCouter ();
  statusCouter ();
};


void Surround::newSetter (void) {
  //add: new setter
  //add: new couter
};


void Surround::guidesCouter (void) {
  COORD position { 0,0 };

  // titleBar
  colourInserter (_titleBar.titelSentence, _titleBar.colour, _titleBar.startPoint);

  // guideBar
  position = _GuideBar.startPoint;
  for (char i = 0; i < 3; i++) {
    if (i == 0)
      colourInserter (_GuideBar._signs.parts[i], _GuideBar._signs.colourOne, position);
    else {
      position.X += static_cast<int>((pow (6, i) + 30));
      if (i == 1) position.X -= 3;
      colourInserter (_GuideBar._signs.parts[i], _GuideBar._signs.colourTwo, position);
    }
    position.X += 2;
    colourInserter (_GuideBar._guides.parts[i], _GuideBar._guides.colour, position);
    position = _GuideBar.startPoint;
  }
};


void Surround::dangerMenuCouter () {
  COORD position { 0,0 };

  // dangerAreaChoicesMenu
  position = _menus._dangerAreaChoices.startPoint;
  colourInserter (_menus._dangerAreaChoices.title, _menus._dangerAreaChoices.colour, position);
  position.Y += 1;
  for (char i = 0; i < 3; i++) {
    colourInserter (_menus._dangerAreaChoices.options[i], _menus._dangerAreaChoices.colour, position);
    position.Y += 1;
  }
  colourInserter (_menus._dangerAreaChoices._selectionSign.sign, _menus._dangerAreaChoices._selectionSign.colour, _menus._dangerAreaChoices._selectionSign.startPoint);
};


void Surround::otherMenusCouter (void) {
  COORD position { 0,0 };

  // ageChoicesMenu
  position = _menus._ageChoices.startPoint;
  colourInserter (_menus._ageChoices.title, _menus._ageChoices.colour, position);
  position.Y += 1;
  for (char i = 0; i < 5; i++) {
    colourInserter (_menus._ageChoices.options[i], _menus._ageChoices.colour, position);
    position.Y += 1;
  }
  colourInserter (_menus._ageChoices._selectionSign.sign, _menus._ageChoices._selectionSign.colour, _menus._ageChoices._selectionSign.startPoint);

  // characterCoicesMenu
  colourInserter (_menus._characterChoices.title, _menus._characterChoices.colour, _menus._characterChoices.startPoint);
  position = _menus._characterChoices.startPoint;
  position.Y += 1;
  colourInserter (_menus._characterChoices.options[0], _menus._characterChoices.colour, position);
  position.X += 5;
  colourInserter (_menus._characterChoices.options[1], _menus._characterChoices.colour, position);
  colourInserter (_menus._characterChoices._selectionSign.sign, _menus._characterChoices._selectionSign.colour, _menus._characterChoices._selectionSign.startPoint);
};


void Surround::statusCouter (void) {
  COORD position { 0,0 };

  // statusBar
  colourInserter (_statusBar.title, _statusBar.colour, _statusBar.startPoint);

  position = _statusBar._packers.point;
  colourInserter (_statusBar._packers.str, _statusBar._packers.colourOne, position);
  position.X += 9;
  colourInserter (std::to_string (_statusBar._packers.count), _statusBar._packers.colourTwo, position);

  position = _statusBar._age.point;
  colourInserter (_statusBar._age.str, _statusBar._age.colourOne, position);
  position.Y += 1;
  colourInserter (_statusBar._age.ages[_statusBar._age.id], _statusBar._age.colourTwo, position);

  colourInserter (_statusBar._resources.str, _statusBar._resources.colour, _statusBar._resources.startPoint);
  position = _statusBar._resources._healthy.point;
  colourInserter (_statusBar._resources._healthy.str, _statusBar._resources._healthy.colourOne, position);
  position.X += 9;
  colourInserter (std::to_string (_statusBar._resources._healthy.count), _statusBar._resources._healthy.colourTwo, position);
  position = _statusBar._resources._renewed.point;
  colourInserter (_statusBar._resources._renewed.str, _statusBar._resources._renewed.colourOne, position);
  position.X += 9;
  colourInserter (std::to_string (_statusBar._resources._renewed.count), _statusBar._resources._renewed.colourTwo, position);
  position = _statusBar._resources._vanished.point;
  colourInserter (_statusBar._resources._vanished.str, _statusBar._resources._vanished.colourOne, position);
  position.X += 10;
  colourInserter (std::to_string (_statusBar._resources._vanished.count), _statusBar._resources._vanished.colourTwo, position);

  colourInserter (_statusBar._packages.str, _statusBar._packages.colour, _statusBar._packages.startPoint);
  position = _statusBar._packages._have.point;
  colourInserter (_statusBar._packages._have.str, _statusBar._packages._have.colourOne, position);
  position.Y += 1;
  colourInserter (std::to_string (_statusBar._packages._have.count), _statusBar._packages._have.colourTwo, position);
  position = _statusBar._packages._need.point;
  colourInserter (_statusBar._packages._need.str, _statusBar._packages._need.colourOne, position);
  position.Y += 1;
  colourInserter (std::to_string (_statusBar._packages._need.count), _statusBar._packages._need.colourTwo, position);
};


void Surround::colourInserter (std::string str, WORD colour, COORD pos) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleCursorPosition (consoleOutput, pos);
  SetConsoleTextAttribute (consoleOutput, colour);
  std::cout << str;
};


void Surround::menusSetter (unsigned short choice, bool confirm) {
  COORD pos;
  unsigned short find { static_cast<unsigned short>(choice / 100) };
  unsigned short direction { static_cast<unsigned short>(choice % 2) };
  pos = _menus._dangerAreaChoices._selectionSign.startPoint;
  if (find == 1) {
    if (confirm != true) {
      pos.Y += (_menus._dangerAreaChoices.selected % 100) / 10;
      colourInserter (u8"  ", _menus._dangerAreaChoices._selectionSign.colour, pos);
      _menus._dangerAreaChoices.selected = choice;
      pos = _menus._dangerAreaChoices._selectionSign.startPoint;
      if (direction == 0)
        pos.Y += (choice % 100) / 10;
      else
        if (((choice % 100) % 10) == 1)
          pos.Y += (choice % 100) / 10;
      colourInserter (_menus._dangerAreaChoices._selectionSign.sign, _menus._dangerAreaChoices._selectionSign.colour, pos);
    }
    else
      if (choice == 100) {
        pos.X += 2;
        colourInserter (_menus._dangerAreaChoices.options[0], F_bRED, pos);
      }
  }
};