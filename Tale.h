// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,01.04.2019</created>
/// <changed>ʆϒʅ,11.06.2022</changed>
// ********************************************************************************

#include "Shared.h"


#ifndef TALE_H
#define TALE_H


class Narrator : public Inserter
{
private:
  std::string title;
  WORD colours [2];
  std::string scenes [3][3];
  unsigned char currentScene;
  std::string firstMenuSentences [4];
  std::string secondMenuSentences [8];
  coordinateType startPoints [2];
  //bool inserted;
  //unsigned char counter;
public:
  Narrator ();
  void insertion ( const unsigned short& );
  const unsigned char& get ( void );
};


class Giant : public Inserter
{
private:
  std::string title;
  std::string theGiant [38];
  WORD colourOne;
  WORD colourTwo;
  WORD colourThree;
  std::string sentances [2];
  coordinateType startPoints [2];
public:
  Giant ();
};


#endif // !TALE_H
