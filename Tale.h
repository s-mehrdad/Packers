// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,23.06.2022</changed>
// ********************************************************************************

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
    WORD colours[2];
    std::string scenes[3][4];
    std::string firstMenuSentences[6];
    std::string secondMenuSentences[9];
    coordinateType startPoints[2];
    short inRow;
    std::string floatedTo;
    //bool inserted;
    //unsigned char counter;
public:
    TheNarrator(std::string elementName);
    void setArea(CoordinateType areaGrid);
    void setBase();
    const unsigned char& get(void);
    void draw(const unsigned short&);
};


class TheGiant : public GameElement, Inserter
{
private:
    short elementID;
    std::string elementName;
    short firstInScene;
    std::string title;
    std::string theGiant[38];
    WORD colourOne;
    WORD colourTwo;
    WORD colourThree;
    std::string sentances[2];
    coordinateType startPoints[2];
    short inRow;
    std::string floatedTo;
public:
    TheGiant(std::string elementName, coordinateType areaGrid);
    void setBase();
    void draw(void);
};


#endif // !TALE_H
