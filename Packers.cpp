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
/// <changed>ʆϒʅ,27.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Area.h"
#include "Infobars.h"
#include "Menus.h"
#include "Packer.h"
#include "Status.h"
#include "Surround.h"
#include "Tale.h"
#include "Shared.h"
#include "Console.h"


bool runningOne { true };
bool runningTwo { true };
unsigned char menuState { 10 };
bool MenusFlag { false };


int main ()
{
#pragma region ConsoleAdjustments
  // Console.h
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
#pragma endregion


  // Tale.h
  Tale tale ( 0 );
  // Shared.h
  Loading loader ( LOAD_ONE );
  loader.clear ();
  // Infobars.h
  titleBar title;
  guideBar guide;
  // Area.h
  Area areaOne ( 0 );
  // Shared.h
  loader.setter ( LOAD_ONE );


#pragma region pacKers
  // Packer.h

  Packer* allPackersList []
  { new ( std::nothrow ) Packer ( 1 ),
  new ( std::nothrow )Packer ( 2 ),
  new ( std::nothrow )Packer ( 3 ),
  new ( std::nothrow )Packer ( 4 ),
  new ( std::nothrow )Packer ( 5 ),
  new ( std::nothrow )Packer ( 6 ),
  new ( std::nothrow )Packer ( 7 ),
  new ( std::nothrow )Packer ( 8 ), };

  //Packer Packer1 ( 1 );
  //Packer Packer2 ( 2 );
  //Packer Packer3 ( 3 );
  //Packer Packer4 ( 4 );
  //Packer Packer5 ( 5 );
  //Packer Packer6 ( 6 );
  //Packer Packer7 ( 7 );
  //Packer Packer8 ( 8 );
  //Packer::aspirationsSetter ();

  // packers list
  //std::list<Packer> allPackersList;
  //allPackersList.insert ( allPackersList.begin (), Packer1 );
  //allPackersList.insert ( allPackersList.begin (), Packer2 );
  //allPackersList.insert ( allPackersList.begin (), Packer3 );
  //allPackersList.insert ( allPackersList.begin (), Packer4 );
  //allPackersList.insert ( allPackersList.begin (), Packer5 );
  //allPackersList.insert ( allPackersList.begin (), Packer6 );
  //allPackersList.insert ( allPackersList.begin (), Packer7 );
  //allPackersList.insert ( allPackersList.begin (), Packer8 );
#pragma endregion


  if ( allPackersList != nullptr )
  {

    // Status.h
    Status state ( 0 );
    state.get ( Packer::count );

    // Menus.h
    dangerAreaMenu menuOne;
    ageMenu menuTwo;
    characterMenu menuThree;


    // Surround.h
    //Surround surroundOne ( 0 );


    // coding for action area
    unsigned short temp { 0 };
    do
    {

#pragma region Menus

      // 10 to 12 represents the options of dangerAreaMenu
      // 20 to 24 represents the options of ageMenu
      // 30 to 31 represents the options of characterMenu

      if ( GetAsyncKeyState ( VK_DOWN ) )
      {
        switch ( menuState )
        {
          case 10:
          case 11:
            menuState += 1;
            menuOne.switchSet ( menuState, false );
            break;
          case 12:
            menuState -= 2;
            menuOne.switchSet ( menuState, false );
            break;
          case 20:
          case 21:
          case 22:
          case 23:
            menuState += 1;
            menuTwo.switchSet ( menuState, false );
            break;
          case 24:
            menuState -= 4;
            menuTwo.switchSet ( menuState, false );
            break;
        }
      }
      if ( GetAsyncKeyState ( VK_UP ) )
      {
        switch ( menuState )
        {
          case 10:
            menuState += 2;
            menuOne.switchSet ( menuState, false );
            break;
          case 11:
          case 12:
            menuState -= 1;
            menuOne.switchSet ( menuState, false );
            break;
          case 20:
            menuState += 4;
            menuTwo.switchSet ( menuState, false );
            break;
          case 21:
          case 22:
          case 23:
          case 24:
            menuState -= 1;
            menuTwo.switchSet ( menuState, false );
            break;
        }
      }

      if ( GetAsyncKeyState ( VK_LEFT ) )
      {
        switch ( menuState )
        {
          case 30:
            menuState += 1;
            menuThree.switchSet ( menuState, false );
            break;
          case 31:
            menuState -= 1;
            menuThree.switchSet ( menuState, false );
            break;
        }
      }

      if ( GetAsyncKeyState ( VK_RIGHT ) )
      {
        switch ( menuState )
        {
          case 30:
            menuState += 1;
            menuThree.switchSet ( menuState, false );
            break;
          case 31:
            menuState -= 1;
            menuThree.switchSet ( menuState, false );
            break;
        }
      }

      if ( GetAsyncKeyState ( VK_RETURN ) )
      {
        switch ( menuState )
        {
          case 10:
            // Todo FYI, user may doubtfully get involved in demo too! :)
            //xx Todo possible dream is also a dream! :) as if the programmer has more than two hands!
            menuOne.switchSet ( menuState, true );
            break;
          case 11:
            menuOne.switchSet ( menuState, true );
            menuState = 20;
            menuOne.switcher ();
            menuTwo.switcher ();
            break;
          case 12:
            runningOne = false;
            break;
          case 20:
          case 21:
          case 22:
          case 23:
          case 24:
            menuTwo.switchSet ( menuState, true );
            menuState = 30;
            menuTwo.switcher ();
            menuThree.switcher ();
            break;
          case 30:
          case 31:
            menuThree.switchSet ( menuState, true );
            menuState = 10;
            menuThree.switcher ();
            menuOne.switcher ();
            menuOne.get () = 0;
            break;
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
          //if ( allPackersList [j]->getProcess ( i ).delay != DELAY_ONE )
          //  colourInserter ( std::to_string ( allPackersList [j]->getId () ), allPackersList [j]->getMotivation (), allPackersList [j]->getPosition () );
          //else
          colourInserter ( allPackersList [j]->getProcess ( i ).action, allPackersList [j]->getMotivation (), allPackersList [j]->getPosition () );

          if ( allPackersList [j]->getProcess ( i ).delay == DELAY_ONE )
          {
            if ( allPackersList [j]->getDirection () == true )
            {
              if ( allPackersList [j]->getPosition ().X <= ( areaOne.get ().X - 3 ) )
                allPackersList [j]->getPosition ().X += 2;
              else
                allPackersList [j]->getDirection () = false;
            } else
              if ( allPackersList [j]->getPosition ().X > 3 )
                allPackersList [j]->getPosition ().X -= 2;
              else
                allPackersList [j]->getDirection () = true;
          }
          if ( allPackersList [j]->getProcess ( i ).delay == DELAY_THREE )
          {
            areaOne.setter ( allPackersList [j]->getAspiration (), allPackersList [j]->getPosition () );
          }
          temp = allPackersList [0]->getProcess ( i ).delay;
        }
        std::this_thread::sleep_for ( std::chrono::milliseconds ( temp ) );
      }


      if ( runningOne == false )
      {
        // packers send their regards! :)
        runningTwo = false;
        loader.clear ();
      }

      ////TODO add: more smarty pants packers! :)
      ////TODO add: change made by packers in their surround
      //for ( int i = 0; i < 4; i++ )
      //{
      //  for ( int j = 0; j < Packer::count; j++ )
      //  {
      //    //! inserting packer's ids (debug purposes)
      //    //if ( allPackersList.back ().moves [i].delay != DELAY_ONE )
      //    //    Packer::colourInserter ( std::to_string ( allPackersList.back ().id ), allPackersList.back ().moves [i].colour, allPackersList.back ().position );
      //    //else
      //    colourInserter ( allPackersList.back ()._action [i].current, allPackersList.back ().baseMotivation, allPackersList.back ().position );

      //    if ( allPackersList.back ()._action [i].delay == DELAY_ONE )
      //    {
      //      if ( allPackersList.back ().get () == true )
      //      {
      //        if ( allPackersList.back ().position.X <= ( areaOne.get ().X - 3 ) )
      //          allPackersList.back ().position.X += 2;
      //        else
      //          allPackersList.back ().get () = false;
      //      } else
      //        if ( allPackersList.back ().position.X > 3 )
      //          allPackersList.back ().position.X -= 2;
      //        else
      //          allPackersList.back ().get () = true;
      //    }
      //    if ( allPackersList.back ()._action [i].delay == DELAY_THREE )
      //    {
      //      allPackersList.back ().lastAspiration /= 100;
      //      allPackersList.back ().lastAspiration *= 100;
      //      allPackersList.back ().lastAspiration += Packer::aspirations [allPackersList.back ().id] + 2;
      //      //Area::resourceSetter ( allPackersList.back ().lastAspiration, allPackersList.back ().position );
      //      areaOne.setter ( allPackersList.back ().lastAspiration, allPackersList.back ().position );
      //    }
      //    allPackersList.emplace_front ( allPackersList.back () );
      //    allPackersList.pop_back ();
      //  }
      //  std::this_thread::sleep_for ( std::chrono::milliseconds ( allPackersList.back ()._action [i].delay ) );
      //}
      //if ( runningOne == false )
      //{
      //  runningTwo = false;
      //  loader.clear ();
      //}
    } while ( runningTwo );
  }

  // back to system default
  SetConsoleOutputCP ( consoleOutputCPstorage );
}
