// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,20.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
//#include "Area.h"
//#include "Infobars.h"
//#include "Menus.h"
#include "Packer.h"
//#include "Status.h"
#include "Surround.h"
//#include "Tale.h"
#include "Shared.h"
#include "Console.h"


//struct Surround::titleBar
//{
//  std::string titleSentence { u8"Feel free to way in as a packer toward becoming an advanced packer! ♥♥♥♥♥ :)" };
//  WORD colour { F_bBLUE };
//  COORD startPoint { ( ( SCREEN_W / 2 ) - 9 ) - ( 76 / 2 ), 0 };
//  void inserter ()
//  {
//    //COORD coordinate { startPoint };
//
//    // titleBar
//    colourInserter ( titleSentence, colour, startPoint );
//  }
//} _titleBar;


struct Surround::menus
{

  struct wayInDecision
  {
    std::string titleSentence { u8"Press that enter key ._." };
    std::string secondSentence { u8"++: This is a demo ^.^ :++" };
    WORD colour { F_bWHITE };
    COORD startPoint { ( ( SCREEN_W / 2 ) - 9 ) - ( 24 / 2 ), SCREEN_H - 7 };
    bool set { false };
    void inserter ()
    {
      COORD coordinate ( startPoint );
      if ( set == true )
      {
        colourInserter ( u8"                        ", colour, coordinate );
        coordinate.X -= 1;
        coordinate.Y += 1;
        colourInserter ( u8"                          ", colour, coordinate );
        set = false;
      } else
      {
        colourInserter ( titleSentence, colour, coordinate );
        coordinate.X -= 1;
        coordinate.Y += 1;
        colourInserter ( secondSentence, colour, coordinate );
        set = true;
      }
    };
  } _wayInDecision;

  struct dangerAreaChoices
  {
    std::string title { u8"Danger area:" };
    std::string options [3] {
      u8"  Involve me!",
      u8"  Let me furnish! :)",
      u8"  Let's hit the road!" };
    WORD colour { F_bWHITE };
    //COORD startPoint { ( ( SCREEN_W - 26 ) - 16 ), SCREEN_H - 10 };
    COORD startPoint { 5, SCREEN_H - 10 };
    unsigned short selected { 0 };
    bool set { false };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      //COORD startPoint { ( ( SCREEN_W - 26 ) - 16 ) - 1, SCREEN_H - 9 };
      COORD startPoint { 4, SCREEN_H - 9 };
    } _selectionSign;
    void inserter ()
    {
      COORD coordinate { startPoint };

      // dangerAreaChoicesMenu
      if ( set == false )
      {
        colourInserter ( title, colour, coordinate );
        coordinate.Y += 1;
        for ( char i = 0; i < 3; i++ )
        {
          colourInserter ( options [i], colour, coordinate );
          coordinate.Y += 1;
        }
        colourInserter ( _selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint );
        set = true;
      } else
      {
        coordinate.X -= 1;
        for ( unsigned char i = 0; i <= 3; i++ )
        {
          coordinate.Y += 1;
          colourInserter ( "                       ", coordinate );
        }
        set = false;
      }
    }
  } _dangerAreaChoices;

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
    COORD startPoint { 5, SCREEN_H - 10 };
    unsigned short selected { 0 };
    bool set { false };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { 4, SCREEN_H - 9 };
    } _selectionSign;
    void inserter ()
    {
      COORD coordinate { startPoint };

      // ageChoicesMenu
      if ( set == false )
      {
        colourInserter ( title, colour, coordinate );
        coordinate.Y += 1;
        for ( unsigned char i = 0; i < 5; i++ )
        {
          WORD tmpColour { colour };
          if ( i == selected )
            tmpColour = F_bRED;
          colourInserter ( options [i], tmpColour, coordinate );
          coordinate.Y += 1;
        }
        selected = 0;
        coordinate = _selectionSign.startPoint;
        colourInserter ( _selectionSign.sign, _selectionSign.colour, coordinate );
        set = true;
      } else
      {
        coordinate.X -= 1;
        for ( unsigned char i = 0; i <= 5; i++ )
        {
          colourInserter ( "                                           ", coordinate );
          coordinate.Y += 1;
        }
        set = false;
      }
    }
  } _ageChoices;

  struct characterChoices
  {
    std::string title { u8"Character Choices:" };
    // two character re-presenter should be enough for the ambitious packers! :)
    std::string options [2] {
      u8"☺" ,
      u8"☻" };
    WORD colour { F_bWHITE };
    COORD startPoint { ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2, SCREEN_H - 10 };
    unsigned short selected { 0 };
    bool set { false };
    struct selectionSign
    {
      std::string sign { u8"->" };
      WORD colour { F_bRED };
      COORD startPoint { ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 4, SCREEN_H - 9 };
    } _selectionSign;
    void inserter ()
    {
      COORD coordinate { startPoint };

      // characterCoicesMenu
      if ( set == false )
      {
        colourInserter ( title, colour, coordinate );
        coordinate.X += 5;
        coordinate.Y += 1;
        for ( unsigned char i = 0; i < 2; i++ )
        {
          WORD tmpColour { colour };
          if ( i == selected )
            tmpColour = F_bRED;
          if ( i == 1 )
            coordinate.X += 7;
          colourInserter ( options [i], tmpColour, coordinate );
        }
        selected = 0;
        colourInserter ( _selectionSign.sign, _selectionSign.colour, _selectionSign.startPoint );
        set = true;
      } else
      {
        coordinate.X -= 1;
        for ( unsigned char i = 0; i <= 1; i++ )
        {
          colourInserter ( "                    ", coordinate );
          coordinate.Y += 1;
        }
        set = false;
      }
    }
  } _characterChoices;

}_menus;


