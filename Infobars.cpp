
// ===========================================================================
/// <summary>
/// Infobars.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Infobars.h"


TheTitleBar::TheTitleBar (coordinateType area, std::wstring name)
{

    setBase ();
    elementID = 0;
    elementName = name;

    firstInScene = 2;
    titleSentence = L"Feel free to way in toward becoming an advanced packer! ♥♥♥♥♥ :)";

    startPoints [0] = {short ((area.x / 2) - ((titleSentence.size () - 5) / 2)) + 2, 0}; // center it! :)
    startPoints [1] = {short (titleSentence.size () - 10), 0}; // end of it.
    inRow = 1;
    floatedTo = L"center";

};


void TheTitleBar::setBase (void)
{

    setGetElementId () = &elementID;
    setGetElementName () = &elementName;
    setGetsceneNumber () = &firstInScene;
    setGetElementStartPoint () = startPoints;
    setGetElementRow () = &inRow;
    setGetElementFloat () = &floatedTo;

};


void TheTitleBar::draw (void)
{

    colourInserter (titleSentence, F_CYAN, startPoints [0]);

};


TheGuideBar::TheGuideBar (coordinateType area, std::wstring name)
{

    setBase ();
    elementID = 0;
    elementName = name;

    firstInScene = 2;

    signs [0] = L"♣:";
    signs [1] = L"☻:";
    signs [2] = L".:";
    guides [0] = L" healthy resources";
    guides [1] = L" beloved packers";
    guides [2] = L" ready packages";

    startPoints [0] = {2, short (area.y + 9)};
    startPoints [1] = {short (guides [0].size () + guides [1].size () + guides [2].size () + 2), short (area.y + 11)};
    inRow = 4;
    floatedTo = L"center";

};


void TheGuideBar::setBase (void)
{

    setGetElementId () = &elementID;
    setGetElementName () = &elementName;
    setGetsceneNumber () = &firstInScene;
    setGetElementStartPoint () = startPoints;
    setGetElementRow () = &inRow;
    setGetElementFloat () = &floatedTo;

};


void TheGuideBar::draw (void)
{

    // output
    coordinateType coordinate {startPoints [0]};

    auto temp {guides [0].size () + guides [1].size () + guides [2].size ()};

    // guideBar
    for (char i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            colourInserter (signs [i], F_GREEN, coordinate);
        }
        if (i == 1)
        {
            coordinate.x += (temp / 3) + 3;
            colourInserter (signs [i], F_bWHITE, coordinate);
        }
        if (i == 2)
        {
            coordinate.x += (temp / 3) + 1;
            colourInserter (signs [i], F_bWHITE, coordinate);
        }
        coordinate.x += 2;
        colourInserter (guides [i], F_CYAN, coordinate);
        coordinate.x += 2;

    }

};
