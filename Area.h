// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,26.11.2018</changed>
// ********************************************************************************

#pragma once


#ifndef AREA_H
#define AREA_H


class Area {
  int rows;
  int columns;
  struct materials;
public:
  Area (unsigned char, unsigned char, unsigned char);
  static void green (COORD);
  static void yellow (COORD);
  static void red (COORD);
  void fullPacked ();

  static void colourInserter (COORD);
  static void colourInserter (std::string, WORD);
};


#endif // !AREA_H