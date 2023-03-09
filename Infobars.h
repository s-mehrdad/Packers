
// ********************************************************************************
/// <summary>
/// Infobars.h
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#ifndef INFOBARS_H
#define INFOBARS_H


#include "Shared.h"


class TheTitleBar :public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    std::string titleSentence;
    coordinateType startPoints [2];
    short inRow;
    std::string floatedTo;
public:
    TheTitleBar ( coordinateType areaGrid, std::string elementName ); //parameter: area dimension
    void setBase ( void );
    void draw ( void );
};


class TheGuideBar :public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    std::string titleSentence;
    std::string signs [3];
    std::string guides [3];
    coordinateType startPoints [2];
    short inRow;
    std::string floatedTo;
public:
    TheGuideBar ( coordinateType areaGrid, std::string elementName ); //parameter: area dimension
    void setBase ( void );
    void draw ( void );
};


#endif //INFOBARS_H
