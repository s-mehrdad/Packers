// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,18.06.2019</changed>
// ********************************************************************************

#pragma once


#ifndef SHARED_H
#define SHARED_H


class Inserter
{
public:
  Inserter ();

  static COORD currentPosition;
  static HANDLE consoleOutput;
  static CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
  static void colourInserter ( const COORD& );
  static void colourInserter ( const std::string&, const WORD& );
  static void colourInserter ( const std::string&, const COORD& );
  static void colourInserter ( const std::string&, const WORD&, const COORD& );
};


class Loading
{
  struct loadingBar;

public:
  Loading ( unsigned char );
  void newSetter ( unsigned char );

  //static void inserter ( void );
  static void clear ( unsigned char );
};


#endif // !SHARED_H
