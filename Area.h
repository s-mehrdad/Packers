// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,26.01.2019</changed>
// ********************************************************************************

#pragma once


#ifndef AREA_H
#define AREA_H


class Area
{
    unsigned char age;
    struct materials;
public:
    Area ( unsigned char );
    void inserter ();

    static const int rows { SCREEN_H - 9 };
    static const int columns { SCREEN_W - 18 };
    static unsigned char stateArray [rows] [columns];
    static void colourInserter ( COORD );
    static void colourInserter ( std::string, WORD );
    static void resourceSetter ( unsigned short, COORD );
};


#endif // !AREA_H