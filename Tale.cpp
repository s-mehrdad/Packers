
// ===========================================================================
/// <summary>
/// Tale.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 01.04.2019
/// </summary>
/// <created>ʆϒʅ, 01.04.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Tale.h"


TheNarrator::TheNarrator (std::wstring name) :GameElement::GameElement ()
{

    setBase ();

    elementID = 0;
    elementName = name;
    firstInScene = 1;
    currentScene = 1;
    //xx TODO add: funny story of the game! :)
    title = L"The Narrator";
    colours [0] = F_YELLOW;
    colours [1] = F_bWHITE;

    scenes [0][0] = L"It is not sure, what the giant sees";
    scenes [0][1] = L"up there! Supercomputer still dates on ";
    scenes [0][2] = L"load process of stone age! Thus the next";
    scenes [0][3] = L"scene is foreseen to let us wait a little!";
    scenes [1][0] = L"The spot pointed by the giant is ";
    scenes [1][1] = L"interesting. He lives at a planet full of";
    scenes [1][2] = L"little creatures. Their history written";
    scenes [1][3] = L"in stone script is full of hunger.";
    scenes [2][0] = L"Years after the first Packer presence";
    scenes [2][1] = L"on earth, yet at stone age, at the teeth ";
    scenes [2][2] = L"of continuous evolution,";
    scenes [2][3] = L"the packing process is obvious above!";
    firstMenuSentences [0] = L"I feel your enthusiasm for an involvement,";
    firstMenuSentences [1] = L"yet whether you survive in stone age?! :)";
    firstMenuSentences [2] = L"Well, undecorated involvement";
    firstMenuSentences [3] = L"is also involvement...";
    firstMenuSentences [4] = L"Indeed, tools and decorations are ";
    firstMenuSentences [5] = L"always well appreciated!";
    secondMenuSentences [0] = L"Stones and clubs are available!";
    secondMenuSentences [1] = L"The last one tried to decorate too much,";
    secondMenuSentences [2] = L"it ended up nasty in stone age! :)";
    secondMenuSentences [3] = L"The age is still nasty,";
    secondMenuSentences [4] = L"decoration isn't yet above strength. :)";
    secondMenuSentences [5] = L"A little fashion after so many years!";
    secondMenuSentences [6] = L"Yeah, empty handed decoration! WOW :)";
    secondMenuSentences [7] = L"Pay attention to your nose, ";
    secondMenuSentences [8] = L"knowing decoration isn't important!";
    inRow = 0;
    floatedTo = L"different";

};


void TheNarrator::setArea (CoordinateType area)
{

    startPoints [0] = {short (area.x - 23), short (area.y + 1)};
    startPoints [1] = {short (area.x - 23), short (area.y + 6)};

};


void TheNarrator::setBase (void)
{

    setGetElementId () = &elementID;
    setGetElementName () = &elementName;
    setGetsceneNumber () = &firstInScene;
    setGetElementStartPoint () = startPoints;
    setGetElementRow () = &inRow;
    setGetElementFloat () = &floatedTo;

};


const unsigned char& TheNarrator::get (void)
{

    return currentScene;

};


