// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,11.06.2022</changed>
// ********************************************************************************

#ifndef SHARED_H
#define SHARED_H


#include "View.h"


typedef struct Position
{
  short x;
  short y;
} coordinateType;


class Inserter :public View
{
private:
  HANDLE consoleOutput;
  CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX;
public:
  Inserter ();
  void colourInserter ( const coordinateType& );
  void colourInserter ( const std::string&, const WORD& );
  void colourInserter ( const std::string&, const coordinateType& );
  void colourInserter ( const std::string&, const WORD&, const coordinateType& );
  void clear ();

  static coordinateType lastInsertStartPosition;
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
  coordinateType startPoint;
  unsigned char speed;
public:
  Loading ( const unsigned char& );
  void inserter ( void );
  void setter ( const unsigned char& );
};


#endif // !SHARED_H
