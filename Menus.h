
// ===========================================================================
/// <summary>
/// Menus.h
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

#ifndef MENUS_H
#define MENUS_H


#include "Shared.h"


class pMenus
{

private:
    coordinateType startPoints [2];

public:
    pMenus (coordinateType areaGrid); //parameter: area dimension
    coordinateType* getSetStartPoints (); // get set start points

    // TODO menu process
    static unsigned char menuState;

};


class dangerAreaMenu :public pMenus, Inserter
{
private:
    std::string title;
    std::string options [3];
    std::string selectionSign;
    unsigned char selected;
    bool set {false};
    //coordinateType startPoints [2];
public:
    dangerAreaMenu (coordinateType areaGrid); //parameter: inherited area dimension
    void switcher (bool isInvolved);
    void switchSet (const unsigned char&, const bool&);
    unsigned char& get ();

};


class agesMenu :public pMenus, Inserter
{
private:
    std::string title;
    std::string options [5];
    std::string selectionSign;
    unsigned char selected;
    bool set {false};
    //coordinateType startPoints [2];
public:
    agesMenu (coordinateType areaGrid); //parameter: inherited area dimension
    void switcher ();
    void switchSet (const unsigned char&, const bool&);
    const unsigned char& get ();

};


class charactersMenu :public pMenus, Inserter
{
private:
    std::string title;
    std::string options [2];
    std::string selectionSign;
    unsigned char selected;
    bool set {false};
    //coordinateType startPoints [2];
public:
    charactersMenu (coordinateType areaGrid); //parameter: inherited area dimension
    void switcher ();
    void switchSet (const unsigned char&, const bool&);
    const unsigned char& get ();

};


class motivationsMenu :public pMenus, Inserter
{
private:
    std::string title;
    std::string options [6];
#ifdef _WIN32
    WORD colours [6];
#else ifdef __APPLE__
    std::string colours [6];
#endif
    std::string selectionSign;
    unsigned char selected;
    bool set {false};
    //coordinateType startPoints [2];
public:
    motivationsMenu (coordinateType areaGrid); //parameter: inherited area dimension
    void switcher ();
    void switchSet (const unsigned char&, const bool&);
    const unsigned char& get ();

};


#endif //MENUS_H
