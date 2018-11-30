// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,15.11.2018</changed>
// ********************************************************************************

#include "pch.h"
#include "Surround.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"


struct Surround::titleBar {
  std::string titleSentence { u8"Feel free to way in as a packer toward becoming an advanced packer! ♥♥♥♥♥ :)" };
  WORD colour { F_bBLUE };
  COORD startPoint { 7,0 };
  void inserter () {
    COORD position { 0,0 };

    // titleBar
    colourInserter (titleSentence, colour, startPoint);
  }
} _titleBar;


struct Surround::menus {
  struct wayInDecision {
    std::string titleSentence { u8"Press that enter key ._." };
    WORD colour { F_bWHITE };
    COORD startPoint { 33,25 };
    bool set { false };
    void inserter () {
      if (set == true) {
        colourInserter (u8"                        ", colour, startPoint);
        set = false;
      }
      else {
        colourInserter (titleSentence, colour, startPoint);
        set = true;
      }
    };
  } _wayInDecision;

  struct agesChoices {
    std::string title { u8"Packing speed:" };
    std::string options[5] {
      u8"  Stone age." ,
      u8"  Middle age..." ,
      u8"  Advanced age........." ,
      u8"  Hollow age.      . .            ." ,
      u8"  Dirty age (packers of packers contest!)" };
    WORD colour { F_bWHITE };
    COORD startPoint { 5,20 };
    unsigned short selected { 300 };
    struct selectionSign {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 3,21 };
    } _selectionSign;
    void inserter () {
      COORD position { 0,0 };

      // ageChoicesMenu
      position = startPoint;
      colourInserter (title, colour, position);
      position.Y += 1;
      for (char i = 0; i < 5; i++) {
        colourInserter (options[i], colour, position);
        position.Y += 1;
      }
      colourInserter (_selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint);
    }
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
      COORD startPoint { 43,21 };
    } _selectionSign;
    void inserter () {
      COORD position { 0,0 };

      // characterCoicesMenu
      position = startPoint;
      colourInserter (title, colour, position);
      position.X += 3;
      position.Y += 1;
      colourInserter (options[0], colour, position);
      position.X += 5;
      colourInserter (options[1], colour, position);
      colourInserter (_selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint);
    }
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
    void inserter () {
      COORD position { 0,0 };

      // dangerAreaChoicesMenu
      position = startPoint;
      colourInserter (title, colour, position);
      position.Y += 1;
      for (char i = 0; i < 3; i++) {
        colourInserter (options[i], colour, position);
        position.Y += 1;
      }
      colourInserter (_selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint);
    }
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
  void inserter () {
    COORD position { 0,0 };

    // guideBar
    position = startPoint;
    for (char i = 0; i < 3; i++) {
      if (i == 0)
        colourInserter (_signs.parts[i], _signs.colourOne, position);
      else {
        position.X += static_cast<int>((pow (6, i) + 30));
        if (i == 1) position.X -= 3;
        colourInserter (_signs.parts[i], _signs.colourTwo, position);
      }
      position.X += 2;
      colourInserter (_guides.parts[i], _guides.colour, position);
      position = startPoint;
    }
  }
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
  void inserter () {
    COORD position { 0,0 };

    // statusBar
    colourInserter (title, colour, startPoint);

    position = _packers.point;
    colourInserter (_packers.str, _packers.colourOne, position);
    position.X += 9;
    colourInserter (std::to_string (_packers.count), _packers.colourTwo, position);

    position = _age.point;
    colourInserter (_age.str, _age.colourOne, position);
    position.Y += 1;
    colourInserter (_age.ages[_age.id], _age.colourTwo, position);

    colourInserter (_resources.str, _resources.colour, _resources.startPoint);
    position = _resources._healthy.point;
    colourInserter (_resources._healthy.str, _resources._healthy.colourOne, position);
    position.X += 9;
    colourInserter (std::to_string (_resources._healthy.count), _resources._healthy.colourTwo, position);
    position = _resources._renewed.point;
    colourInserter (_resources._renewed.str, _resources._renewed.colourOne, position);
    position.X += 9;
    colourInserter (std::to_string (_resources._renewed.count), _resources._renewed.colourTwo, position);
    position = _resources._vanished.point;
    colourInserter (_resources._vanished.str, _resources._vanished.colourOne, position);
    position.X += 10;
    colourInserter (std::to_string (_resources._vanished.count), _resources._vanished.colourTwo, position);

    colourInserter (_packages.str, _packages.colour, _packages.startPoint);
    position = _packages._have.point;
    colourInserter (_packages._have.str, _packages._have.colourOne, position);
    position.Y += 1;
    colourInserter (std::to_string (_packages._have.count), _packages._have.colourTwo, position);
    position = _packages._need.point;
    colourInserter (_packages._need.str, _packages._need.colourOne, position);
    position.Y += 1;
    colourInserter (std::to_string (_packages._need.count), _packages._need.colourTwo, position);
  }
} _statusBar;


struct Surround::loadingBar {
  std::string characters[9] { u8"L", u8"O", u8"A", u8"D", u8"I", u8"N", u8"G", u8"#", u8" " };
  std::string copywrite { u8"  ©: ʆϒʅ" };
  WORD colourOne { B_bBLUE | F_bWHITE };
  WORD colourTwo { B_BLACK | F_bGREEN };
  WORD colourThree { B_BLACK | F_bWHITE };
  COORD startPoint { SCREEN_W - 10, SCREEN_H - 1 };
  void inserter () {
    COORD position { startPoint };
    for (unsigned char i = 0; i < 7; i++) {
      colourInserter (characters[i], colourOne, position);
      std::this_thread::sleep_for (std::chrono::milliseconds (100));
      position.X += 1;
    }
    for (unsigned char i = 1; i <= 3; i++) {
      colourInserter (characters[7], colourTwo, position);
      std::this_thread::sleep_for (std::chrono::milliseconds (150));
      colourInserter (characters[8], colourTwo, position);
      std::this_thread::sleep_for (std::chrono::milliseconds (200));
    }
    std::this_thread::sleep_for (std::chrono::milliseconds (200));
    colourInserter (copywrite, colourThree, startPoint);
  }
} _loadingBar;


//to be added: funny literature of the game
struct Surround::storyLine {

} _storyLine;


Surround::Surround (unsigned char mode) {
  // set
  _statusBar._packers.count = Packer::count;
  _statusBar._age.id = mode;

  // cout
  _titleBar.inserter ();
  _GuideBar.inserter ();
  _menus._wayInDecision.inserter ();
  _statusBar.inserter ();
  _loadingBar.inserter ();
};


void Surround::newSetter (void) {
  //add: new setter
  //add: new couter
};


void Surround::colourInserter (std::string str, WORD colour, COORD pos) {
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleCursorPosition (consoleOutput, pos);
  SetConsoleTextAttribute (consoleOutput, colour);
  std::cout << str;
};


void Surround::menusSetter (unsigned short choice, bool confirm) {
  if (choice == 000) {
    if (_menus._wayInDecision.set == true) {
      _menus._wayInDecision.inserter ();
      _menus._ageChoices.inserter ();
      _menus._characterChoices.inserter ();
      _menus._dangerAreaChoices.inserter ();
    }
  }
  else {
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
  }
};