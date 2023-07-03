
// ===========================================================================
/// <summary>
/// Menus.cpp
/// Packers
/// created by Mehrdad Soleimanimajd on 20.06.2019
/// </summary>
/// <created>ʆϒʅ, 20.06.2019</created>
/// <changed>ʆϒʅ, 03.07.2023</changed>
// ===========================================================================

#include "Packers.h"
#include "Menus.h"


pMenus::pMenus (coordinateType area)
{


    startPoints [0] = {2,  short (area.y + 1)};
    startPoints [1] = {3,  short (area.y + 2)};

};


unsigned char pMenus::menuState = 0;


coordinateType* pMenus::getSetStartPoints ()
{

    return startPoints;

};


dangerAreaMenu::dangerAreaMenu (coordinateType area) :pMenus::pMenus (area)
{

    title = L"Danger area:";
    options [0] = L"  Involve me!";
    options [1] = L"  Let me furnish! :)";
    options [2] = L"  Let's hit the road!";
    selectionSign = L"->";
    selected = 0;
    set = false;
    switcher (false);

};


void dangerAreaMenu::switcher (bool involved)
{

    coordinateType coordinateOne {*getSetStartPoints ()};
    coordinateType coordinateTwo {*(getSetStartPoints () + 1)};

    // dangerAreaMenu
    if (set == false)
    {
        colourInserter (title, F_bWHITE, coordinateOne);
        coordinateOne.y += 1;
        for (char i = 0; i < 3; i++)
        {
            //coordinateOne.x -= 3;
            colourInserter (L"                                           ", coordinateOne);
            //coordinateOne.x += 3;
            colourInserter (options [i], F_bWHITE, coordinateOne);
            coordinateOne.y += 1;
        }
        coordinateTwo.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinateTwo);
        set = true;
    } else
    {
        if (involved)
        {
            //coordinateOne.x -= 3;
            colourInserter (L"                                           ", coordinateOne);
            for (unsigned char i = 0; i < 3; i++)
            {
                coordinateOne.y += 1;
                switch (i)
                {
                    case 0:
                        colourInserter (L"For now you can be just a nature lover! ^.^", coordinateOne);
                        break;
                    case 1:
                        colourInserter (L"This is a demo representing the idea. ^,^", coordinateOne);
                        break;
                    case 2:
                        colourInserter (L"Please press ESC to end your try.", coordinateOne);
                        break;
                }
            }
        } else
        {
            coordinateOne.x -= 1;
            for (unsigned char i = 0; i <= 3; i++)
            {
                colourInserter (L"                                           ", coordinateOne);
                coordinateOne.y += 1;
            }

        }
        set = false;
    }

};


void dangerAreaMenu::switchSet (const unsigned char& choice, const bool& confirm)
{

    coordinateType coordinate {0, 0};
    unsigned int chosen {static_cast<unsigned int>(choice % 10)};

    // events of danger area choices
    coordinate = *(getSetStartPoints () + 1);
    coordinate.y += selected;
    coordinate.x -= 2;
    if (confirm == false)
    {
        colourInserter (L"  ", F_bRED, coordinate);
        selected = chosen;
        // TODO aware the narrator! :)
        coordinate = *(getSetStartPoints () + 1);
        coordinate.y += chosen;
        coordinate.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinate);
    } else
    {

    }

};


unsigned char& dangerAreaMenu::get ()
{

    return selected;
}


agesMenu::agesMenu (coordinateType area) :pMenus::pMenus (area)
{

    title = L"Packing speed:";
    options [0] = L"  Stone age.";
    options [1] = L"  Middle age...";
    options [2] = L"  Advanced age.........";
    options [3] = L"  Hollow age.      . .            .";
    options [4] = L"  Dirty age (packers of packers contest!)";
    selectionSign = L"->";
    unsigned short selected {0};
    bool set {false};

};


