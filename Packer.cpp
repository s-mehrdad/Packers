// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,27.06.2019</changed>
// ********************************************************************************

//#include "pch.h"
#include "Packers.h"
#include "Packer.h"
//#include "Area.h"
//#include "Infobars.h"
//#include "Menus.h"
//#include "Status.h"
//#include "Surround.h"
//#include "Tale.h"
#include "Shared.h"
#include "Console.h"


Packer::Packer ( unsigned char quickReSeed )
{
  // rand seed provider + quick reseeding
  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 5.5 ) );
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
      mood = 1000; // normal
      break;
    case 2:
      mood = 2000; // not in the mood
      break;
    case 3:
      mood = 3000; // tired
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


//Packer::Packer ( unsigned char quickReSeed )
//{
//  id = quickReSeed - 1;
//  address = this;
//  aspirationsSeeds [count] = quickReSeed;
//  count++;
//
//
//  //rand function seed provider + quick reseeding
//  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 50.5 ) );
//
//  //TODO different packer types can be added
//  // random character
//  int c { 0 };
//  c = ( rand () % 2 + 1 );
//  if ( c == 1 )
//    character = u8"☻";
//  else
//    character = u8"☺";
//
//  if ( character == u8"☻" )
//  {
//    _action [0] = { DELAY_ONE, 0 };
//    _action [1] = { DELAY_TWO, 1 };
//    _action [2] = { DELAY_THREE, 3 };
//    _action [3] = { DELAY_FOUR, 0 };
//  } else
//  {
//    _action [0] = { DELAY_ONE, 0 };
//    _action [1] = { DELAY_TWO, 2 };
//    _action [2] = { DELAY_THREE, 3 };
//    _action [3] = { DELAY_FOUR, 0 };
//  }
//
//
//  //rand function seed provider + quick reseeding
//  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 55.5 ) );
//
//  // random beginning position
//  do
//  {
//    position.X = rand () % ( ( SCREEN_W - 18 ) - 3 ) + 3;
//    position.Y = rand () % ( ( SCREEN_H - 12 ) - 3 ) + 3;
//  } while ( position.X % 2 == 0 || position.Y % 2 == 0 );
//
//
//  //rand function seed provider + quick reseeding
//  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 60.5 ) );
//
//  // random direction
//  int d { 0 };
//  d = ( rand () % 1000 + 1 );
//  if ( d % 2 == 0 )
//  {
//    direction = true;
//  } else
//  {
//    direction = false;
//  }
//
//
//  //rand function seed provider + quick reseeding
//  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 65.5 ) );
//
//  // random state
//  //TODO changed (part of smart pants of packers :) )
//  int s { 0 };
//  s = ( rand () % 3 + 1 );
//  if ( s == 1 )
//    baseState = 1000; // normal
//  if ( s == 2 )
//    baseState = 2000; // not in the mood
//  if ( s == 3 )
//    baseState = 3000; // tired
//
//
//// making packer's aspirations ready... :)
//  lastAspiration = id * 100;
//
//
//  //rand function seed provider + quick reseeding
//  srand ( ( unsigned int) time ( NULL ) + static_cast<long>( quickReSeed * 70.5 ) );
//
//  // random motivation
//  int m { 0 };
//  m = ( rand () % 6 + 1 );
//  if ( m == 1 )
//    baseMotivation = F_bBLUE; // independent-chewer
//  if ( m == 2 )
//    baseMotivation = F_GREEN; // green-national-chewer
//  if ( m == 3 )
//    baseMotivation = F_RED; // red-national-chewer
//  if ( m == 4 )
//    baseMotivation = F_PURPLE; // not-know-chewer
//  if ( m == 5 )
//    baseMotivation = F_bYELLOW; // free-chewer
//  if ( m == 6 )
//    baseMotivation = F_WHITE; // neutral-chewer
//
//
//  baseSetter ();
//};
//
//
//unsigned char Packer::count { 0 };
//unsigned char Packer::aspirationsSeeds [32] { 0 };
//unsigned char Packer::aspirations [32] { 10 };
//
//
//void Packer::baseSetter ( void )
//{
//  colourInserter ( character, baseMotivation, position );
//};
//
//
//bool& Packer::get ( void )
//{
//  return direction;
//};
//
//
//void Packer::aspirationsSetter ( void )
//{
//  unsigned char randomNumber { 0 };
//  for ( unsigned char i = 0; i < count; i++ )
//  {
//    srand ( ( unsigned int) time ( NULL ) + aspirationsSeeds [i] );
//    randomNumber = rand () % 4 + 1;
//    switch ( randomNumber )
//    {
//      case 1:
//        aspirations [i] = 10;
//        break;
//      case 2:
//        aspirations [i] = 20;
//        break;
//      case 3:
//        aspirations [i] = 30;
//        break;
//      case 4:
//        aspirations [i] = 40;
//        break;
//    }
//  }
//}
