
// ===========================================================================
/// <summary>
/// Shared.h
/// Packers
/// created by Mehrdad Soleimanimajd on 13.10.2018
/// </summary>
/// <created>ʆϒʅ, 13.10.2018</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

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


class Inserter : View
{
private:
#ifdef _WIN32
    const HANDLE* consoleOutput;
    //CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
#else ifdef __APPLE__
#endif // _WIN32
public:
    Inserter ();
    void colourInserter (const coordinateType& coord);
    void colourInserter (const std::string& str, const coordinateType& pos);

#ifdef _WIN32
    void colourInserter (const std::string& str, const WORD& colour);
    void colourInserter (const wchar_t& chr, const WORD& colour, const coordinateType& pos);
    void colourInserter (const std::string& str, const WORD& colour, const coordinateType& pos);

    using View::getConsoleOutput;

#else ifdef __APPLE__
    void colourInserter (const std::string& str, const std::string& colour);
    void colourInserter (const wchar_t& chr, const std::string& colour, const coordinateType& pos);
    void colourInserter (const std::string& str, const std::string& colour, const coordinateType& pos);
#endif // _WIN32

    void clear ();

    static coordinateType lastInsertStartPosition;

};


class Loading :public Inserter
{
private:
    //struct loadingBar;
    std::string characters [9];
    std::string copyWrite;
#ifdef _WIN32
    WORD colourOne;
    WORD colourTwo;
    WORD colourThree;
#else ifdef __APPLE__
    std::string colourOne;
    std::string colourTwo;
    std::string colourThree;
#endif // _WIN32
    coordinateType startPoint;
    unsigned char speed;
public:
    Loading (const unsigned char&, coordinateType areaGrid);
    void inserter (void);
    void setter (const unsigned char&);
};


#endif // !SHARED_H
