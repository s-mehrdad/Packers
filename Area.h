﻿// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,29.06.2019</changed>
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
  const COORD get ( void );

  //static unsigned char stateArray [rows][columns]; // dynamic needed
};


#endif // !AREA_H
