// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,23.06.2019</changed>
// ********************************************************************************

#pragma once


#ifndef SHARED_H
#define SHARED_H


void colourInserter ( const COORD& );
void colourInserter ( const std::string&, const WORD& );
void colourInserter ( const std::string&, const COORD& );
void colourInserter ( const std::string&, const WORD&, const COORD& );


class Inserter
{
private:
  HANDLE consoleOutput;
  CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
public:
  Inserter ();
  void colourInserter ( const COORD& );
  void colourInserter ( const std::string&, const WORD& );
  void colourInserter ( const std::string&, const COORD& );
  void colourInserter ( const std::string&, const WORD&, const COORD& );
  void clear ();

  static COORD lastInsertStartPosition;
};


class Loading :public Inserter
{
private:
  //struct loadingBar;
  std::string characters [9];
  std::string copywrite;
  WORD colourOne;
  WORD colourTwo;
  WORD colourThree;
  COORD startPoint;
  unsigned char speed;
public:
  Loading ( const unsigned char& );
  void inserter ( void );
  void setter ( const unsigned char& );
};


#endif // !SHARED_H