struct Surround::guideBar
{
  COORD startPoint { 10, SCREEN_H - 3 };
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
    COORD coordinate { startPoint };

    // guideBar
    for ( char i = 0; i < 3; i++ )
    {
      if ( i == 0 )
        colourInserter ( _signs.parts [i], _signs.colourOne, coordinate );
      else
        if ( i == 1 )
        {
          coordinate.X = ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2;
          colourInserter ( _signs.parts [i], _signs.colourTwo, coordinate );
        } else
        {
          coordinate.X = ( ( SCREEN_W - 26 ) - 17 );
          colourInserter ( _signs.parts [i], _signs.colourTwo, coordinate );
        }
        coordinate.X += 2;
        colourInserter ( _guides.parts [i], _guides.colour, coordinate );
    }
  }
} _GuideBar;


struct Surround::status
{
  std::string state { u8".: demo ^.^ :." };
  COORD pointOne { SCREEN_W - 16, 1 };
  std::string title { u8"status ^,^" };
  COORD pointTwo { SCREEN_W - 15, 3 };
  WORD colour { F_bWHITE };

  struct packers
  {
    std::string str { u8"packers: " };
    WORD colourOne { F_bPURPLE };
    unsigned char count { 0 };
    WORD colourTwo { F_bBLUE };
    COORD point { SCREEN_W - 15, 5 };
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
    COORD point { SCREEN_W - 15, 7 };
  } _age;

  struct resources
  {
    std::string str { u8"resources->" };
    WORD colour { F_bWHITE };
    COORD startPoint { SCREEN_W - 15, 10 };
    struct healthy
    {
      std::string str { u8"healthy:" };
      WORD colourOne { F_bGREEN };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15, 12 };
    } _healthy;
    struct renewed
    {
      std::string str { u8"renewed:" };
      WORD colourOne { F_YELLOW };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15, 15 };
    } _renewed;
    struct vanished
    {
      std::string str { u8"vanished:" };
      WORD colourOne { F_RED };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15, 18 };
    } _vanished;
  } _resources;

  struct packages
  {
    std::string str { u8"packages->" };
    WORD colour { F_bWHITE };
    COORD startPoint { SCREEN_W - 15, 21 };
    struct have
    {
      std::string str { u8"have:" };
      WORD colourOne { F_bPURPLE };
      //TODO add: default count setter in different ages (constructor)
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15, 23 };
    } _have;
    struct need
    {
      std::string str { u8"need:" };
      WORD colourOne { F_bPURPLE };
      //TODO add: random need setter in constructor
      unsigned int count { 0 };
      WORD colourTwo { F_bBLUE };
      COORD point { SCREEN_W - 15, 26 };
    } _need;
  } _packages;
  void inserter ()
  {

    // game state
    colourInserter ( state, colour, pointOne );

    // statusBar
    colourInserter ( title, colour, pointTwo );

    COORD coordinate { _packers.point };
    colourInserter ( _packers.str, _packers.colourOne, coordinate );
    coordinate.X += 9;
    colourInserter ( std::to_string ( _packers.count ), _packers.colourTwo, coordinate );

    coordinate = _age.point;
    colourInserter ( _age.str, _age.colourOne, coordinate );
    coordinate.Y += 1;
    colourInserter ( _age.ages [_age.id], _age.colourTwo, coordinate );

    colourInserter ( _resources.str, _resources.colour, _resources.startPoint );
    coordinate = _resources._healthy.point;
    colourInserter ( _resources._healthy.str, _resources._healthy.colourOne, coordinate );
    coordinate.X += 3;
    coordinate.Y += 1;
    colourInserter ( std::to_string ( _resources._healthy.count ), _resources._healthy.colourTwo, coordinate );
    coordinate = _resources._renewed.point;
    colourInserter ( _resources._renewed.str, _resources._renewed.colourOne, coordinate );
    coordinate.X += 3;
    coordinate.Y += 1;
    colourInserter ( std::to_string ( _resources._renewed.count ), _resources._renewed.colourTwo, coordinate );
    coordinate = _resources._vanished.point;
    colourInserter ( _resources._vanished.str, _resources._vanished.colourOne, coordinate );
    coordinate.X += 3;
    coordinate.Y += 1;
    colourInserter ( std::to_string ( _resources._vanished.count ), _resources._vanished.colourTwo, coordinate );

    colourInserter ( _packages.str, _packages.colour, _packages.startPoint );
    coordinate = _packages._have.point;
    colourInserter ( _packages._have.str, _packages._have.colourOne, coordinate );
    coordinate.X += 3;
    coordinate.Y += 1;
    colourInserter ( std::to_string ( _packages._have.count ), _packages._have.colourTwo, coordinate );
    coordinate = _packages._need.point;
    colourInserter ( _packages._need.str, _packages._need.colourOne, coordinate );
    coordinate.X += 3;
    coordinate.Y += 1;
    colourInserter ( std::to_string ( _packages._need.count ), _packages._need.colourTwo, coordinate );
  }
} _statusBar;


