﻿// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,19.02.2019</changed>
// ********************************************************************************

#pragma once


#ifndef PACKER_H
#define PACKER_H


class Packer
{
public:
    std::string character { u8"☻" };
    unsigned char id;
    Packer *address;
    COORD position;
    bool RchanceL;
    unsigned short baseState;
    WORD baseMotivation;
    unsigned short lastAspiration;
    struct actions
    {
        unsigned short delay;
        std::string current { };
        actions ()
        {
            delay = 2000;
            current = "NULL";
        }
        actions ( unsigned short speed, unsigned char id ) : delay ( speed )
        {
            std::string signs [4] { u8" ", u8"☻", u8"☺", u8"•" };
            current = signs [id];
        }
        bool operator< ( const actions &a ) const
        {
            return ( delay < a.delay );
        }
    }_action [4];
    Packer ( unsigned char );
    void baseSetter ( void );

    static unsigned char count;
    static unsigned char aspirationsSeeds [32];
    static unsigned char aspirations [32];
    //static void colourInserter ( std::string, WORD, COORD );
    static void aspirationsSetter ( void );
    //TODO add a possible aspiration renew-er for packers (possibly called from surround)
    //TODO add a possible motivation renew-er for packers (possibly called from surround)

};


#endif // !PACKER_H