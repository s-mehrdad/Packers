// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,14.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Tale.h"


Narrator::Narrator ()
{
  //xx TODO add: funny story of the game! :)
  title = u8"The Narrator";
  colours [0] = F_YELLOW;
  colours [1] = F_bWHITE;
  scenes [0][0] = u8"It is not sure, what the giant sees up there!";
  scenes [0][1] = u8"Supercomputer still dates on load process of stone age!";
  scenes [0][2] = u8"Thus the next scene is foreseen to let us wait a little!";
  scenes [1][0] = "The spot pointed by the giant is interesting.";
  scenes [1][1] = "He lives at a planet full of little creatures.";
  scenes [1][2] = "Their history written in stone script is full of hunger.";
  scenes [2][0] = u8"Years after the first Packer presence on earth,";
  scenes [2][1] = u8"yet at stone age, at the teeth of continuous evolution,";
  scenes [2][2] = u8"the packing process is obvious above!";
  currentScene = 1;
  firstMenuSentences [0] = u8"I feel your enthusiasm to involve yourself,";
  firstMenuSentences [1] = u8"jet are you sure, whether you survive in stone age?! :)";
  firstMenuSentences [2] = u8"Well, undecorated involvement is still involvement...";
  firstMenuSentences [3] = u8"Oh yeah, tools and decorations are always appreciated!";
  secondMenuSentences [0] = u8"Stones and clubs are available!";
  secondMenuSentences [1] = u8"The last one tried to decorate too much,";
  secondMenuSentences [2] = u8"it ended up nasty in stone age! :)";
  secondMenuSentences [3] = u8"The age is still nasty,";
  secondMenuSentences [4] = u8"decoration isn't jet above strength. :)";
  secondMenuSentences [5] = u8"At least a little fashion after so many years!";
  secondMenuSentences [6] = u8"Yeah, decoration empty handed is still decoration!";
  secondMenuSentences [7] = u8"Pay attention to your nose, decoration isn't important!";
  startPoints [0] = { SCREEN_W - 60, SCREEN_H - 10 };
  startPoints [1] = { SCREEN_W - 60, SCREEN_H - 6 };
};


void Narrator::insertion ( const unsigned short& instance )
{
  // guide of passed argument code:
  // 1: clear four first line
  // 2: clear two last line
  // first digit: element
  // second digit: sphere
  // third digit: sentence

  coordinateType pointOne { startPoints [0] };
  coordinateType pointTwo { startPoints [1] };
  if (instance == 1)
  {
    for (unsigned char i = 0; i < 4; i++)
    {
      colourInserter ( u8"                                                          ", pointOne );
      pointOne.y += 1;
    }
  } else
    if (instance == 2)
    {
      pointOne.y += 4;
      for (unsigned char i = 0; i < 2; i++)
      {
        colourInserter ( u8"                                                          ", pointOne );
        pointOne.y += 1;
      }
    } else
    {
      unsigned char tempOne { 0 };
      unsigned char tempTwo { 0 };
      unsigned char tempThree { 0 };
      tempOne = (instance / 100);
      tempTwo = ((instance % 100) / 10);
      tempThree = ((instance % 100) % 10);
      int rnd { 0 };

      switch (tempOne)
      {
        case 1:
          // scenes:
          for (unsigned char i = 0; i < 3; i++)
          {
            colourInserter ( scenes [tempTwo][i], colours [0], pointOne );
            pointOne.y += 1;
          }
          currentScene = tempTwo;
          break;
        case 2:
          // menus:
          if (tempTwo == 1)
          {
            if (tempThree == 0)
            {
              rnd = (rand () % 2 + 1);
              switch (rnd)
              {
                case 1:
                  colourInserter ( firstMenuSentences [0], colours [1], pointTwo );
                  pointTwo.y += 1;
                  colourInserter ( firstMenuSentences [1], colours [1], pointTwo );
                  break;
                case 2:
                  colourInserter ( firstMenuSentences [2], colours [1], pointTwo );
                  break;
              }
            } else
              colourInserter ( firstMenuSentences [3], colours [1], pointTwo );
          } else
            if (tempTwo == 2)
            {
              switch (tempThree)
              {
                case 0:
                  rnd = (rand () % 2 + 1);
                  if (rnd == 1)
                    colourInserter ( secondMenuSentences [0], colours [1], pointTwo );
                  else
                  {
                    colourInserter ( secondMenuSentences [1], colours [1], pointTwo );
                    pointTwo.y += 1;
                    colourInserter ( secondMenuSentences [2], colours [1], pointTwo );
                  }
                  break;
                case 1:
                  colourInserter ( secondMenuSentences [3], colours [1], pointTwo );
                  pointTwo.y += 1;
                  colourInserter ( secondMenuSentences [4], colours [1], pointTwo );
                  break;
                case 2:
                  colourInserter ( secondMenuSentences [5], colours [1], pointTwo );
                  break;
                case 3:
                  colourInserter ( secondMenuSentences [6], colours [1], pointTwo );
                  break;
                case 4:
                  colourInserter ( secondMenuSentences [7], colours [1], pointTwo );
                  break;
              }
            }
          break;
      }
    }
};