void agesMenu::switcher ()
{

    coordinateType coordinate {*getSetStartPoints ()};

    // agesMenu
    if (set == false)
    {
        colourInserter (title, F_bWHITE, coordinate);
        coordinate.y += 1;
        for (unsigned char i = 0; i < 5; i++)
        {
#ifdef _WIN32
            WORD tmpColour {F_bWHITE};
#else ifdef __APPLE__
            std::wstring tmpColour {F_bWHITE};
#endif
            if (i == selected)
                tmpColour = F_bRED;
            colourInserter (options [i], tmpColour, coordinate);
            coordinate.y += 1;
        }
        selected = 0;
        coordinate = *(getSetStartPoints () + 1);
        coordinate.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinate);
        set = true;
    } else
    {
        coordinate.x -= 1;
        for (unsigned char i = 0; i <= 5; i++)
        {
            colourInserter (L"                                           ", coordinate);
            coordinate.y += 1;
        }
        set = false;
    }

};


void agesMenu::switchSet (const unsigned char& choice, const bool& confirm)
{

    coordinateType coordinate {0, 0};
    unsigned int chosen {static_cast<unsigned int>(choice % 10)};

    // events of age choices
    coordinate = *(getSetStartPoints () + 1);
    coordinate.y += selected;
    coordinate.x -= 2;
    if (confirm == false)
    {
        colourInserter (L"  ", F_bRED, coordinate);
        coordinate = *(getSetStartPoints () + 1);
        coordinate.y += chosen;
        coordinate.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinate);
        selected = chosen;
        switch (chosen)
        {
            case 0:
                theNarrator.draw (2);
                theNarrator.draw (220);
                break;
            case 1:
                theNarrator.draw (2);
                theNarrator.draw (221);
                break;
            case 2:
                theNarrator.draw (2);
                theNarrator.draw (222);
                break;
            case 3:
                theNarrator.draw (2);
                theNarrator.draw (223);
                break;
            case 4:
                theNarrator.draw (2);
                theNarrator.draw (224);
                break;
        }
    } else
    {

    }

};


const unsigned char& agesMenu::get ()
{

    return selected;
}


charactersMenu::charactersMenu (coordinateType area) :pMenus::pMenus (area)
{

    title = L"Character Choices:";
    // two character re-presenter should be enough for the ambitious packers! :)
    options [0] = L"☻";
    options [1] = L"☺";
    selectionSign = L"->";
    selected = 0;
    set = false;
    //*getSetStartPoints () = { 5, SCREEN_H - 10 };;
    //*( getSetStartPoints () + 1 ) = { 7, SCREEN_H - 9 };

};


void charactersMenu::switcher ()
{

    coordinateType coordinateOne {*getSetStartPoints ()};

    // charactersMenu
    if (set == false)
    {
        colourInserter (title, F_bWHITE, coordinateOne);
        coordinateOne.x += 2;
        coordinateOne.y += 1;
        for (unsigned char i = 0; i < 2; i++)
        {
#ifdef _WIN32
            WORD tmpColour {F_bWHITE};
#else ifdef __APPLE__
            std::wstring tmpColour {F_bWHITE};
#endif
            if (i == selected)
                tmpColour = F_bRED;
            if (i == 1)
                coordinateOne.x += 7;
            colourInserter (options [i], tmpColour, coordinateOne);
        }
        selected = 0;
        coordinateType coordinateTwo {*(getSetStartPoints () + 1)};
        coordinateTwo.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinateTwo);
        set = true;
    } else
    {
        coordinateOne.x -= 1;
        for (unsigned char i = 0; i <= 1; i++)
        {
            colourInserter (L"                    ", coordinateOne);
            coordinateOne.y += 1;
        }
        set = false;
    }

};


void charactersMenu::switchSet (const unsigned char& choice, const bool& confirm)
{

    coordinateType coordinate {0, 0};
    unsigned int chosen {static_cast<unsigned int>(choice % 10)};

    // events of character choices
    coordinate = *(getSetStartPoints () + 1);
    coordinate.x -= 2;
    if (selected == 1)
        coordinate.x += 7;
    if (confirm == false)
    {
        colourInserter (L"  ", F_bRED, coordinate);
        coordinate = *(getSetStartPoints () + 1);
        coordinate.x -= 2;
        if (chosen == 1)
            coordinate.x += 7;
        colourInserter (selectionSign, F_bRED, coordinate);
        selected = chosen;
        // TODO aware the narrator! :)
    } else
    {

    }

};


const unsigned char& charactersMenu::get ()
{

    return selected;
}


