
// ===========================================================================
/// <summary>
/// Area.h
/// Packers
/// created by Mehrdad Soleimanimajd on 29.09.2018
/// </summary>
/// <created>ʆϒʅ, 29.09.2018</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#ifndef AREA_H
#define AREA_H


#include "Shared.h"
#include "GameElements.h"


class TheArea : public GameElement, Inserter
{
private:
    short elementID;
    std::wstring elementName;
    short firstInScene;
    unsigned char currentAge;
    std::wstring horizontalWall;
    std::wstring verticalWall;
    std::wstring edges [4];

#ifdef _WIN32
    WORD wallColour;
#else ifdef __APPLE__
    std::wstring wallColour;
#endif // _WIN32

    short rows;
    short columns;
    coordinateType startPoints [2];
    std::wstring resources [3];

#ifdef _WIN32
    WORD healthyColour;
    WORD renewedColour;
    WORD vanishedColour;
#else ifdef __APPLE__
    std::wstring healthyColour;
    std::wstring renewedColour;
    std::string vanishedColour;
#endif // _WIN32

    short inRow;
    std::wstring floatedTo;
public:
    TheArea (unsigned char ageArgument, std::wstring elementName);
    void setBase (void);
    void draw (void);
    void setter (const unsigned short&, const coordinateType&);
    const coordinateType& getDimension (void); //area's dimension

    //static unsigned char stateArray [rows][columns]; // dynamic needed
};


#endif // !AREA_H
