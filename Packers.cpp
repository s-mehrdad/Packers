// ********************************************************************************
/// <summary>
/// nerd Snow's sayings!
/// Programming is patience and practical practice.
/// A needed thing needs to get its done upon itself! :)
// I still remember the begin of this project, as I created the first interface of the program,
// I thought I probably need another platform to create all the funny characters, the famous packers obviously, again,
// then at some point afterward I came to decision,
// that I am exactly at the right way to create probably a new platform for games by using just characters.
// The characters can represent the human's character simply and honestly! ^.^
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,11.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Console.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"
#include "Surround.h"
#include "Tale.h"


bool runningOne { true };
bool runningTwo { true };
unsigned char menusSelection { 000 };
bool MenusFlag { false };


int main ()
{

  // ConsoleAdjustments.dll
  // font
  ConsoleFont ( FONT_NAME );
  ConsoleFontSize ( { FONT_SIZEa, FONT_SIZEb } );
  ConsoleFontColour ( F_bPURPLE );
  // screen
  ConsoleScreenPosition ( { SCREEN_L,SCREEN_T } );
  ConsoleScreenSize ( { SCREEN_W,SCREEN_H } );
  ConsoleScreenColour ( BACKGROUND_COLOUR );
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP ();
  SetConsoleOutputCP ( CP_UTF8 );
  // cursor
  ConsoleCursorState ( false );


  // Area.h
  Tale tale ( 0 );
  Loading loadOne (5);
  Loading::clear ( 77 );
  Area areaOne ( 0 );


#pragma region pacKers
  // packers
  Packer Packer1 ( 1 );
  Packer Packer2 ( 2 );
  Packer Packer3 ( 3 );
  Packer Packer4 ( 4 );
  Packer Packer5 ( 5 );
  Packer Packer6 ( 6 );
  Packer Packer7 ( 7 );
  Packer Packer8 ( 8 );
  Packer::aspirationsSetter ();

  // packers list
  std::list<Packer> allPackersList;
  allPackersList.insert ( allPackersList.begin (), Packer1 );
  allPackersList.insert ( allPackersList.begin (), Packer2 );
  allPackersList.insert ( allPackersList.begin (), Packer3 );
  allPackersList.insert ( allPackersList.begin (), Packer4 );
  allPackersList.insert ( allPackersList.begin (), Packer5 );
  allPackersList.insert ( allPackersList.begin (), Packer6 );
  allPackersList.insert ( allPackersList.begin (), Packer7 );
  allPackersList.insert ( allPackersList.begin (), Packer8 );
#pragma endregion


  // Surround.h
  Surround surroundOne ( 0 );


  // coding for action area
  do
  {

#pragma region keyPRess
    if ( GetAsyncKeyState ( VK_RETURN ) )
    {
      if ( menusSelection == 000 )
      {
        Surround::menusSetter ( 000, false );
        menusSelection = 100;
      } else
      {
        if ( menusSelection == 100 && MenusFlag == false )
          Surround::menusSetter ( menusSelection, true );
        else
          if ( menusSelection == 120 && MenusFlag == false )
          {
            runningOne = false;
          }
      }
    }

    if ( menusSelection != 000 )
    {
      if ( GetAsyncKeyState ( VK_DOWN ) )
      {
        if ( menusSelection == 100 && MenusFlag == false )
        {
          menusSelection = 110;
          MenusFlag = true;
          Surround::menusSetter ( menusSelection, false );
        } else
          if ( menusSelection == 110 && MenusFlag == false )
          {
            menusSelection = 120;
            MenusFlag = true;
            Surround::menusSetter ( menusSelection, false );
          }
        MenusFlag = false;
      }

      if ( GetAsyncKeyState ( VK_UP ) )
      {
        if ( menusSelection == 120 && MenusFlag == false )
        {
          menusSelection = 110;
          MenusFlag = true;
          Surround::menusSetter ( menusSelection + 1, false );
        } else
          if ( menusSelection == 110 && MenusFlag == false )
          {
            menusSelection = 100;
            MenusFlag = true;
            Surround::menusSetter ( menusSelection + 1, false );
          }
        MenusFlag = false;
      }

      if ( GetAsyncKeyState ( VK_LEFT ) )
      {

      }

      if ( GetAsyncKeyState ( VK_RIGHT ) )
      {

      }
    }
#pragma endregion


    //TODO add: more smarty pants packers! :)
    //TODO add: change made by packers in their surround
    for ( int i = 0; i < 4; i++ )
    {
      for ( int j = 0; j < Packer::count; j++ )
      {
        //! inserting packer's ids (debug purposes)
        //if ( allPackersList.back ().moves [i].delay != DELAY_ONE )
        //    Packer::colourInserter ( std::to_string ( allPackersList.back ().id ), allPackersList.back ().moves [i].colour, allPackersList.back ().position );
        //else
        Inserter::colourInserter ( allPackersList.back ()._action [i].current, allPackersList.back ().baseMotivation, allPackersList.back ().position );

        if ( allPackersList.back ()._action [i].delay == DELAY_ONE )
        {
          if ( allPackersList.back ().RchanceL == true )
          {
            if ( allPackersList.back ().position.X != ( Area::columns - 3 ) )
              allPackersList.back ().position.X += 2;
            else
              allPackersList.back ().RchanceL = false;
          } else
            if ( allPackersList.back ().position.X != 3 )
              allPackersList.back ().position.X -= 2;
            else
              allPackersList.back ().RchanceL = true;
        }
        if ( allPackersList.back ()._action [i].delay == DELAY_THREE )
        {
          allPackersList.back ().lastAspiration /= 100;
          allPackersList.back ().lastAspiration *= 100;
          allPackersList.back ().lastAspiration += Packer::aspirations [allPackersList.back ().id] + 2;
          Area::resourceSetter ( allPackersList.back ().lastAspiration, allPackersList.back ().position );
        }
        allPackersList.emplace_front ( allPackersList.back () );
        allPackersList.pop_back ();
      }
      std::this_thread::sleep_for ( std::chrono::milliseconds ( allPackersList.back ()._action [i].delay ) );
    }
    if ( runningOne == false )
    {
      runningTwo = false;
      Loading::clear ( 77 );
    }
  } while ( runningTwo );


  // back to system default
  SetConsoleOutputCP ( consoleOutputCPstorage );
}
