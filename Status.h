// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,11.06.2022</changed>
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
  Status ( const unsigned char& );
  void get ( const unsigned short& );
  void setter ( const unsigned char& );
};


#endif //STATUS_H
