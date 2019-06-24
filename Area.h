// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,24.06.2019</changed>
// ********************************************************************************

#pragma once


#include "Shared.h"


#ifndef AREA_H
#define AREA_H


class Area : public Inserter
{
private:
  unsigned char age;
  std::string wallH;
  std::string wallV;
  std::string edges [4];
  WORD colourW;
  short rows;
  short columns;
  std::string resources [3];
  WORD colourH;
  WORD colourR;
  WORD colourV;
public:
  Area ( unsigned char );
  void setter ( const unsigned short&, const COORD& );
  const COORD& get ( void );

  //static unsigned char stateArray [rows][columns]; // dynamic needed
};


//class Area
//{
//  struct materials;
//  unsigned char age;
//public:
//  Area ( unsigned char );
//  void inserter ();
//
//  static const int rows { SCREEN_H - 12 };
//  static const int columns { SCREEN_W - 18 };
//  static unsigned char stateArray [rows][columns];
//  static void resourceSetter ( unsigned short, COORD );
//};


#endif // !AREA_H
