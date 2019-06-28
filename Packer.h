// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,29.06.2019</changed>
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


#endif // !PACKER_H
