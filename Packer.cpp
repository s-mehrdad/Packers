// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,28.01.2019</changed>
// ********************************************************************************

#include "pch.h"
#include "Packer.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Surround.h"


//TODO different packer types can be added
struct eventFeed blinkA ( DELAY_ONE, u8" ", F_bWHITE );
struct eventFeed blinkB ( DELAY_TWO, u8"☻", F_bWHITE );
struct eventFeed packed ( DELAY_THREE, u8"▪", F_bWHITE );
struct eventFeed ready ( DELAY_FOUR, u8"☻", F_bWHITE );


Packer::Packer ( unsigned char quickReSeed )
{
    id = quickReSeed - 1;
    address = this;
    aspirationsSeeds [count] = quickReSeed;
    count++;

    //rand function seed provider + quick reseeding
    srand ( (unsigned int) time ( NULL ) + id );

    //TODO add: change made by packers in their surround
    moves [0] = blinkA;
    moves [1] = blinkB;
    moves [2] = packed;
    moves [3] = ready;

    // random beginning position
    do
    {
        position.X = rand () % ( ( SCREEN_W - 18 ) - 3 ) + 3;
        position.Y = rand () % ( ( SCREEN_H - 11 ) - 3 ) + 3;
    } while ( position.X % 2 == 0 || position.Y % 2 == 0 );
    colourInserter ( u8"☻", F_bWHITE, position );

    // random direction
    int d { 0 };
    d = ( rand () % 499 + 1 );
    if ( d % 2 == 0 )
    {
        RchanceL = true;
    } else
    {
        RchanceL = false;
    }

    // random state
    //TODO can be omitted (going to far for a console game?! :) )
    int s { 0 };
    s = ( rand () % 3 + 1 );
    if ( s == 1 )
        state = 1000; // normal
    if ( s == 2 )
        state = 2000; // not in the mood
    if ( s == 3 )
        state = 3000; // tired

    // making packer's aspirations ready... :)
    lastAspiration = id * 100;
};


unsigned char Packer::count { 0 };
unsigned char Packer::aspirationsSeeds [32] { 0 };
unsigned char Packer::aspirations [32] { 10 };


void Packer::colourInserter ( std::string str, WORD colour, COORD pos )
{
    GetConsoleScreenBufferInfoEx ( consoleOutput, &screenBinfoEX );
    SetConsoleCursorPosition ( consoleOutput, pos );
    SetConsoleTextAttribute ( consoleOutput, colour );
    std::cout << str;
};


void Packer::aspirationsSetter ( void )
{
    unsigned char randomNumber { 0 };
    for ( unsigned char i = 0; i < count; i++ )
    {
        srand ( (unsigned int) time ( NULL ) + aspirationsSeeds [i] );
        randomNumber = rand () % 4 + 1;
        switch ( randomNumber )
        {
            case 1:
                aspirations [i] = 10;
                break;
            case 2:
                aspirations [i] = 20;
                break;
            case 3:
                aspirations [i] = 30;
                break;
            case 4:
                aspirations [i] = 40;
                break;
        }
    }
}