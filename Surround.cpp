// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#include "pch.h"
#include "Surround.h"
#include "Shared.h"
#include "ConsoleAdjustments.h"
#include "Area.h"
#include "Packer.h"
#include "Tale.h"


struct Surround::titleBar
{
  std::string titleSentence { u8"Feel free to way in as a packer toward becoming an advanced packer! ♥♥♥♥♥ :)" };
  WORD colour { F_bBLUE };
  COORD startPoint { ( ( SCREEN_W / 2 ) - 9 ) - ( 76 / 2 ),0 };
  void inserter ()
  {
    COORD position { 0,0 };

    // titleBar
    Inserter::colourInserter ( titleSentence, colour, startPoint );
  }
} _titleBar;


struct Surround::menus
{
  struct wayInDecision
  {
    std::string titleSentence { u8"Press that enter key ._." };
    std::string secondSentence { u8"++: This is a demo ^.^ :++" };
    WORD colour { F_bWHITE };
    COORD startPoint { ( ( SCREEN_W / 2 ) - 9 ) - ( 24 / 2 ),Area::rows + 3 };
    bool set { false };
    void inserter ()
    {
      COORD temp ( startPoint );
      if ( set == true )
      {
        Inserter::colourInserter ( u8"                        ", colour, temp );
        temp.X -= 1;
        temp.Y += 1;
        Inserter::colourInserter ( u8"                          ", colour, temp );
        set = false;
      } else
      {
        Inserter::colourInserter ( titleSentence, colour, temp );
        temp.X -= 1;
        temp.Y += 1;
        Inserter::colourInserter ( secondSentence, colour, temp );
        set = true;
      }
    };
  } _wayInDecision;

  struct agesChoices
  {
    std::string title { u8"Packing speed:" };
    std::string options [5] {
      u8"  Stone age." ,
      u8"  Middle age..." ,
      u8"  Advanced age........." ,
      u8"  Hollow age.      . .            ." ,
      u8"  Dirty age (packers of packers contest!)" };
    WORD colour { F_bWHITE };
    COORD startPoint { 5,Area::rows + 2 };
    unsigned short selected { 300 };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 4,Area::rows + 3 };
    } _selectionSign;
    void inserter ()
    {
      COORD position { 0,0 };

      // ageChoicesMenu
      position = startPoint;
      Inserter::colourInserter ( title, colour, position );
      position.Y += 1;
      for ( char i = 0; i < 5; i++ )
      {
        Inserter::colourInserter ( options [i], colour, position );
        position.Y += 1;
      }
      Inserter::colourInserter ( _selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint );
    }
  } _ageChoices;

  struct characterChoices
  {
    std::string title { u8"Character Choices:" };
    // two character re-presenter for the ambitious packers should be enough! :)
    std::string options [2] {
      u8"  ☺  " ,
      u8"    ☻" };
    WORD colour { F_bWHITE };
    //position.X = ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2;

    COORD startPoint { ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2,Area::rows + 2 };
    unsigned short selected { 200 };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 11,Area::rows + 3 };
    } _selectionSign;
    void inserter ()
    {
      COORD position { 0,0 };

      // characterCoicesMenu
      position = startPoint;
      Inserter::colourInserter ( title, colour, position );
      position.X += 3;
      position.Y += 1;
      Inserter::colourInserter ( options [0], colour, position );
      position.X += 5;
      Inserter::colourInserter ( options [1], colour, position );
      Inserter::colourInserter ( _selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint );
    }
  } _characterChoices;

  struct dangerAreaChoices
  {
    std::string title { u8"Danger area:" };
    std::string options [3] {
      u8"  Involve me!",
      u8"  Let me furnish! :)",
      u8"  Let's hit the road!" };
    WORD colour { F_bWHITE };
    COORD startPoint { ( ( SCREEN_W - 26 ) - 16 ),Area::rows + 2 };
    unsigned short selected { 100 };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { ( ( SCREEN_W - 26 ) - 16 ) - 1,Area::rows + 3 };
    } _selectionSign;
    void inserter ()
    {
      COORD position { 0,0 };

      // dangerAreaChoicesMenu
      position = startPoint;
      Inserter::colourInserter ( title, colour, position );
      position.Y += 1;
      for ( char i = 0; i < 3; i++ )
      {
        Inserter::colourInserter ( options [i], colour, position );
        position.Y += 1;
      }
      Inserter::colourInserter ( _selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint );
    }
  } _dangerAreaChoices;
}_menus;


