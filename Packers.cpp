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
/// <changed>ʆϒʅ,15.07.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Area.h"
#include "Infobars.h"
#include "Menus.h"
#include "Packer.h"
#include "Status.h"
#include "Tale.h"
#include "Shared.h"
#include "Console.h"


bool runningOne { true };
bool runningTwo { true };
unsigned char menuState { 10 };
bool involved { false };
Narrator theNarrator;

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


  // Shared.h
  Inserter insert;
  insert.clear ();
  // Tale.h
  Giant theGiant;
  theNarrator.insertion ( 10 );
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
  // packers list
  Packer* allPackersList []
  { new ( std::nothrow ) Packer ( 1 ),
  new ( std::nothrow )Packer ( 2 ),
  new ( std::nothrow )Packer ( 3 ),
  new ( std::nothrow )Packer ( 4 ),
  new ( std::nothrow )Packer ( 5 ),
  new ( std::nothrow )Packer ( 6 ),
  new ( std::nothrow )Packer ( 7 ),
  new ( std::nothrow )Packer ( 8 ), };
  Packer* involvedOne { nullptr };

#pragma endregion


  if ( allPackersList != nullptr )
  {

    // Status.h
    Status state ( 0 );
    state.get ( Packer::count );

    // Menus.h
    dangerAreaMenu menuOne;
    agesMenu menuTwo;
    charactersMenu menuThree;
    motivationsMenu menuFour;


    // coding for action area
    unsigned short temp { 0 };
    int counter { 0 };
    do
    {

#pragma region Menus

      // 10 to 12 represents the options of dangerAreaMenu
      // 20 to 24 represents the options of agesMenu
      // 30 to 31 represents the options of charactersMenu
      // 40 to 46 represents the options of motivationsMenu

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
          case 40:
          case 41:
          case 42:
          case 43:
          case 44:
            menuState += 1;
            menuFour.switchSet ( menuState, false );
            break;
          case 45:
            menuState -= 5;
            menuFour.switchSet ( menuState, false );
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
          case 40:
            menuState += 5;
            menuFour.switchSet ( menuState, false );
            break;
          case 41:
          case 42:
          case 43:
          case 44:
          case 45:
            menuState -= 1;
            menuFour.switchSet ( menuState, false );
            break;
        }
      }

      if ( GetAsyncKeyState ( VK_LEFT ) )
      {

        if ( involved == true )
        {
          if ( involvedOne->getPosition ().X > 3 )
          {
            insert.colourInserter ( involvedOne->getProcess ( 0 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );
            involvedOne->getPosition ().X -= 2;
            involvedOne->getDirection () = false;
            //! inserting packer's ids (debug purposes)
            //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
            //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
            //else
            insert.colourInserter ( involvedOne->getProcess ( 1 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );


            //if ( involvedOne->getProcess.delay == DELAY_THREE )
            //{
            //  areaOne.setter ( involvedOne->getAspiration (), involvedOne->getPosition () );
            //}
          }
        } else
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
            case 40:
            case 41:
            case 42:
              menuState += 3;
              menuFour.switchSet ( menuState, false );
              break;
            case 43:
            case 44:
            case 45:
              menuState -= 3;
              menuFour.switchSet ( menuState, false );
              break;
          }
        }
      }

      if ( GetAsyncKeyState ( VK_RIGHT ) )
      {

        if ( involved == true )
        {
          if ( involvedOne->getPosition ().X <= ( areaOne.get ().X - 3 ) )
          {
            insert.colourInserter ( involvedOne->getProcess ( 0 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );
            involvedOne->getPosition ().X += 2;
            involvedOne->getDirection () = true;
            //! inserting packer's ids (debug purposes)
            //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
            //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
            //else
            insert.colourInserter ( involvedOne->getProcess ( 1 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );
          }

          //if ( involvedOne->getProcess.delay == DELAY_THREE )
          //{
          //  areaOne.setter ( involvedOne->getAspiration (), involvedOne->getPosition () );
          //}
        }

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
          case 40:
          case 41:
          case 42:
            menuState += 3;
            menuFour.switchSet ( menuState, false );
            break;
          case 43:
          case 44:
          case 45:
            menuState -= 3;
            menuFour.switchSet ( menuState, false );
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
            // Edit: lets try it! :)
            if ( involvedOne == nullptr )
            {
              involvedOne = { new ( std::nothrow ) Packer ( Packer::count + 1 ) };
              involvedOne->involve ( ( menuThree.get () * 10 ) + menuFour.get () );
            }
            state.get ( Packer::count );
            involved = true;
            // Todo aware the narrator! :)
            //! inserting packer's ids (debug purposes)
            //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
            //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
            //else
            insert.colourInserter ( involvedOne->getProcess ( 1 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );
            menuOne.switcher ();
            insert.colourInserter ( "For the time being you can just be a nature lover! ^.^", F_bWHITE, { 3, 35 } );
            insert.colourInserter ( "This is a demo representing the idea. ^,^", F_bWHITE, { 3, 36 } );
            insert.colourInserter ( "Please press ESC to end your try.", F_bWHITE, { 3, 37 } );
            menuState = 0;
            break;
          case 11:
            //menuOne.switchSet ( menuState, true );
            menuState = 20;
            menuOne.switcher ();
            // Todo aware the narrator! :)
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
            //menuTwo.switchSet ( menuState, true );
            menuState = 30;
            menuTwo.switcher ();
            state.setter ( menuTwo.get () );
            // Todo aware the narrator! :)
            menuThree.switcher ();
            break;
          case 30:
          case 31:
            //menuThree.switchSet ( menuState, true );
            menuState = 40;
            menuThree.switcher ();
            // Todo aware the narrator! :)
            menuFour.switcher ();
            break;
          case 40:
          case 41:
          case 42:
          case 43:
          case 44:
          case 45:
            //menuFour.switchSet ( menuState, true );
            menuState = 10;
            menuFour.switcher ();
            menuOne.get () = 0;
            // Todo aware the narrator! :)
            menuOne.switcher ();
            if ( involvedOne != nullptr )
              involvedOne->involve ( ( menuThree.get () * 10 ) + menuFour.get () );
            break;
        }
      }

      {
        //xx Todo providing the ability so the involved one could escape her/his mess! :)
        // edit: solution for time being:
        if ( GetAsyncKeyState ( VK_ESCAPE ) )
        {
          involved = false;
          insert.colourInserter ( involvedOne->getProcess ( 0 ).action, involvedOne->getMotivation (), involvedOne->getPosition () );
          state.get ( Packer::count - 1 );
          menuState = 10;
          insert.colourInserter ( "                                                      ", { 3, 35 } );
          insert.colourInserter ( "                                         ", { 3, 36 } );
          insert.colourInserter ( "                                 ", { 3, 37 } );
          menuOne.switcher ();
        }
      }

#pragma endregion

      unsigned char c { 0 };
      if ( ( involved == false ) && ( involvedOne == nullptr ) )
        c = Packer::count;
      else
        c = Packer::count - 1;

      //TODO add: more smarty pants packers! :)
      //TODO add: change made by packers in their surround
      for ( int i = 0; i < 4; i++ )
      {
        for ( int j = 0; j < c; j++ )
        {
          //! inserting packer's ids (debug purposes)
          //if ( allPackersList [j]->getProcess ( i ).delay != DELAY_ONE )
          //  insert.colourInserter ( std::to_string ( allPackersList [j]->getId () ), allPackersList [j]->getMotivation (), allPackersList [j]->getPosition () );
          //else
          insert.colourInserter ( allPackersList [j]->getProcess ( i ).action, allPackersList [j]->getMotivation (), allPackersList [j]->getPosition () );

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

      counter++;
      if ( counter == 10 )
        theNarrator.insertion ( 11 );
      if ( counter == 30 )
      {
        theNarrator.insertion ( 0 );
        theNarrator.insertion ( 12 );
      }

      if ( runningOne == false )
      {
        // Note packers send their regards! :)
        runningTwo = false;
        loader.clear ();
      }
    } while ( runningTwo );
  }

  // back to system default
  SetConsoleOutputCP ( consoleOutputCPstorage );
}
