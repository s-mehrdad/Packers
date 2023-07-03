
// ===========================================================================
/// <summary>
/// GameElements.h
/// Packers
/// created by Mehrdad Soleimanimajd on 14.06.2022
/// </summary>
/// <created>ʆϒʅ, 14.06.2022</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#ifndef GAMEELEMENTS_H
#define GAMEELEMENTS_H


#include "Shared.h"


class GameElement
{
private:
    short* elementID;
    std::wstring* elementName;

    short* sceneNumber;

    coordinateType* elementStartPoint;
    short* elementRow;
    std::wstring* elementFloat; //left, center, right, stretchedH, stretchedV, different
public:
    GameElement (void);
    GameElement* setGet (void);
    void setElementId (short& elementID);
    short*& setGetElementId (void);
    std::wstring*& setGetElementName (void);
    short*& setGetsceneNumber (void);
    coordinateType*& setGetElementStartPoint (void);
    short*& setGetElementRow (void);
    std::wstring*& setGetElementFloat (void);
    void release (void);

    virtual void draw (void) {};
    virtual void draw (const unsigned short&) {};
};


class GameElements
{
private:
    GameElement* gameElements [20];
    //short setElement;
    short elementsCount;
    short paddingShort;
    short paddingMedium;
    short paddingLong;
public:
    GameElements (void);
    void release (void);

    void set (GameElement*);
    GameElement& get (short& elementID);
};


#endif // !GAMEELEMENTS_H
