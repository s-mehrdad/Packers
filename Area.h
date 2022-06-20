// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#ifndef AREA_H
#define AREA_H


#include "Shared.h"
#include "GameElements.h"


class TheArea : public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    unsigned char currentAge;
    std::string horizontalWall;
    std::string verticalWall;
    std::string edges [4];
    WORD wallColour;
    short rows;
    short columns;
    coordinateType startPoints [2];
    std::string resources [3];
    WORD healthyColour;
    WORD renewedColour;
    WORD vanishedColour;
    short inRow;
    std::string floatedTo;
public:
    TheArea ( unsigned char ageArgument, std::string elementName );
    void setBase ( void );
    void draw ( void );
    void setter ( const unsigned short&, const coordinateType& );
    const coordinateType& getDimension ( void ); //area's dimension

    //static unsigned char stateArray [rows][columns]; // dynamic needed
};


#endif // !AREA_H