struct Surround::guideBar
{
  COORD startPoint { 10, SCREEN_H - 2 };
  struct signs
  {
    std::string parts [3] {
      u8"♣:",
      u8"☻:",
      u8".:" };
    WORD colourOne { F_bGREEN };
    WORD colourTwo { F_bWHITE };
  } _signs;
  struct guides
  {
    std::string parts [3] {
      u8" healthy resources",
      u8" beloved packers",
      u8" ready packages",
    };
    WORD colour { F_bBLUE };
  } _guides;
  void inserter ()
  {
    COORD position { 0,0 };

    // guideBar
    position = startPoint;

    for ( char i = 0; i < 3; i++ )
    {
      if ( i == 0 )
        Inserter::colourInserter ( _signs.parts [i], _signs.colourOne, position );
      else
        if ( i == 1 )
        {
          position.X = ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2;
          Inserter::colourInserter ( _signs.parts [i], _signs.colourTwo, position );
        } else
        {
          position.X = ( ( SCREEN_W - 26 ) - 17 );
          Inserter::colourInserter ( _signs.parts [i], _signs.colourTwo, position );
        }
        position.X += 2;
        Inserter::colourInserter ( _guides.parts [i], _guides.colour, position );
    }
  }
} _GuideBar;


struct Surround::statusBar
{
  std::string title { u8"status ^,^" };
  WORD colour { F_bWHITE };
  COORD startPoint { SCREEN_W - 15,3 };

  struct packers
  {
    std::string str { u8"packers: " };
    WORD colourOne { F_bPURPLE };
    unsigned char count { 0 };
    WORD colourTwo { F_bBLUE };
    COORD point { SCREEN_W - 15,5 };
  } _packers;

  struct age
  {
    std::string str { u8"age:" };
    WORD colourOne { F_bPURPLE };
    //TODO add: age setter + user choice for start age
    unsigned char id { 0 };
    std::string ages [5] {
      u8"   Stone" ,
      u8"   Middle" ,
      u8"   Advanced" ,
      u8"   Hollow" ,
      u8"   Dirty" };
    WORD colourTwo { F_bBLUE };
    COORD point { SCREEN_W - 15,7 };
  } _age;

  struct resources
  {
    std::string str { u8"resources->" };
    WORD colour { F_bWHITE };
    COORD startPoint { SCREEN_W - 15,10 };
    struct healthy
    {
      std::string str { u8"healthy:" };
      WORD colourOne { F_bGREEN };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15,12 };
    } _healthy;
    struct renewed
    {
      std::string str { u8"renewed:" };
      WORD colourOne { F_YELLOW };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15,15 };
    } _renewed;
    struct vanished
    {
      std::string str { u8"vanished:" };
      WORD colourOne { F_RED };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15,18 };
    } _vanished;
  } _resources;

  struct packages
  {
    std::string str { u8"packages->" };
    WORD colour { F_bWHITE };
    COORD startPoint { SCREEN_W - 15,21 };
    struct have
    {
      std::string str { u8"have:" };
      WORD colourOne { F_bPURPLE };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15,23 };
    } _have;
    struct need
    {
      std::string str { u8"need:" };
      WORD colourOne { F_bPURPLE };
      //TODO add: random need setter in constructor
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15,26 };
    } _need;
  } _packages;
  void inserter ()
  {
    COORD position { 0,0 };

    // statusBar
    Inserter::colourInserter ( title, colour, startPoint );

    position = _packers.point;
    Inserter::colourInserter ( _packers.str, _packers.colourOne, position );
    position.X += 9;
    Inserter::colourInserter ( std::to_string ( _packers.count ), _packers.colourTwo, position );

    position = _age.point;
    Inserter::colourInserter ( _age.str, _age.colourOne, position );
    position.Y += 1;
    Inserter::colourInserter ( _age.ages [_age.id], _age.colourTwo, position );

    Inserter::colourInserter ( _resources.str, _resources.colour, _resources.startPoint );
    position = _resources._healthy.point;
    Inserter::colourInserter ( _resources._healthy.str, _resources._healthy.colourOne, position );
    position.X += 3;
    position.Y += 1;
    Inserter::colourInserter ( std::to_string ( _resources._healthy.count ), _resources._healthy.colourTwo, position );
    position = _resources._renewed.point;
    Inserter::colourInserter ( _resources._renewed.str, _resources._renewed.colourOne, position );
    position.X += 3;
    position.Y += 1;
    Inserter::colourInserter ( std::to_string ( _resources._renewed.count ), _resources._renewed.colourTwo, position );
    position = _resources._vanished.point;
    Inserter::colourInserter ( _resources._vanished.str, _resources._vanished.colourOne, position );
    position.X += 3;
    position.Y += 1;
    Inserter::colourInserter ( std::to_string ( _resources._vanished.count ), _resources._vanished.colourTwo, position );

    Inserter::colourInserter ( _packages.str, _packages.colour, _packages.startPoint );
    position = _packages._have.point;
    Inserter::colourInserter ( _packages._have.str, _packages._have.colourOne, position );
    position.X += 3;
    position.Y += 1;
    Inserter::colourInserter ( std::to_string ( _packages._have.count ), _packages._have.colourTwo, position );
    position = _packages._need.point;
    Inserter::colourInserter ( _packages._need.str, _packages._need.colourOne, position );
    position.X += 3;
    position.Y += 1;
    Inserter::colourInserter ( std::to_string ( _packages._need.count ), _packages._need.colourTwo, position );
  }
} _statusBar;