motivationsMenu::motivationsMenu (coordinateType area) :pMenus::pMenus (area)
{

    title = L"A shiny colour is wished!:";
    options [0] = L"  Independent";
    options [1] = L"  Green nationalist";
    options [2] = L"  Red nationalist";
    options [3] = L"  Not know how";
    options [4] = L"  Free";
    options [5] = L"  Neutral";
    colours [0] = F_bCYAN;
    colours [1] = F_bGREEN;
    colours [2] = F_bRED;
    colours [3] = F_bPURPLE;
    colours [4] = F_bYELLOW;
    colours [5] = F_bWHITE;
    selectionSign = L"->";
    unsigned short selected {0};
    bool set {false};
    //*getSetStartPoints () = { 5, SCREEN_H - 10 };
    //*( getSetStartPoints () + 1 ) = { 4, SCREEN_H - 9 };

};


void motivationsMenu::switcher ()
{

    coordinateType coordinate {*getSetStartPoints ()};
#ifdef _WIN32
    WORD tmpColour {0};
#else ifdef __APPLE__
    std::wstring tmpColour {""};
#endif

    // motivationsMenu
    if (set == false)
    {
        colourInserter (title, F_bWHITE, coordinate);
        coordinate.y += 1;
        for (unsigned char i = 0; i < 6; i++)
        {
            if (i == selected)
            {
#ifdef _WIN32
                tmpColour = B_bCYAN | colours [i];
#else ifdef __APPLE__
                tmpColour = B_bCYAN + colours [i];
#endif
            } else
            {
#ifdef _WIN32
                tmpColour = colours [i];
#else ifdef __APPLE__
                tmpColour = B_BLACK + colours [i];
#endif
            }
            if (i == 3)
            {
                coordinate.x += 23;
                coordinate.y -= 3;
            }
            colourInserter (options [i], tmpColour, coordinate);
            coordinate.y += 1;
        }
        selected = 0;
        coordinate = *(getSetStartPoints () + 1);
        coordinate.x -= 2;
        colourInserter (selectionSign, F_bRED, coordinate);
        set = true;
    } else
    {
        coordinate.x -= 1;
        for (unsigned char i = 0; i <= 5; i++)
        {
            colourInserter (L"                                        ", coordinate);
            coordinate.y += 1;
        }
        set = false;
    }

};


void motivationsMenu::switchSet (const unsigned char& choice, const bool& confirm)
{

    coordinateType coordinate {0, 0};
    unsigned int chosen {static_cast<unsigned int>(choice % 10)};

    // events of motivation choices
    coordinate = *(getSetStartPoints () + 1);
    coordinate.y += selected;
    coordinate.x -= 2;
    if (selected > 2)
    {
        coordinate.x += 23;
        coordinate.y -= 3;
    }
    if (((selected - chosen) == 3) || ((chosen - selected) == 3))
    {
        if (confirm == false)
        {
            colourInserter (L"  ", F_bRED, coordinate);
            coordinate.x = (getSetStartPoints () + 1)->x;
            coordinate.x -= 2;
            if (selected < chosen)
            {
                coordinate.x += 23;

            }
            if (selected > chosen)
            {
                //coordinate.x -= 23;

            }
            colourInserter (selectionSign, F_bRED, coordinate);
            selected = chosen;
            // TODO aware the narrator, mentioning that the jump was bigger! :)
        } else
        {

        }
    } else
    {
        if (confirm == false)
        {
            colourInserter (L"  ", F_bRED, coordinate);
            coordinate = *(getSetStartPoints () + 1);
            coordinate.y += chosen;
            coordinate.x -= 2;
            if ((selected >= 2) && (chosen != 1))
            {
                coordinate.x += 23;
                if ((selected != 5) && (chosen != 0))
                    coordinate.y -= 3;
                if ((selected == 5) && (chosen == 4))
                    coordinate.y -= 3;
                if ((selected == 3) && (chosen == 2))
                {
                    coordinate.x -= 23;
                    coordinate.y += 3;
                }

            }
            if ((selected == 5) && (chosen == 0))
            {
                coordinate.x -= 23;
            }
            if ((selected == 0) && (chosen == 5))
            {
                coordinate.x += 23;
                coordinate.y -= 3;
            }
            colourInserter (selectionSign, F_bRED, coordinate);
            selected = chosen;
            // TODO aware the narrator! :)
        } else
        {

        }
    }

};


const unsigned char& motivationsMenu::get ()
{

    return selected;
}
