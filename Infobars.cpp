// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,20.06.2019</changed>
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
  colour = F_bBLUE;
  startPoint = { ( ( SCREEN_W / 2 ) - 9 ) - ( 76 / 2 ), 0 };
  colourInserter ( titleSentence, colour, startPoint );
};


guideBar::guideBar ()
{

}
