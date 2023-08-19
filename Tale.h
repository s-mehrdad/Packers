
// ===========================================================================
/// <summary>
/// Tale.h
/// Packers
/// created by Mehrdad Soleimanimajd on 01.04.2019
/// </summary>
/// <created>ʆϒʅ, 01.04.2019</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#include "Shared.h"
#include "GameElements.h"


#ifndef TALE_H
#define TALE_H


class TheNarrator : public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    short currentScene;
    std::string title;
#ifdef _WIN32
    WORD colours [2];
#else ifdef __APPLE__
    std::string colours [2];
#endif // _WIN32
    std::string scenes [3][4];
    std::string firstMenuSentences [6];
    std::string secondMenuSentences [9];
    coordinateType startPoints [2];
    short inRow;
    std::string floatedTo;
    //bool inserted;
    //unsigned char counter;
public:
    TheNarrator (std::string elementName);
    void setArea (CoordinateType areaGrid);
    void setBase ();
    const unsigned char& get (void);
    void draw (const unsigned short&);

};


class TheGiant : public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    std::string title;
    std::string theGiant [38];
#ifdef _WIN32
    WORD colourOne;
    WORD colourTwo;
    WORD colourThree;
#else ifdef __APPLE__
    std::string colourOne;
    std::string colourTwo;
    std::string colourThree;
#endif // _WIN32
    std::string sentances [2];
    coordinateType startPoints [2];
    short inRow;
    std::string floatedTo;
public:
    TheGiant (std::string elementName, coordinateType areaGrid);
    void setBase ();
    void draw (void);

};


#endif // !TALE_H
