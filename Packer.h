// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,08.12.2018</changed>
// ********************************************************************************

#pragma once


#ifndef PACKER_H
#define PACKER_H


class Packer
{
    char Sign;
    unsigned short state;
public:
    unsigned char id;
    Packer *address;
    COORD position;
    bool RchanceL;
    unsigned short lastAspiration;
    eventFeed moves [4];
    Packer ( unsigned char );

    static unsigned char count;
    static unsigned char aspirationsSeeds[32];
    static unsigned char aspirations[32];
    static void colourInserter ( std::string, WORD, COORD );
    static void aspirationsSetter (void);
};


#endif // !PACKER_H