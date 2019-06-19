// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,06.11.2018</created>
/// <changed>ʆϒʅ,19.06.2019</changed>
// ********************************************************************************

#pragma once


#ifndef SURROUND_H
#define SURROUND_H


class Surround
{
  struct titleBar;
  struct menus;
  struct guideBar;
  struct statusBar;
public:
  Surround ( unsigned char );
  void newSetter ( void );

  static void menusSetter ( const unsigned short&, const bool& );
};


#endif // !SURROUND_H
