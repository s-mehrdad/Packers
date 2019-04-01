// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,13.10.2018</created>
/// <changed>ʆϒʅ,01.04.2019</changed>
// ********************************************************************************

#pragma once


#ifndef SHARED_H
#define SHARED_H


class Loading
{
  struct loadingBar;

public:
  Loading ( unsigned char );
  void newSetter ( void );

  static void inserter ( void );
};


#endif // !SHARED_H