//struct Surround::loadingBar
//{
//    std::string characters [9] { u8"L", u8"O", u8"A", u8"D", u8"I", u8"N", u8"G", u8"#", u8" " };
//    //std::string copywrite { u8"  ©: ʆϒʅ" }; // for fonts with more characters
//    std::string copywrite { u8"  ©: }Y{" };
//    WORD colourOne { B_bBLUE | F_bWHITE };
//    WORD colourTwo { B_BLACK | F_bGREEN };
//    WORD colourThree { B_BLACK | F_bWHITE };
//    COORD startPoint { SCREEN_W - 13, SCREEN_H - 2 };
//    void inserter ()
//    {
//        COORD position { startPoint };
//        for ( unsigned char i = 0; i < 7; i++ )
//        {
//            Inserter::colourInserter ( characters [i], colourOne, position );
//            std::this_thread::sleep_for ( std::chrono::milliseconds ( 100 ) );
//            position.X += 1;
//        }
//        for ( unsigned char i = 1; i <= 3; i++ )
//        {
//            Inserter::colourInserter ( characters [7], colourTwo, position );
//            std::this_thread::sleep_for ( std::chrono::milliseconds ( 150 ) );
//            Inserter::colourInserter ( characters [8], colourTwo, position );
//            std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
//        }
//        std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );
//        Inserter::colourInserter ( copywrite, colourThree, startPoint );
//    }
//} _loadingBar;
//
//
////TODO to be added: funny literature of the game! :)
//struct Surround::storyLine
//{
//
//} _storyLine;


Surround::Surround ( unsigned char mode )
{
  // set
  _statusBar._packers.count = Packer::count;
  _statusBar._age.id = mode;

  // cout
  _titleBar.inserter ();
  _GuideBar.inserter ();
  _menus._wayInDecision.inserter ();
  _statusBar.inserter ();
  //_loadingBar.inserter ();
};


void Surround::newSetter ( void )
{
  //TODO add: new setter
  //TODO add: new couter
};


//void Surround::colourInserter ( std::string str, WORD colour, COORD pos )
//{
//    GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
//    SetConsoleCursorPosition ( consoleOutput, pos );
//    SetConsoleTextAttribute ( consoleOutput, colour );
//    std::cout << str;
//};


void Surround::menusSetter ( unsigned short choice, bool confirm )
{
  if ( choice == 000 )
  {
    if ( _menus._wayInDecision.set == true )
    {
      _menus._wayInDecision.inserter ();
      _menus._ageChoices.inserter ();
      _menus._characterChoices.inserter ();
      _menus._dangerAreaChoices.inserter ();
    }
  } else
  {
    COORD pos;
    unsigned short find { static_cast<unsigned short>( choice / 100 ) };
    unsigned short direction { static_cast<unsigned short>( choice % 2 ) };
    pos = _menus._dangerAreaChoices._selectionSign.startPoint;
    if ( find == 1 )
    {
      if ( confirm != true )
      {
        pos.Y += ( _menus._dangerAreaChoices.selected % 100 ) / 10;
        Inserter::colourInserter ( u8"  ", _menus._dangerAreaChoices._selectionSign.colour, pos );
        _menus._dangerAreaChoices.selected = choice;
        pos = _menus._dangerAreaChoices._selectionSign.startPoint;
        if ( direction == 0 )
          pos.Y += ( choice % 100 ) / 10;
        else
          if ( ( ( choice % 100 ) % 10 ) == 1 )
            pos.Y += ( choice % 100 ) / 10;
        Inserter::colourInserter ( _menus._dangerAreaChoices._selectionSign.sign, _menus._dangerAreaChoices._selectionSign.colour, pos );
      } else
        if ( choice == 100 )
        {
          pos.X += 2;
          Inserter::colourInserter ( _menus._dangerAreaChoices.options [0], F_bRED, pos );
        }
    }
  }
};