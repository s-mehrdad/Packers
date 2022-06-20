// ********************************************************************************
/// <summary>
/// 
/// </summary>
/// <created>ʆϒʅ,20.06.2019</created>
/// <changed>ʆϒʅ,20.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Menus.h"


pMenus::pMenus ( coordinateType area )
{

    startPoints [0] = { 5,  short ( area.y + 2 ) };
    startPoints [1] = { 4,  short ( area.y + 3 ) };

};


coordinateType* pMenus::getSetStartPoints ()
{

    return startPoints;

};


dangerAreaMenu::dangerAreaMenu ( coordinateType area ) :pMenus::pMenus ( area )
{
    title = u8"Danger area:";
    options [0] = u8"  Involve me!";
    options [1] = u8"  Let me furnish! :)";
    options [2] = u8"  Let's hit the road!";
    selectionSign = u8"->";
    selected = 0;
    set = false;
    switcher ();
};


void dangerAreaMenu::switcher ()
{
    coordinateType coordinate { *getSetStartPoints () };

    // dangerAreaMenu
    if ( set == false )
    {
        colourInserter ( title, F_bWHITE, coordinate );
        coordinate.y += 1;
        for ( char i = 0; i < 3; i++ )
        {
            colourInserter ( options [i], F_bWHITE, coordinate );
            coordinate.y += 1;
        }
        colourInserter ( selectionSign, F_bRED, *( getSetStartPoints () + 1 ) );
        set = true;
    } else
    {
        coordinate.x -= 1;
        for ( unsigned char i = 0; i <= 3; i++ )
        {
            colourInserter ( u8"                       ", coordinate );
            coordinate.y += 1;
        }
        set = false;
    }
};


void dangerAreaMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
    coordinateType coordinate { 0, 0 };
    unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

    // events of danger area choices
    coordinate = *( getSetStartPoints () + 1 );
    coordinate.y += selected;
    if ( confirm == false )
    {
        colourInserter ( u8"  ", F_bRED, coordinate );
        selected = chosen;
        // Todo aware the narrator! :)
        coordinate = *( getSetStartPoints () + 1 );
        coordinate.y += chosen;
        colourInserter ( selectionSign, F_bRED, coordinate );
    } else
    {

    }
};


unsigned char& dangerAreaMenu::get ()
{
    return selected;
}


agesMenu::agesMenu ( coordinateType area ) :pMenus::pMenus ( area )
{
    title = u8"Packing speed:";
    options [0] = u8"  Stone age.";
    options [1] = u8"  Middle age...";
    options [2] = u8"  Advanced age.........";
    options [3] = u8"  Hollow age.      . .            .";
    options [4] = u8"  Dirty age (packers of packers contest!)";
    selectionSign = u8"->";
    unsigned short selected { 0 };
    bool set { false };
};


void agesMenu::switcher ()
{
    coordinateType coordinate { *getSetStartPoints () };

    // agesMenu
    if ( set == false )
    {
        colourInserter ( title, F_bWHITE, coordinate );
        coordinate.y += 1;
        for ( unsigned char i = 0; i < 5; i++ )
        {
            WORD tmpColour { F_bWHITE };
            if ( i == selected )
                tmpColour = F_bRED;
            colourInserter ( options [i], tmpColour, coordinate );
            coordinate.y += 1;
        }
        selected = 0;
        coordinate = *( getSetStartPoints () + 1 );
        colourInserter ( selectionSign, F_bRED, coordinate );
        set = true;
    } else
    {
        coordinate.x -= 1;
        for ( unsigned char i = 0; i <= 5; i++ )
        {
            colourInserter ( u8"                                           ", coordinate );
            coordinate.y += 1;
        }
        set = false;
    }
};


void agesMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
    coordinateType coordinate { 0, 0 };
    unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

    // events of age choices
    coordinate = *( getSetStartPoints () + 1 );
    coordinate.y += selected;
    if ( confirm == false )
    {
        colourInserter ( u8"  ", F_bRED, coordinate );
        coordinate = *( getSetStartPoints () + 1 );
        coordinate.y += chosen;
        colourInserter ( selectionSign, F_bRED, coordinate );
        selected = chosen;
        switch ( chosen )
        {
        case 0:
            theNarrator.draw ( 2 );
            theNarrator.draw ( 220 );
            break;
        case 1:
            theNarrator.draw ( 2 );
            theNarrator.draw ( 221 );
            break;
        case 2:
            theNarrator.draw ( 2 );
            theNarrator.draw ( 222 );
            break;
        case 3:
            theNarrator.draw ( 2 );
            theNarrator.draw ( 223 );
            break;
        case 4:
            theNarrator.draw ( 2 );
            theNarrator.draw ( 224 );
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


charactersMenu::charactersMenu ( coordinateType area ) :pMenus::pMenus ( area )
{
    title = u8"Character Choices:";
    // two character re-presenter should be enough for the ambitious packers! :)
    options [0] = u8"☻";
    options [1] = u8"☺";
    selectionSign = u8"->";
    selected = 0;
    set = false;
    *getSetStartPoints () = { 5, SCREEN_H - 10 };;
    *( getSetStartPoints () + 1 ) = { 7, SCREEN_H - 9 };
};


void charactersMenu::switcher ()
{
    coordinateType coordinate { *getSetStartPoints () };

    // charactersMenu
    if ( set == false )
    {
        colourInserter ( title, F_bWHITE, coordinate );
        coordinate.x += 5;
        coordinate.y += 1;
        for ( unsigned char i = 0; i < 2; i++ )
        {
            WORD tmpColour { F_bWHITE };
            if ( i == selected )
                tmpColour = F_bRED;
            if ( i == 1 )
                coordinate.x += 7;
            colourInserter ( options [i], tmpColour, coordinate );
        }
        selected = 0;
        colourInserter ( selectionSign, F_bRED, *( getSetStartPoints () + 1 ) );
        set = true;
    } else
    {
        coordinate.x -= 1;
        for ( unsigned char i = 0; i <= 1; i++ )
        {
            colourInserter ( u8"                    ", coordinate );
            coordinate.y += 1;
        }
        set = false;
    }
};


void charactersMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
    coordinateType coordinate { 0, 0 };
    unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

    // events of character choices
    coordinate = *( getSetStartPoints () + 1 );
    if ( selected == 1 )
        coordinate.x += 7;
    if ( confirm == false )
    {
        colourInserter ( u8"  ", F_bRED, coordinate );
        coordinate = *( getSetStartPoints () + 1 );
        if ( chosen == 1 )
            coordinate.x += 7;
        colourInserter ( selectionSign, F_bRED, coordinate );
        selected = chosen;
        // Todo aware the narrator! :)
    } else
    {

    }
};


const unsigned char& charactersMenu::get ()
{
    return selected;
}


motivationsMenu::motivationsMenu ( coordinateType area ) :pMenus::pMenus ( area )
{
    title = u8"A shiny colour is wished!:";
    options [0] = u8"  Independent";
    options [1] = u8"  Green nationalist";
    options [2] = u8"  Red nationalist";
    options [3] = u8"  Not know how";
    options [4] = u8"  Free";
    options [5] = u8"  Neutral";
    colours [0] = F_bCYAN;
    colours [1] = F_bGREEN;
    colours [2] = F_bRED;
    colours [3] = F_bPURPLE;
    colours [4] = F_bYELLOW;
    colours [5] = F_bWHITE;
    selectionSign = u8"->";
    unsigned short selected { 0 };
    bool set { false };
    *getSetStartPoints () = { 5, SCREEN_H - 10 };
    *( getSetStartPoints () + 1 ) = { 4, SCREEN_H - 9 };
};


void motivationsMenu::switcher ()
{
    coordinateType coordinate { *getSetStartPoints () };

    // motivationsMenu
    if ( set == false )
    {
        colourInserter ( title, F_bWHITE, coordinate );
        coordinate.y += 1;
        for ( unsigned char i = 0; i < 6; i++ )
        {
            WORD tmpColour { colours [i] };
            if ( i == selected )
                tmpColour = B_CYAN | colours [i];
            if ( i == 3 )
            {
                coordinate.x += 23;
                coordinate.y -= 3;
            }
            colourInserter ( options [i], tmpColour, coordinate );
            coordinate.y += 1;
        }
        selected = 0;
        coordinate = *( getSetStartPoints () + 1 );
        colourInserter ( selectionSign, F_bRED, coordinate );
        set = true;
    } else
    {
        coordinate.x -= 1;
        for ( unsigned char i = 0; i <= 5; i++ )
        {
            colourInserter ( u8"                                        ", coordinate );
            coordinate.y += 1;
        }
        set = false;
    }
};


void motivationsMenu::switchSet ( const unsigned char& choice, const bool& confirm )
{
    coordinateType coordinate { 0, 0 };
    unsigned int chosen { static_cast<unsigned int>( choice % 10 ) };

    // events of motivation choices
    coordinate = *( getSetStartPoints () + 1 );
    coordinate.y += selected;
    if ( selected > 2 )
    {
        coordinate.x += 23;
        coordinate.y -= 3;
    }
    if ( ( ( selected - chosen ) == 3 ) || ( ( chosen - selected ) == 3 ) )
    {
        if ( confirm == false )
        {
            colourInserter ( u8"  ", F_bRED, coordinate );
            coordinate.x = ( getSetStartPoints () + 1 )->x;
            if ( selected < chosen )
            {
                coordinate.x += 23;

            }
            if ( selected > chosen )
            {
                //coordinate.x -= 23;

            }
            colourInserter ( selectionSign, F_bRED, coordinate );
            selected = chosen;
            // Todo aware the narrator, mentioning that the jump was bigger! :)
        } else
        {

        }
    } else
    {
        if ( confirm == false )
        {
            colourInserter ( u8"  ", F_bRED, coordinate );
            coordinate = *( getSetStartPoints () + 1 );
            coordinate.y += chosen;
            if ( ( selected >= 2 ) && ( chosen != 1 ) )
            {
                coordinate.x += 23;
                if ( ( selected != 5 ) && ( chosen != 0 ) )
                    coordinate.y -= 3;
                if ( ( selected == 5 ) && ( chosen == 4 ) )
                    coordinate.y -= 3;
                if ( ( selected == 3 ) && ( chosen == 2 ) )
                {
                    coordinate.x -= 23;
                    coordinate.y += 3;
                }

            }
            if ( ( selected == 5 ) && ( chosen == 0 ) )
            {
                coordinate.x -= 23;
            }
            if ( ( selected == 0 ) && ( chosen == 5 ) )
            {
                coordinate.x += 23;
                coordinate.y -= 3;
            }
            colourInserter ( selectionSign, F_bRED, coordinate );
            selected = chosen;
            // Todo aware the narrator! :)
        } else
        {

        }
    }

};


const unsigned char& motivationsMenu::get ()
{
    return selected;
}
