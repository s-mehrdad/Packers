
// ===========================================================================
/// <summary>
/// Infobars.h
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#ifndef INFOBARS_H
#define INFOBARS_H


#include "Shared.h"


class TheTitleBar :public GameElement, Inserter
{
private:
    short elementID;
    std::wstring elementName;

    short firstInScene;
    std::wstring titleSentence;

    coordinateType startPoints [2];
    short inRow;
    std::wstring floatedTo;
public:
    TheTitleBar (coordinateType areaGrid, std::wstring elementName); //parameter: area dimension
    void setBase (void);
    void draw (void);
};


class TheGuideBar :public GameElement, Inserter
{
private:
    short elementID;
    std::wstring elementName;

    short firstInScene;

    std::wstring signs [3];
    std::wstring guides [3];

    coordinateType startPoints [2];
    short inRow;
    std::wstring floatedTo;
public:
    TheGuideBar (coordinateType areaGrid, std::wstring elementName); //parameter: area dimension
    void setBase (void);
    void draw (void);
};


#endif //INFOBARS_H
