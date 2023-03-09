
// ********************************************************************************
/// <summary>
/// Status.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 09.03.2023</changed>
// ********************************************************************************

#include "Packers.h"
#include "Status.h"


Status::Status(const unsigned char& age, coordinateType area)
{
    state = ".: demo ^.^ :.";
    title = "status ^,^";
    pointState = { short(area.x + 2), 1 };
    pointTitle = { short(area.x + 2), 3 };
    otherString[0] = "packers:";
    otherString[1] = "age:";
    otherString[2] = "resources->";
    otherString[3] = "healthy:";
    otherString[4] = "renewing:";
    otherString[5] = "vanished:";
    otherString[6] = "packages->";
    otherString[7] = "have:";
    otherString[8] = "need:";
    otherPoints[0] = { short(area.x + 4), 5 };
    otherPoints[1] = { short(area.x + 4), 7 };
    otherPoints[2] = { short(area.x + 4), 10 };
    otherPoints[3] = { short(area.x + 4), 12 };
    otherPoints[4] = { short(area.x + 4), 15 };
    otherPoints[5] = { short(area.x + 4), 18 };
    otherPoints[6] = { short(area.x + 4), 21 };
    otherPoints[7] = { short(area.x + 4), 23 };
    otherPoints[8] = { short(area.x + 4), 26 };
    packersState = 0;
    agesIdentifier = age;
    agesStrings[0] = "   Stone";
    agesStrings[1] = "   Middle";
    agesStrings[2] = "   Advanced";
    agesStrings[3] = "   Hollow";
    agesStrings[4] = "   Dirty";
    healthyState = 0;
    renewedState = 0;
    vanishedState = 0;
    haveState = 0;
    needState = 0;


    // game state
    colourInserter(state, F_bWHITE, pointState);


    // statusBar
    colourInserter(title, F_bWHITE, pointTitle);

    coordinateType coordinate{ otherPoints[0] };
    colourInserter(otherString[0], F_bPURPLE, coordinate);
    coordinate.x += 9;
    colourInserter("", F_CYAN, coordinate);

    coordinate = otherPoints[1];
    colourInserter(otherString[1], F_bPURPLE, coordinate);
    coordinate.y += 1;
    colourInserter(agesStrings[agesIdentifier], F_CYAN, coordinate);

    colourInserter(otherString[2], F_bWHITE, otherPoints[2]);
    coordinate = otherPoints[3];
    colourInserter(otherString[3], F_GREEN, coordinate);
    coordinate.x += 3;
    coordinate.y += 1;
    colourInserter("", F_CYAN, coordinate);
    coordinate = otherPoints[4];
    colourInserter(otherString[4], F_YELLOW, coordinate);
    coordinate.x += 3;
    coordinate.y += 1;
    colourInserter("", F_CYAN, coordinate);
    coordinate = otherPoints[5];
    colourInserter(otherString[5], F_bRED, coordinate);
    coordinate.x += 3;
    coordinate.y += 1;
    colourInserter("", F_CYAN, coordinate);

    colourInserter(otherString[6], F_bWHITE, otherPoints[6]);
    coordinate = otherPoints[7];
    colourInserter(otherString[7], F_bPURPLE, coordinate);
    coordinate.x += 3;
    coordinate.y += 1;
    colourInserter("", F_CYAN, coordinate);
    coordinate = otherPoints[8];
    colourInserter(otherString[8], F_bPURPLE, coordinate);
    coordinate.x += 3;
    coordinate.y += 1;
    colourInserter("", F_CYAN, coordinate);
    //TODO add: random need setter
};


void Status::set(const unsigned short& count)
{
    coordinateType coordinate{ otherPoints[0] };
    coordinate.x += 9;
    packersState = count;
    colourInserter("", F_CYAN, coordinate);
}


const unsigned short& Status::get ()
{
    return packersState;
}


void Status::setter(const unsigned char& age)
{
    //TODO add: a set of state setter
    // update complete the state setter
    coordinateType coordinate{ otherPoints[1] };
    coordinate.y += 1;
    colourInserter("            ", F_CYAN, coordinate);
    colourInserter(agesStrings[age], F_CYAN, coordinate);
};


void Status::setPaackersState ( void )
{
    coordinateType coordinate{ otherPoints[0] };
    coordinate.x += 9;
    colourInserter(std::to_string(packersState), F_CYAN, coordinate );
}
