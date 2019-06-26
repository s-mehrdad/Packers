// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,27.06.2019</changed>
// ********************************************************************************

#pragma once


#include "Shared.h"


#ifndef PACKER_H
#define PACKER_H


struct Actions
{
  std::string action;
  unsigned short delay;
  Actions ();
  Actions ( std::string, unsigned short );
};


class Packer :public Inserter
{
private:
  unsigned char id;
  Packer* address;
  std::string faces [2];
  std::string* currentFace; // Todo for use in the tale
  Actions process [4];
  COORD position;
  bool direction;
  WORD motivation;
  unsigned char aspiration;
  unsigned char mood;
  //unsigned char advancement;
public:
  Packer ( unsigned char );
  const unsigned char& getId ( void );
  const Actions& getProcess ( const unsigned char& );
  COORD& getPosition ( void );
  bool& getDirection ( void );
  const WORD& getMotivation ( void );
  const unsigned char& getAspiration ( void );

  static unsigned short count;
};


//class Packer
//{
//private:
//  bool direction;
//public:
//  std::string character { u8"☻" };
//  unsigned char id;
//  Packer* address;
//  COORD position;
//  unsigned short baseState;
//  WORD baseMotivation;
//  unsigned short lastAspiration;
//  struct actions
//  {
//    unsigned short delay;
//    std::string current { };
//    actions ()
//    {
//      delay = 2000;
//      current = "NULL";
//    }
//    actions ( unsigned short speed, unsigned char id ) : delay ( speed )
//    {
//      std::string signs [4] { u8" ", u8"☻", u8"☺", u8"." };
//      current = signs [id];
//    }
//    bool operator< ( const actions& a ) const
//    {
//      return ( delay < a.delay );
//    }
//  }_action [4];
//  Packer ( unsigned char );
//  void baseSetter ( void );
//  bool& get ( void );
//
//  static unsigned char count;
//  static unsigned char aspirationsSeeds [32];
//  static unsigned char aspirations [32];
//  static void aspirationsSetter ( void );
//  //TODO add a possible aspiration renew-er for packers (possibly called from surround)
//  //TODO add a possible motivation renew-er for packers (possibly called from surround)
//
//};


#endif // !PACKER_H