void TheNarrator::draw (const unsigned short& instance)
{


    // guide of passed argument code:
    // 1: clear four first line
    // 2: clear two last line
    // first digit: element
    // second digit: sphere
    // third digit: sentence

    coordinateType pointOne {startPoints [0]};
    coordinateType pointTwo {startPoints [1]};
    if (instance == 1)
    {
        for (unsigned char i = 0; i < 4; i++)
        {
            colourInserter (L"                                           ", pointOne);
            pointOne.y += 1;
        }
    } else
        if (instance == 2)
        {
            pointOne.y += 5;
            for (unsigned char i = 0; i < 2; i++)
            {
                colourInserter (L"                                           ", pointOne);
                pointOne.y += 1;
            }
        } else
        {
            unsigned char tempOne {0};
            unsigned char tempTwo {0};
            unsigned char tempThree {0};
            tempOne = (instance / 100);
            tempTwo = ((instance % 100) / 10);
            tempThree = ((instance % 100) % 10);
            int rnd {0};

            switch (tempOne)
            {
                case 1:
                    // scenes:
                    for (unsigned char i = 0; i < 4; i++)
                    {
                        colourInserter (scenes [tempTwo][i], colours [0], pointOne);
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
                                    colourInserter (firstMenuSentences [0], colours [1], pointTwo);
                                    pointTwo.y += 1;
                                    colourInserter (firstMenuSentences [1], colours [1], pointTwo);
                                    break;
                                case 2:
                                    colourInserter (firstMenuSentences [2], colours [1], pointTwo);
                                    pointTwo.y += 1;
                                    colourInserter (firstMenuSentences [3], colours [1], pointTwo);
                                    break;
                            }
                        } else
                        {
                            colourInserter (firstMenuSentences [4], colours [1], pointTwo);
                            pointTwo.y += 1;
                            colourInserter (firstMenuSentences [5], colours [1], pointTwo);
                        }
                    } else
                        if (tempTwo == 2)
                        {
                            switch (tempThree)
                            {
                                case 0:
                                    rnd = (rand () % 2 + 1);
                                    if (rnd == 1)
                                        colourInserter (secondMenuSentences [0], colours [1], pointTwo);
                                    else
                                    {
                                        colourInserter (secondMenuSentences [1], colours [1], pointTwo);
                                        pointTwo.y += 1;
                                        colourInserter (secondMenuSentences [2], colours [1], pointTwo);
                                    }
                                    break;
                                case 1:
                                    colourInserter (secondMenuSentences [3], colours [1], pointTwo);
                                    pointTwo.y += 1;
                                    colourInserter (secondMenuSentences [4], colours [1], pointTwo);
                                    break;
                                case 2:
                                    colourInserter (secondMenuSentences [5], colours [1], pointTwo);
                                    break;
                                case 3:
                                    colourInserter (secondMenuSentences [6], colours [1], pointTwo);
                                    break;
                                case 4:
                                    colourInserter (secondMenuSentences [7], colours [1], pointTwo);
                                    pointTwo.y += 1;
                                    colourInserter (secondMenuSentences [8], colours [1], pointTwo);
                                    break;
                            }
                        }
                    break;
            }
        }

};


TheGiant::TheGiant (std::wstring name, coordinateType area) :GameElement::GameElement ()
{

    setBase ();

    title = L"A giant:";
    theGiant [0] = L"                      ;;;;;;";
    theGiant [1] = L"                     ;;;;;;;;";
    theGiant [2] = L"                     ;;;;;;;;";
    theGiant [3] = L"▄";
    theGiant [4] = L"                     ;;▄;;▄;;";
    theGiant [5] = L"▃▃";
    theGiant [6] = L"                     ;;;▃▃;;;";
    theGiant [7] = L"▄▄▄▄";
    theGiant [8] = L"                     ;;▄▄▄▄;;";
    theGiant [9] = L"                      ;;;;;;";
    theGiant [10] = L"                 ;;;;;;;;;;;;;;;                  ;;";
    theGiant [11] = L"                 ;;;;;;;;;;;;;;;;          ;;  ;;;;";
    theGiant [12] = L"                ;;;;;;;;;;;;;;;;;;        ;;;;;;;";
    theGiant [13] = L"♥";
    theGiant [14] = L";;             ;;;;;;;;;;;;♥;;;;;;;       ;;;;";
    theGiant [15] = L" ;;           ;;;;;;;;;;;;;;;;;;;;;;    ;;;;";
    theGiant [16] = L"  ;;         ;;;; ;;;;;;;;;;;;;; ;;;;; ;;;;";
    theGiant [17] = L"  ;;        ;;;;  ;;;;;;;;;;;;;;   ;;;;;;;";
    theGiant [18] = L"   ;;      ;;;;   ;;;;;;;;;;;;;;     ;;;";
    theGiant [19] = L"   ;;     ;;;;    ;;;;;;;;;;;;;;";
    theGiant [20] = L"   ;;    ;;;;      ;;;;;;;;;;;;;";
    theGiant [21] = L"   ;;  ;;;;        ;;;;;;;;;;;;;";
    theGiant [22] = L"  ;;; ;;;;         ;;;;;;;;;;;;;";
    theGiant [23] = L"  ;;;;;;           ;;;;;;;;;;;;;";
    theGiant [24] = L"  ;;;;              ;;;;;;;;;;;;";
    theGiant [25] = L"   ;;               ;;;;;;;;;;;;";
    theGiant [26] = L"   ;;               ;;;;; ;;;;;;";
    theGiant [27] = L"   ;;               ;;;;;  ;;;;;";
    theGiant [28] = L"   ;;               ;;;;;  ;;;;;";
    theGiant [29] = L"   ;;               ;;;;;; ;;;;;";
    theGiant [30] = L"   ;;                ;;;;;;;;;;;";
    theGiant [31] = L"   ;;                 ;;;;;;;;;;";
    theGiant [32] = L"   ;;                    ;;;;;;;;";
    theGiant [33] = L"   ;;                     ;;;;;;;;;;;";
    theGiant [34] = L"   ;;                     ;;;;; ;;;;;;;";
    theGiant [35] = L"   ;;                     ;;;;   ;;;;;";
    theGiant [36] = L"   ;;                    ;;;;;  ;;;;";
    theGiant [37] = L"   ;;                   ;;;;;  ;;;;";
    colourOne = F_bWHITE;
    colourTwo = F_CYAN;
    colourThree = F_bRED;
    sentances [0] = L"\"Look at these new puny two legs creatures!\"";
    sentances [1] = L"\"Look how they dance and chew away!\"";
    startPoints [0] = {2, short (area.y + 10)};
    startPoints [1] = {short (area.x - 30), short (area.y - 24)};

};


