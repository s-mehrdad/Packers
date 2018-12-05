// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,01.12.2018</changed>
// ********************************************************************************

#pragma once


#ifndef PACKER_H
#define PACKER_H


class Packer
{
    char Sign;
    unsigned char id;
    unsigned short state;
public:
    Packer *address;
    COORD position;
    bool RchanceL;
    eventFeed moves [4];
    Packer ( unsigned char );

    static unsigned char count;
    static void colourInserter ( std::string, WORD, COORD );
};


#endif // !PACKER_H