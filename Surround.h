// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,01.12.2018</changed>
// ********************************************************************************

#pragma once


#ifndef SURROUND_H
#define SURROUND_H


class Surround
{
    struct titleBar;
    struct menus;
    struct guideBar;
    struct statusBar;
    struct loadingBar;
    struct storyLine;
public:
    Surround ( unsigned char );
    void newSetter ( void );

    static void colourInserter ( std::string, WORD, COORD );
    static void menusSetter ( unsigned short, bool );
};


#endif // !SURROUND_H