void TheGiant::setBase (void)
{

    setGetElementId () = &elementID;
    setGetElementName () = &elementName;
    setGetsceneNumber () = &firstInScene;
    setGetElementStartPoint () = startPoints;
    setGetElementRow () = &inRow;
    setGetElementFloat () = &floatedTo;

};


void TheGiant::draw (void)
{

    coordinateType tempOne (startPoints [0]);
    coordinateType tempTwo (tempOne);
    for (short i = 37; i >= 0; i--)
    {
        if (i == 3)
        {
            tempOne.y += 1;
            tempTwo.y = tempOne.y;
            tempTwo.x = tempOne.x + 23;
            colourInserter (theGiant [i], colourTwo, tempTwo);
            tempTwo.x = tempOne.x + 26;
            colourInserter (theGiant [i], colourTwo, tempTwo);
        } else
            if (i == 5)
            {
                tempOne.y += 1;
                tempTwo.y = tempOne.y;
                tempTwo.x = tempOne.x + 24;
                colourInserter (theGiant [i], colourTwo, tempTwo);
            } else
                if (i == 7)
                {
                    tempOne.y += 1;
                    tempTwo.y = tempOne.y;
                    tempTwo.x = tempOne.x + 23;
                    colourInserter (theGiant [i], colourTwo, tempTwo);
                } else
                    if (i == 13)
                    {
                        tempOne.y += 1;
                        tempTwo.y = tempOne.y;
                        tempTwo.x = tempOne.x + 27;
                        colourInserter (theGiant [i], colourThree, tempTwo);
                    } else
                        colourInserter (theGiant [i], colourOne, tempOne);
                    tempOne.y -= 1;
    }
    coordinateType tempThree (startPoints [1]);
    colourInserter (title, colourTwo, tempThree);
    tempThree.y += 2;
    colourInserter (tempThree);
    std::wstring str {L""};
    for (char element : sentances [0])
    {
        str += element;
        colourInserter (str, colourOne);
        str = L"";
        std::this_thread::sleep_for (std::chrono::milliseconds (50));
    }
    tempThree = startPoints [1];
    tempThree.y += 3;
    colourInserter (tempThree);
    for (char element : sentances [1])
    {
        str += element;
        colourInserter (str, colourOne);
        str = L"";
        std::this_thread::sleep_for (std::chrono::milliseconds (50));
    }

};
