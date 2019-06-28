// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,29.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Menus.h"
#include "Console.h"


dangerAreaMenu::dangerAreaMenu ()
{
  title = u8"Danger area:";
  options [0] = u8"  Involve me!";
  options [1] = u8"  Let me furnish! :)";
  options [2] = u8"  Let's hit the road!";
  selectionSign = u8"->";
  selected = 0;
  set = false;
  startPoints [0] = { 5, SCREEN_H - 10 };
  startPoints [1] = { 4, SCREEN_H - 9 };
  switcher ();
};


void dangerAreaMenu::switcher ()
{
  COORD coordinate { startPoints [0] };

  // dangerAreaChoicesMenu
  if ( set == false )
  {
    colourInserter ( title, F_bWHITE, coordinate );
    coordinate.Y += 1;
    for ( char i = 0; i < 3; i++ )
    {
      colourInserter ( options [i], F_bWHITE, coordinate );
      coordinate.Y += 1;
    }
    colourInserter ( selectionSign, F_bRED, startPoints [1] );
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
};


void dangerAreaMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
  COORD coordinate { 0, 0 };
  unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

  // events of dangerAreaChoices
  coordinate = startPoints [1];
  coordinate.Y += selected;
  if ( confirm == false )
  {
    colourInserter ( u8"  ", F_bRED, coordinate );
    selected = chosen;
    coordinate = startPoints [1];
    coordinate.Y += chosen;
    colourInserter ( selectionSign, F_bRED, coordinate );
  } else
  {
    if ( chosen == 0 )
    {
      coordinate.X += 2;
      colourInserter ( options [0], F_bRED, coordinate );
    }
    // Todo aware the narrator! :)
  }
};


unsigned char& dangerAreaMenu::get ()
{
  return selected;
}


ageMenu::ageMenu ()
{
  title = u8"Packing speed:";
  options [0] = u8"  Stone age.";
  options [1] = u8"  Middle age...";
  options [2] = u8"  Advanced age.........";
  options [3] = u8"  Hollow age.      . .            .";
  options [4] = u8"  Dirty age (packers of packers contest!)";
  selectionSign = u8"->";
  unsigned short selected { 0 };
  bool set { false };
  startPoints [0] = { 5, SCREEN_H - 10 };
  startPoints [1] = { 4, SCREEN_H - 9 };
};


void ageMenu::switcher ()
{
  COORD coordinate { startPoints [0] };

  // ageChoicesMenu
  if ( set == false )
  {
    colourInserter ( title, F_bWHITE, coordinate );
    coordinate.Y += 1;
    for ( unsigned char i = 0; i < 5; i++ )
    {
      WORD tmpColour { F_bWHITE };
      if ( i == selected )
        tmpColour = F_bRED;
      colourInserter ( options [i], tmpColour, coordinate );
      coordinate.Y += 1;
    }
    selected = 0;
    coordinate = startPoints [1];
    colourInserter ( selectionSign, F_bRED, coordinate );
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
};


void ageMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
  COORD coordinate { 0, 0 };
  unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

  // events of ageChoices
  coordinate = startPoints [1];
  coordinate.Y += selected;
  if ( confirm == false )
  {
    colourInserter ( u8"  ", F_bRED, coordinate );
    coordinate = startPoints [1];
    coordinate.Y += chosen;
    colourInserter ( selectionSign, F_bRED, coordinate );
    selected = chosen;
  } else
  {
    // Todo aware the narrator! :)
  }
};


characterMenu::characterMenu ()
{
  title = u8"Character Choices:";
  // two character re-presenter should be enough for the ambitious packers! :)
  options [0] = u8"☺";
  options [1] = u8"☻";
  selectionSign = u8"->";
  selected = 0;
  set = false;
  startPoints [0] = { 5, SCREEN_H - 10 };;
  startPoints [1] = { 7, SCREEN_H - 9 };
};


void characterMenu::switcher ()
{
  COORD coordinate { startPoints [0] };

  // characterCoicesMenu
  if ( set == false )
  {
    colourInserter ( title, F_WHITE, coordinate );
    coordinate.X += 5;
    coordinate.Y += 1;
    for ( unsigned char i = 0; i < 2; i++ )
    {
      WORD tmpColour { F_WHITE };
      if ( i == selected )
        tmpColour = F_bRED;
      if ( i == 1 )
        coordinate.X += 7;
      colourInserter ( options [i], tmpColour, coordinate );
    }
    selected = 0;
    colourInserter ( selectionSign, F_bRED, startPoints [1] );
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
};


void characterMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
  COORD coordinate { 0, 0 };
  unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

  // events of ageChoices
  coordinate = startPoints [1];
  if ( selected == 1 )
    coordinate.X += 7;
  if ( confirm == false )
  {
    colourInserter ( u8"  ", F_bRED, coordinate );
    coordinate = startPoints [1];
    if ( chosen == 1 )
      coordinate.X += 7;
    colourInserter ( selectionSign, F_bRED, coordinate );
    selected = chosen;
  } else
  {
    // Todo aware the narrator! :)
  }
};
