// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,13.11.2018</changed>
// ********************************************************************************

#pragma once


#ifndef AREA_H
#define AREA_H


class Area {
  int rows;
  int columns;
  struct materials;
public:
  Area (unsigned char);
  static void green (COORD);
  static void yellow (COORD);
  static void red (COORD);
  void fullPacked ();
};


#endif // !AREA_H