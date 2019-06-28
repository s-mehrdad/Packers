// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,27.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Tale.h"
#include "Shared.h"
#include "Console.h"


Tale::Tale ()
{
  title = u8"The Packers";
  colour = F_WHITE;
  //TODO add: funny story of the game! :)
};


Narrator::Narrator ()
{
  title = u8"The Narrator";
  colour = F_YELLOW;
  sentences [0] = u8"It is not sure, what the giant sees up there!";
  sentences [1] = u8"Supercomputer still dates on load process of stone age!";
  sentences [2] = u8"So the next scene is foreseen to let us wait a little!";
  startPoint = { SCREEN_W - 60, SCREEN_H - 10 };

  for ( unsigned char i = 0; i < 3; i++ )
  {
    colourInserter ( sentences [i], colour, startPoint );
    startPoint.Y += 1;
  }
};


Giant::Giant ()
{
  title = u8"A giant:";
  theGiant [0] = u8"                      ;;;;;;";
  theGiant [1] = u8"                     ;;;;;;;;";
  theGiant [2] = u8"                     ;;;;;;;;";
  theGiant [3] = u8"                     ;;■;;■;;";
  theGiant [4] = u8"■";
  theGiant [5] = u8"                     ;;;▌▐;;;";
  theGiant [6] = u8"▌▐";
  theGiant [7] = u8"                     ;;▄▄▄▄;;";
  theGiant [8] = u8"▄▄▄▄";
  theGiant [9] = u8"                      ;;;;;;";
  theGiant [10] = u8"                 ;;;;;;;;;;;;;;;                  ;;";
  theGiant [11] = u8"                 ;;;;;;;;;;;;;;;;          ;;  ;;;;";
  theGiant [12] = u8"                ;;;;;;;;;;;;;;;;;;        ;;;;;;;";
  theGiant [13] = u8";;             ;;;;;;;;;;;;♥;;;;;;;       ;;;;";
  theGiant [14] = u8"♥";
  theGiant [15] = u8" ;;           ;;;;;;;;;;;;;;;;;;;;;;    ;;;;";
  theGiant [16] = u8"  ;;         ;;;; ;;;;;;;;;;;;;; ;;;;; ;;;;";
  theGiant [17] = u8"  ;;        ;;;;  ;;;;;;;;;;;;;;   ;;;;;;;";
  theGiant [18] = u8"   ;;      ;;;;   ;;;;;;;;;;;;;;     ;;;";
  theGiant [19] = u8"   ;;     ;;;;    ;;;;;;;;;;;;;;";
  theGiant [20] = u8"   ;;    ;;;;      ;;;;;;;;;;;;;";
  theGiant [21] = u8"   ;;  ;;;;        ;;;;;;;;;;;;;";
  theGiant [22] = u8"  ;;; ;;;;         ;;;;;;;;;;;;;";
  theGiant [23] = u8"  ;;;;;;           ;;;;;;;;;;;;;";
  theGiant [24] = u8"  ;;;;              ;;;;;;;;;;;;";
  theGiant [25] = u8"   ;;               ;;;;;;;;;;;;";
  theGiant [26] = u8"   ;;               ;;;;; ;;;;;;";
  theGiant [27] = u8"   ;;               ;;;;;  ;;;;;";
  theGiant [28] = u8"   ;;               ;;;;;  ;;;;;";
  theGiant [29] = u8"   ;;               ;;;;;; ;;;;;";
  theGiant [30] = u8"   ;;                ;;;;;;;;;;;";
  theGiant [31] = u8"   ;;                 ;;;;;;;;;;";
  theGiant [32] = u8"   ;;                    ;;;;;;;;";
  theGiant [33] = u8"   ;;                     ;;;;;;;;;;;";
  theGiant [34] = u8"   ;;                     ;;;;; ;;;;;;;";
  theGiant [35] = u8"   ;;                     ;;;;   ;;;;;";
  theGiant [36] = u8"   ;;                    ;;;;;  ;;;;";
  theGiant [37] = u8"   ;;                   ;;;;;  ;;;;";
  colourOne = F_bWHITE;
  colourTwo = F_bBLUE;
  colourThree = F_RED;
  sentances [0] = u8"\"Look at these new puny two legs creatures!\"";
  sentances [1] = u8"\"Look how they dance and chew away!\"";
  startPoints [0] = { 3, SCREEN_H - 35 };
  startPoints [1] = { 50, SCREEN_H - 40 };


  COORD tempOne ( startPoints [0] );
  COORD tempTwo ( tempOne );
  for ( size_t i = 0; i < 38; i++ )
  {
    if ( i == 4 )
    {
      tempOne.Y -= 1;
      tempTwo.Y = tempOne.Y;
      tempTwo.X = tempOne.X + 23;
      colourInserter ( theGiant [i], colourTwo, tempTwo );
      tempTwo.X = tempOne.X + 26;
      colourInserter ( theGiant [i], colourTwo, tempTwo );
    } else
      if ( i == 6 )
      {
        tempOne.Y -= 1;
        tempTwo.Y = tempOne.Y;
        tempTwo.X = tempOne.X + 24;
        colourInserter ( theGiant [i], colourTwo, tempTwo );
      } else
        if ( i == 8 )
        {
          tempOne.Y -= 1;
          tempTwo.Y = tempOne.Y;
          tempTwo.X = tempOne.X + 23;
          colourInserter ( theGiant [i], colourTwo, tempTwo );
        } else
          if ( i == 14 )
          {
            tempOne.Y -= 1;
            tempTwo.Y = tempOne.Y;
            tempTwo.X = tempOne.X + 27;
            colourInserter ( theGiant [i], colourThree, tempTwo );
          } else
            colourInserter ( theGiant [i], colourOne, tempOne );
          tempOne.Y += 1;
  }
  COORD tempThree ( startPoints [1] );
  colourInserter ( title, colourTwo, tempThree );
  tempThree.Y += 2;
  colourInserter ( tempThree );
  std::string str { "" };
  for ( char element : sentances [0] )
  {
    str += element;
    colourInserter ( str, colourOne );
    str = "";
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 50 ) );
  }
  tempThree = startPoints [1];
  tempThree.Y += 3;
  colourInserter ( tempThree );
  for ( char element : sentances [1] )
  {
    str += element;
    colourInserter ( str, colourOne );
    str = "";
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 50 ) );
  }
};
