// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,21.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
//#include "Area.h"
#include "Infobars.h"
//#include "Menus.h"
//#include "Packer.h"
//#include "Status.h"
//#include "Surround.h"
//#include "Tale.h"
//#include "Shared.h"
#include "Console.h"


titleBar::titleBar ()
{
  titleSentence = u8"Feel free to way in as a packer toward becoming an advanced packer! ♥♥♥♥♥ :)";
  startPoint = { ( ( SCREEN_W / 2 ) - 9 ) - ( 76 / 2 ), 0 };

  // output
  colourInserter ( titleSentence, F_bBLUE, startPoint );
};


guideBar::guideBar ()
{
  startPoint = { 10, SCREEN_H - 3 };
  signs [0] = u8"♣:";
  signs [1] = u8"☻:";
  signs [2] = u8".:";
  guides [0] = u8" healthy resources";
  guides [1] = u8" beloved packers";
  guides [2] = u8" ready packages";

  // output
  COORD coordinate { startPoint };

  // guideBar
  for ( char i = 0; i < 3; i++ )
  {
    if ( i == 0 )
      colourInserter ( signs [i], F_bGREEN, coordinate );
    else
      if ( i == 1 )
      {
        coordinate.X = ( ( ( SCREEN_W - 18 ) / 2 ) - 9 ) + 2;
        colourInserter ( signs [i], F_bWHITE, coordinate );
      } else
      {
        coordinate.X = ( ( SCREEN_W - 26 ) - 17 );
        colourInserter ( signs [i], F_bWHITE, coordinate );
      }
      coordinate.X += 2;
      colourInserter ( guides [i], F_bBLUE, coordinate );
  }
};
