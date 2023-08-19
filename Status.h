
// ===========================================================================
/// <summary>
/// Status.h
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 19.08.2023</changed>
// ===========================================================================

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
    Status (const unsigned char& startAge, coordinateType areaGrid); //parameters: game's start age and area dimension
    void set (const unsigned short& packersCount);
    const unsigned short& get (void);
    void setPackersState (void);
    void setter (const unsigned char& selectedAge);
};


#endif //STATUS_H
