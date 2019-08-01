// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,24.07.2019</changed>
// ********************************************************************************

#include "Shared.h"


#ifndef PACKER_H
#define PACKER_H


struct Actions
{
  std::string action;
  unsigned short delay;
  Actions ();
  Actions ( const std::string&, const unsigned short& );
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
  Packer ();
  const unsigned char& getId ( void );
  const Actions& getProcess ( const unsigned char& );
  COORD& getPosition ( void );
  bool& getDirection ( void );
  const WORD& getMotivation ( void );
  const unsigned char& getAspiration ( void );
  void involve ( const unsigned short& );

  static unsigned char count;
};


#endif // !PACKER_H
