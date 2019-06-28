// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,29.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Packer.h"
#include "Shared.h"
#include "Console.h"


Packer::Packer ( unsigned char quickReSeed )
{
  // rand seed provider + quick reseeding
  std::time_t currentTime { std::chrono::system_clock::to_time_t ( std::chrono::system_clock::now () ) };
  std::time_t* currentTime_ptr { &currentTime };
  srand ( static_cast<unsigned int>( time ( currentTime_ptr ) + quickReSeed * 1.123456789 ) );
  int rnd { 0 };


  id = quickReSeed - 1;
  address = this;
  faces [0] = u8"☻";
  faces [1] = u8"☺";


  //TODO different packer types can be added
  // random face + actions
  rnd = ( rand () % 2 + 1 );
  switch ( rnd )
  {
    case 1:
      currentFace = &faces [0];
      process [1] = { faces [0],DELAY_TWO };
      break;
    case 2:
      currentFace = &faces [1];
      process [1] = { faces [1],DELAY_TWO };
      break;
  }
  process [0] = { u8" ",DELAY_ONE };
  process [2] = { u8".",DELAY_THREE };
  process [3] = { u8" ",DELAY_FOUR };


  // random start position
  do
  {
    position.X = rand () % ( ( SCREEN_W - 18 ) - 3 ) + 3;
    position.Y = rand () % ( ( SCREEN_H - 12 ) - 3 ) + 3;
  } while ( position.X % 2 == 0 || position.Y % 2 == 0 );


  // random direction
  rnd = ( rand () % 1000 + 1 );
  if ( rnd % 2 == 0 )
  {
    direction = true;
  } else
  {
    direction = false;
  }


  // random motivation
  rnd = ( rand () % 6 + 1 );
  switch ( rnd )
  {
    case 1:
      motivation = F_bBLUE; // independent-chewer
      break;
    case 2:
      motivation = F_GREEN; // green-national-chewer
      break;
    case 3:
      motivation = F_RED; // red-national-chewer
      break;
    case 4:
      motivation = F_PURPLE; // not-know-chewer
      break;
    case 5:
      motivation = F_bYELLOW; // free-chewer
      break;
    case 6:
      motivation = F_WHITE; // neutral-chewer
      break;
  }


  // making packer's aspirations ready... :)
  // Todo add: current position consideration
  rnd = rand () % 4 + 1;
  switch ( rnd )
  {
    case 1:
      aspiration = 10;
      break;
    case 2:
      aspiration = 20;
      break;
    case 3:
      aspiration = 30;
      break;
    case 4:
      aspiration = 40;
      break;
  }


  // random state
  //TODO changed (part of smart pants of packers :) )
  rnd = ( rand () % 3 + 1 );
  switch ( rnd )
  {
    case 1:
      mood = 10; // normal
      break;
    case 2:
      mood = 20; // not in the mood
      break;
    case 3:
      mood = 30; // tired
      break;
  }


  // the count of active packers
  count++;


  colourInserter ( *currentFace, motivation, position );
};


unsigned short Packer::count { 0 };
//unsigned char Packer::aspirationsSeeds [32] { 0 };
//unsigned char Packer::aspirations [32] { 10 };


const unsigned char& Packer::getId ( void )
{
  return id;
};


const Actions& Packer::getProcess ( const unsigned char& index )
{
  return process [index];
};


COORD& Packer::getPosition ( void )
{
  return position;
}


bool& Packer::getDirection ( void )
{
  return direction;
};


const WORD& Packer::getMotivation ( void )
{
  return motivation;
};


const unsigned char& Packer::getAspiration ( void )
{
  // Todo aspiration re-newer
  return aspiration;
};


Actions::Actions () { action = "NULL"; delay = 2000; };
Actions::Actions ( std::string str, unsigned short shr )
{
  action = str;
  delay = shr;
};
