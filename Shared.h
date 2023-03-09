
// ********************************************************************************
/// <summary>
/// Shared.h
/// Packers
/// created by Mehrdad Soleimanimajd on 13.10.2018
/// </summary>
/// <created>ʆϒʅ, 13.10.2018</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#ifndef SHARED_H
#define SHARED_H


#include "View.h"


typedef struct CoordinateType
{
    int x;
    int y;
} coordinateType;


//typedef struct PositionType
//{
//  short top;
//  short left;
//} positionType;


class Inserter :public View
{
private:
#ifdef _WIN32
    const HANDLE* insertConsoleOutput;
    //CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
#elifdef __APPLE__
#endif
public:
    Inserter();
    void colourInserter(const coordinateType& coord);
#ifdef _WIN32
    void colourInserter(const std::string& str, const WORD& colour);
#elifdef __APPLE__
    void colourInserter(const std::string& str, const std::string& colour);
#endif
    void colourInserter(const std::string& str, const coordinateType& pos);
#ifdef _WIN32
    void colourInserter(const std::string& str, const WORD& colour, const coordinateType& pos);
#elifdef __APPLE__
    void colourInserter(const std::string& str, const std::string& colour, const coordinateType& pos);
#endif
    void clear();

    static coordinateType lastInsertStartPosition;
};


class Loading :public Inserter
{
private:
    //struct loadingBar;
    std::string characters[9];
    std::string copywrite;
#ifdef _WIN32
    WORD colourOne;
    WORD colourTwo;
    WORD colourThree;
#elifdef __APPLE__
    std::string colourOne;
    std::string colourTwo;
    std::string colourThree;
#endif
    coordinateType startPoint;
    unsigned char speed;
public:
    Loading(const unsigned char&, coordinateType areaGrid);
    void inserter(void);
    void setter(const unsigned char&);
};


#endif // !SHARED_H
