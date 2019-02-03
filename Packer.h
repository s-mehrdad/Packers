// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,03.02.2018</changed>
// ********************************************************************************

#pragma once


#ifndef PACKER_H
#define PACKER_H


struct eventFeed
{
    unsigned short delay;
    std::string str;
    eventFeed ()
    {
        delay = 2000;
        str = "NULL";
    }
    eventFeed ( unsigned short mode, std::string Str ) : delay ( mode ), str ( Str ) {}
    //eventFeed ( unsigned short mode, std::string Str ) :delay ( mode ), str ( Str ) {}

    bool operator< ( const eventFeed &a ) const
    {
        return ( delay < a.delay );
    }
};


class Packer
{
    char Sign;
public:
    unsigned char id;
    Packer *address;
    COORD position;
    bool RchanceL;
    unsigned short baseState;
    WORD baseMotivation;
    unsigned short lastAspiration;
    eventFeed moves [4];
    Packer ( unsigned char );

    static unsigned char count;
    static unsigned char aspirationsSeeds[32];
    static unsigned char aspirations[32];
    static void colourInserter ( std::string, WORD, COORD );
    static void aspirationsSetter (void);
    //TODO add a possible aspiration renew-er for packers (possibly called from surround)
    //TODO add a possible motivation renew-er for packers (possibly called from surround)

};


#endif // !PACKER_H