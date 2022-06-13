// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,13.06.2022</changed>
// ********************************************************************************

#ifndef STATUS_H
#define STATUS_H


#include "Shared.h"


class Status :public Inserter
{
private:
  std::string state;
  std::string title;
  coordinateType pointState;
  coordinateType pointTitle;
  std::string otherString [9];
  coordinateType otherPoints [9];
  unsigned short packersState;
  unsigned char agesIdentifier;
  std::string agesStrings [5];
  unsigned int healthyState;
  unsigned int renewedState;
  unsigned int vanishedState;
  unsigned int haveState;
  unsigned int needState;
public:
  Status ( const unsigned char& startAge, coordinateType areaGrid ); //parameters: game's start age and area dimension
  void get ( const unsigned short& packersCount );
  void setter ( const unsigned char& selectedAge );
};


#endif //STATUS_H