const unsigned char& Narrator::get ( void )
{
  return currentScene;
};


Giant::Giant ()
{
  title = u8"A giant:";
  theGiant [0] = u8"                      ;;;;;;";
  theGiant [1] = u8"                     ;;;;;;;;";
  theGiant [2] = u8"                     ;;;;;;;;";
  theGiant [3] = u8"                     ;;▄;;▄;;";
  theGiant [4] = u8"▄";
  theGiant [5] = u8"                     ;;;▃▃;;;";
  theGiant [6] = u8"▃▃";
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
  colourTwo = F_CYAN;
  colourThree = F_bRED;
  sentances [0] = u8"\"Look at these new puny two legs creatures!\"";
  sentances [1] = u8"\"Look how they dance and chew away!\"";
  startPoints [0] = { 3, SCREEN_H - 37 };
  startPoints [1] = { 50, SCREEN_H - 39 };


  coordinateType tempOne ( startPoints [0] );
  coordinateType tempTwo ( tempOne );
  for (size_t i = 0; i < 38; i++)
  {
    if (i == 4)
    {
      tempOne.y -= 1;
      tempTwo.y = tempOne.y;
      tempTwo.x = tempOne.x + 23;
      colourInserter ( theGiant [i], colourTwo, tempTwo );
      tempTwo.x = tempOne.x + 26;
      colourInserter ( theGiant [i], colourTwo, tempTwo );
    } else
      if (i == 6)
      {
        tempOne.y -= 1;
        tempTwo.y = tempOne.y;
        tempTwo.x = tempOne.x + 24;
        colourInserter ( theGiant [i], colourTwo, tempTwo );
      } else
        if (i == 8)
        {
          tempOne.y -= 1;
          tempTwo.y = tempOne.y;
          tempTwo.x = tempOne.x + 23;
          colourInserter ( theGiant [i], colourTwo, tempTwo );
        } else
          if (i == 14)
          {
            tempOne.y -= 1;
            tempTwo.y = tempOne.y;
            tempTwo.x = tempOne.x + 27;
            colourInserter ( theGiant [i], colourThree, tempTwo );
          } else
            colourInserter ( theGiant [i], colourOne, tempOne );
          tempOne.y += 1;
  }
  coordinateType tempThree ( startPoints [1] );
  colourInserter ( title, colourTwo, tempThree );
  tempThree.y += 2;
  colourInserter ( tempThree );
  std::string str { "" };
  for (char element : sentances [0])
  {
    str += element;
    colourInserter ( str, colourOne );
    str = "";
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 50 ) );
  }
  tempThree = startPoints [1];
  tempThree.y += 3;
  colourInserter ( tempThree );
  for (char element : sentances [1])
  {
    str += element;
    colourInserter ( str, colourOne );
    str = "";
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 50 ) );
  }
};
