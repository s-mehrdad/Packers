// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,13.06.2022</changed>
// ********************************************************************************

#ifndef MENUS_H
#define MENUS_H


#include "Shared.h"


class pMenus
{

private:
  coordinateType startPoints [2];
public:
  pMenus ( coordinateType areaGrid ); //parameter: area dimension
  coordinateType* getSetStartPoints (); // get set start points
};


class dangerAreaMenu :public pMenus, Inserter
{
private:
  std::string title;
  std::string options [3];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  //coordinateType startPoints [2];
public:
  dangerAreaMenu ( coordinateType areaGrid ); //parameter: inherited area dimension
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  unsigned char& get ();
};


class agesMenu :public pMenus, Inserter
{
private:
  std::string title;
  std::string options [5];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  //coordinateType startPoints [2];
public:
  agesMenu ( coordinateType areaGrid ); //parameter: inherited area dimension
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


class charactersMenu :public pMenus, Inserter
{
private:
  std::string title;
  std::string options [2];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  //coordinateType startPoints [2];
public:
  charactersMenu ( coordinateType areaGrid ); //parameter: inherited area dimension
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


class motivationsMenu :public pMenus, Inserter
{
private:
  std::string title;
  std::string options [6];
  WORD colours [6];
  std::string selectionSign;
  unsigned char selected;
  bool set { false };
  //coordinateType startPoints [2];
public:
  motivationsMenu ( coordinateType areaGrid ); //parameter: inherited area dimension
  void switcher ();
  void switchSet ( const unsigned char&, const bool& );
  const unsigned char& get ();
};


#endif //MENUS_H