Surround::Surround ( const unsigned char& mode )
{
  // set
  _statusBar._packers.count = Packer::count;
  _statusBar._age.id = mode;

  // cout
  //_titleBar.inserter ();
  _GuideBar.inserter ();
  //_menus._wayInDecision.inserter ();
  _statusBar.inserter ();
  //_loadingBar.inserter ();
  _menus._dangerAreaChoices.inserter ();

};


void Surround::setter ( void )
{
  //TODO add: new setter
  //TODO add: new couter
};


void Surround::menusSetter ( const unsigned short& choice, const bool& confirm )
{
  COORD coordinate { 0, 0 };
  unsigned short find { static_cast<unsigned short>( choice / 10 ) };
  unsigned short chosen { static_cast<unsigned short>( choice % 10 ) };

  // events of dangerAreaChoices
  if ( find == 1 )
  {
    coordinate = _menus._dangerAreaChoices._selectionSign.startPoint;
    coordinate.Y += _menus._dangerAreaChoices.selected;
    if ( confirm == false )
    {
      colourInserter ( u8"  ", _menus._dangerAreaChoices._selectionSign.colour, coordinate );
      _menus._dangerAreaChoices.selected = chosen;
      coordinate = _menus._dangerAreaChoices._selectionSign.startPoint;
      coordinate.Y += chosen;
      colourInserter ( _menus._dangerAreaChoices._selectionSign.sign, _menus._dangerAreaChoices._selectionSign.colour, coordinate );
    } else
      switch ( chosen )
      {
        case 0:
          coordinate.X += 2;
          colourInserter ( _menus._dangerAreaChoices.options [0], F_bRED, coordinate );
          break;
        case 1:
          _menus._dangerAreaChoices.inserter ();
          _menus._ageChoices.inserter ();
          _menus._characterChoices.inserter ();
          break;
      }
  }

  // events of ageChoices
  if ( find == 2 )
  {
    coordinate = _menus._ageChoices._selectionSign.startPoint;
    coordinate.Y += _menus._ageChoices.selected;
    if ( confirm == false )
    {
      colourInserter ( u8"  ", _menus._ageChoices._selectionSign.colour, coordinate );
      coordinate = _menus._ageChoices._selectionSign.startPoint;
      coordinate.Y += chosen;
      colourInserter ( _menus._ageChoices._selectionSign.sign, _menus._ageChoices._selectionSign.colour, coordinate );
      _menus._ageChoices.selected = chosen;
    } else
    {
      coordinate.X += 2;
      colourInserter ( _menus._ageChoices.options [chosen], F_bRED, coordinate );
    }
  }

  // events of characterChoices
  if ( find == 3 )
  {
    coordinate = _menus._characterChoices._selectionSign.startPoint;
    if ( _menus._characterChoices.selected == 1 )
      coordinate.X += 7;
    if ( confirm == false )
    {
      colourInserter ( u8"  ", _menus._characterChoices._selectionSign.colour, coordinate );
      coordinate = _menus._characterChoices._selectionSign.startPoint;
      //coordinate.X += chosen;
      if ( chosen == 1 )
        coordinate.X += 7;
      colourInserter ( _menus._characterChoices._selectionSign.sign, _menus._characterChoices._selectionSign.colour, coordinate );
      _menus._characterChoices.selected = chosen;
    } else
    {
      coordinate.X += 3;
      colourInserter ( _menus._characterChoices.options [chosen], F_bRED, coordinate );
      _menus._ageChoices.inserter ();
      _menus._characterChoices.inserter ();
      _menus._dangerAreaChoices.selected = 0;
      _menus._dangerAreaChoices.inserter ();
    }
  }
};
