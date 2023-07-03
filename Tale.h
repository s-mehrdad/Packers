
// ===========================================================================
/// <summary>
/// Tale.h
/// Packers
/// created by Mehrdad Soleimanimajd on 01.04.2019
/// </summary>
/// <created>ʆϒʅ, 01.04.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "Shared.h"
#include "GameElements.h"


#ifndef TALE_H
#define TALE_H


class TheNarrator : public GameElement, Inserter
{
private:
    short elementID;
    std::wstring elementName;
    short firstInScene;
    short currentScene;
    std::wstring title;
#ifdef _WIN32
    WORD colours [2];
#else ifdef __APPLE__
    std::wstring colours [2];
#endif // _WIN32
    std::wstring scenes [3][4];
    std::wstring firstMenuSentences [6];
    std::wstring secondMenuSentences [9];
    coordinateType startPoints [2];
    short inRow;
    std::wstring floatedTo;
    //bool inserted;
    //unsigned char counter;
public:
    TheNarrator (std::wstring elementName);
    void setArea (CoordinateType areaGrid);
    void setBase ();
    const unsigned char& get (void);
    void draw (const unsigned short&);

};


class TheGiant : public GameElement, Inserter
{
private:
    short elementID;
    std::wstring elementName;
    short firstInScene;
    std::wstring title;
    std::wstring theGiant [38];
#ifdef _WIN32
    WORD colourOne;
    WORD colourTwo;
    WORD colourThree;
#else ifdef __APPLE__
    std::wstring colourOne;
    std::wstring colourTwo;
    std::wstring colourThree;
#endif // _WIN32
    std::wstring sentances [2];
    coordinateType startPoints [2];
    short inRow;
    std::wstring floatedTo;
public:
    TheGiant (std::wstring elementName, coordinateType areaGrid);
    void setBase ();
    void draw (void);

};


#endif // !TALE_H
