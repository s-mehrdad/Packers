
// ********************************************************************************
/// <summary>
/// Packer.h
/// Packers
/// created by Mehrdad Soleimanimajd on 29.09.2018
/// </summary>
/// <created>ʆϒʅ, 29.09.2018</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#ifndef PACKER_H
#define PACKER_H


#include "Shared.h"


struct Actions
{
    std::string action;
    unsigned short delay;
    Actions();
    Actions(const std::string&, const unsigned short&);
};


class Packer :public Inserter
{
private:
    unsigned char id;
    Packer* address;
    std::string faces[2];
    std::string* currentFace; // Todo for use in the tale
    Actions process[4];
    coordinateType position;
    bool direction;
#ifdef _WIN32
    WORD motivation;
#elifdef __APPLE__
    std::string motivation;
#endif
    unsigned char aspiration;
    unsigned char mood;
    //unsigned char advancement;
public:
    Packer(coordinateType areaGrid);
    const unsigned char& getId(void);
    const Actions& getProcess(const unsigned char&);
    coordinateType& getPosition(void);
    bool& getDirection(void);
#ifdef _WIN32
    const WORD& getMotivation(void);
#elifdef __APPLE__
    const std::string& getMotivation(void);
#endif
    const unsigned char& getAspiration(void);
    void involve(const unsigned short&);

    static unsigned char count;
};


#endif // !PACKER_H
