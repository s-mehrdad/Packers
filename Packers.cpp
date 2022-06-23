// ********************************************************************************
/// <summary>
/// nerd Snow's sayings!
/// Programming is patience and practical practice.
/// A needed thing needs to get its done upon itself! :)
// I still remember the begin of this project, as I created the first interface of the program,
// I thought I probably need another platform to create all the funny characters, the famous packers obviously, again,
// then at some point afterward I came to decision,
// that I am exactly at the right way to create probably a new platform for games by using just characters.
// The characters can represent the human's character simply and honestly! ^.^
/// </summary>
/// <created>ʆϒʅ,29.09.2018</created>
/// <changed>ʆϒʅ,23.06.2022</changed>
// ********************************************************************************

#include "Packers.h"
#include "Area.h"
#include "Infobars.h"
#include "Menus.h"
#include "Packer.h"
#include "Status.h"
#include "Tale.h"
#include "View.h"
#include "GameElements.h"
#include "Input.h"
#include "Shared.h"


bool runningOne{ true };
bool runningTwo{ true };
unsigned char menuState{ 10 };
bool involved{ false };
TheNarrator theNarrator(u8"theNarrator");

int main()
{

    //View.h
    View screen;
    screen.setView(CP_UTF8, true);
    screen.setScreen(SCREEN_W, SCREEN_H, SCREEN_L, SCREEN_T);
    screen.setFont(FONT_NAME, FONT_SIZEx, FONT_SIZEy, F_bPURPLE);

    //Input.h
    TheInput theInput;

    // Shared.h
    Inserter insert;
    insert.clear();

    GameElements gameElements;

    // Area.h
    TheArea areaOne(0, u8"areaOne");
    gameElements.set(&areaOne);
    coordinateType areaDimension{ areaOne.getDimension() };

    // Tale.h
    theNarrator.setArea(areaDimension);

    TheGiant theGiant(u8"theGiant", areaDimension);
    gameElements.set(&theGiant);
    gameElements.get(*theGiant.setGetElementId()).draw();
    //theGiant.draw ();

    gameElements.set(&theNarrator);
    gameElements.get(*theNarrator.setGetElementId()).draw(100);
    //theNarrator.draw(100);

    // Shared.h
    Loading loader(LOAD_ONE, areaDimension);
    loader.clear();

    // Area.h
    gameElements.get(*areaOne.setGetElementId()).draw();


    // Infobars.h
    TheTitleBar theTitleBar(areaDimension, u8"theTitleBar");
    gameElements.set(&theTitleBar);
    gameElements.get(*theTitleBar.setGetElementId()).draw();
    TheGuideBar theGuideBar(areaDimension, u8"theGuideBar");
    gameElements.set(&theGuideBar);
    gameElements.get(*theGuideBar.setGetElementId()).draw();

    // Shared.h
    loader.setter(LOAD_ONE);


#pragma region pacKers

    // Packer.h
    // packers list
    Packer* allPackersList[]
    { new (std::nothrow) Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension),
    new (std::nothrow)Packer(areaDimension), };
    Packer* involvedOne{ nullptr };

#pragma endregion

    //1.contain all and genetic

    /*2.independent container*/ //! no redraw

    if (allPackersList != nullptr)
    {

        // Status.h
        Status state(0, areaDimension);
        state.get(Packer::count);

        // Menus.h
        dangerAreaMenu menuOne(areaDimension);
        agesMenu menuTwo(areaDimension);
        charactersMenu menuThree(areaDimension);
        motivationsMenu menuFour(areaDimension);


        // platform game engine:
        unsigned char index{ 0 };
        unsigned short temp{ 0 };
        unsigned int counter{ 0 };
        do
        {

#pragma region Menus

            // 10 to 12 represents the options of dangerAreaMenu
            // 20 to 24 represents the options of agesMenu
            // 30 to 31 represents the options of charactersMenu
            // 40 to 46 represents the options of motivationsMenu
            if ((counter % 1000000) == 0)
            {
                theInput.inputProcessInput();

                if (theInput.getProcess())
                {

                    if (GetAsyncKeyState(VK_DOWN))
                    {
                        switch (menuState)
                        {
                        case 10:
                        case 11:
                            menuState += 1;
                            menuOne.switchSet(menuState, false);
                            break;
                        case 12:
                            menuState -= 2;
                            menuOne.switchSet(menuState, false);
                            break;
                        case 20:
                        case 21:
                        case 22:
                        case 23:
                            menuState += 1;
                            menuTwo.switchSet(menuState, false);
                            break;
                        case 24:
                            menuState -= 4;
                            menuTwo.switchSet(menuState, false);
                            break;
                        case 40:
                        case 41:
                        case 42:
                        case 43:
                        case 44:
                            menuState += 1;
                            menuFour.switchSet(menuState, false);
                            break;
                        case 45:
                            menuState -= 5;
                            menuFour.switchSet(menuState, false);
                            break;
                        }
                    }

                    if (GetAsyncKeyState(VK_UP))
                    {
                        switch (menuState)
                        {
                        case 10:
                            menuState += 2;
                            menuOne.switchSet(menuState, false);
                            break;
                        case 11:
                        case 12:
                            menuState -= 1;
                            menuOne.switchSet(menuState, false);
                            break;
                        case 20:
                            menuState += 4;
                            menuTwo.switchSet(menuState, false);
                            break;
                        case 21:
                        case 22:
                        case 23:
                        case 24:
                            menuState -= 1;
                            menuTwo.switchSet(menuState, false);
                            break;
                        case 40:
                            menuState += 5;
                            menuFour.switchSet(menuState, false);
                            break;
                        case 41:
                        case 42:
                        case 43:
                        case 44:
                        case 45:
                            menuState -= 1;
                            menuFour.switchSet(menuState, false);
                            break;
                        }
                    }

                    if (GetAsyncKeyState(VK_LEFT))
                    {
                        if (involved == true)
                        {
                            if (involvedOne->getPosition().x > 3)
                            {
                                insert.colourInserter(involvedOne->getProcess(0).action, involvedOne->getMotivation(), involvedOne->getPosition());
                                involvedOne->getPosition().x -= 2;
                                involvedOne->getDirection() = false;
                                //! inserting packer's ids (debug purposes)
                                //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
                                //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
                                //else
                                insert.colourInserter(involvedOne->getProcess(1).action, involvedOne->getMotivation(), involvedOne->getPosition());
                                //if ( involvedOne->getProcess.delay == DELAY_THREE )
                                //{
                                //  areaOne.setter ( involvedOne->getAspiration (), involvedOne->getPosition () );
                                //}
                                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                            }
                        }
                        else
                        {
                            switch (menuState)
                            {
                            case 30:
                                menuState += 1;
                                menuThree.switchSet(menuState, false);
                                break;
                            case 31:
                                menuState -= 1;
                                menuThree.switchSet(menuState, false);
                                break;
                            case 40:
                            case 41:
                            case 42:
                                menuState += 3;
                                menuFour.switchSet(menuState, false);
                                break;
                            case 43:
                            case 44:
                            case 45:
                                menuState -= 3;
                                menuFour.switchSet(menuState, false);
                                break;
                            }
                        }
                    }

                    if (GetAsyncKeyState(VK_RIGHT))
                    {
                        if (involved == true)
                        {
                            if (involvedOne->getPosition().x <= (areaDimension.x - 3))
                            {
                                insert.colourInserter(involvedOne->getProcess(0).action, involvedOne->getMotivation(), involvedOne->getPosition());
                                involvedOne->getPosition().x += 2;
                                involvedOne->getDirection() = true;
                                //! inserting packer's ids (debug purposes)
                                //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
                                //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
                                //else
                                insert.colourInserter(involvedOne->getProcess(1).action, involvedOne->getMotivation(), involvedOne->getPosition());
                            }
                            //if ( involvedOne->getProcess.delay == DELAY_THREE )
                            //{
                            //  areaOne.setter ( involvedOne->getAspiration (), involvedOne->getPosition () );
                            //}
                            std::this_thread::sleep_for(std::chrono::milliseconds(50));
                        }
                        else
                        {
                            switch (menuState)
                            {
                            case 30:
                                menuState += 1;
                                menuThree.switchSet(menuState, false);
                                break;
                            case 31:
                                menuState -= 1;
                                menuThree.switchSet(menuState, false);
                                break;
                            case 40:
                            case 41:
                            case 42:
                                menuState += 3;
                                menuFour.switchSet(menuState, false);
                                break;
                            case 43:
                            case 44:
                            case 45:
                                menuState -= 3;
                                menuFour.switchSet(menuState, false);
                                break;
                            }
                        }
                    }

                    if (GetAsyncKeyState(VK_RETURN))
                    {
                        switch (menuState)
                        {
                        case 10:
                            //xx Todo FYI, user may doubtfully get involved in demo too! :)
                            //xx Todo a possible dream is also a dream! :) as if the programmer has more than two hands!
                            // Edit: lets try it! :)
                            if (involvedOne == nullptr)
                            {
                                involvedOne = new (std::nothrow) Packer(areaDimension);
                                involvedOne->involve((menuThree.get() * 10) + menuFour.get());
                            }
                            state.get(Packer::count);
                            involved = true;
                            theNarrator.draw(210);
                            //! inserting packer's ids (debug purposes)
                            //if ( involvedOne->getProcess ( 1 ).delay != DELAY_ONE )
                            //  insert.colourInserter ( std::to_string ( involvedOne->getId () ), involvedOne->getMotivation (), involvedOne->getPosition () );
                            //else
                            insert.colourInserter(involvedOne->getProcess(1).action, involvedOne->getMotivation(), involvedOne->getPosition());
                            menuOne.switcher(true);
                            menuState = 0;
                            break;
                        case 11:
                            //menuOne.switchSet ( menuState, true );
                            menuState = 20;
                            menuOne.switcher(false);
                            theNarrator.draw(211);
                            menuTwo.switcher();
                            break;
                        case 12:
                            runningOne = false;
                            break;
                        case 20:
                        case 21:
                        case 22:
                        case 23:
                        case 24:
                            //menuTwo.switchSet ( menuState, true );
                            menuState = 30;
                            menuTwo.switcher();
                            state.setter(menuTwo.get());
                            menuThree.switcher();
                            theNarrator.draw(2);
                            break;
                        case 30:
                        case 31:
                            //menuThree.switchSet ( menuState, true );
                            menuState = 40;
                            menuThree.switcher();
                            // Todo aware the narrator! :)
                            menuFour.switcher();
                            break;
                        case 40:
                        case 41:
                        case 42:
                        case 43:
                        case 44:
                        case 45:
                            //menuFour.switchSet ( menuState, true );
                            menuState = 10;
                            menuFour.switcher();
                            menuOne.get() = 0;
                            // Todo aware the narrator! :)
                            menuOne.switcher(false);
                            if (involvedOne != nullptr)
                                involvedOne->involve((menuThree.get() * 10) + menuFour.get());
                            break;
                        }
                    }

                    //xx Todo providing the ability so the involved one could escape her/his mess! :)
                    // edit: solution for time being:
                    if (GetAsyncKeyState(VK_ESCAPE) && (menuState == 0))
                    {
                        involved = false;
                        insert.colourInserter(involvedOne->getProcess(0).action, involvedOne->getMotivation(), involvedOne->getPosition());
                        state.get(Packer::count - 1);
                        menuState = 10;
                        theNarrator.draw(2);
                        menuOne.switcher(false);
                    }
                }
            }

#pragma endregion

            if ((counter % 800000) == 0)
            {
                unsigned char count{ 0 };
                if ((involved == false) && (involvedOne == nullptr))
                    count = Packer::count;
                else
                    count = Packer::count - 1;

                //TODO add: more smarty pants packers! :)
                //TODO add: change made by packers in their surround
                for (int i = 0; i < count; i++)
                {
                    //! inserting packer's ids (debug purposes)
                    //if ( allPackersList [i]->getProcess ( index ).delay != DELAY_ONE )
                    //  insert.colourInserter ( std::to_string ( allPackersList [i]->getId () ), allPackersList [i]->getMotivation (), allPackersList [i]->getPosition () );
                    //else
                    insert.colourInserter(allPackersList[i]->getProcess(index).action, allPackersList[i]->getMotivation(), allPackersList[i]->getPosition());

                    if (allPackersList[i]->getProcess(index).delay == DELAY_ONE)
                    {
                        if (allPackersList[i]->getDirection() == true)
                        {
                            if (allPackersList[i]->getPosition().x <= (areaDimension.x - 3))
                                allPackersList[i]->getPosition().x += 2;
                            else
                                allPackersList[i]->getDirection() = false;
                        }
                        else
                            if (allPackersList[i]->getPosition().x > 3)
                                allPackersList[i]->getPosition().x -= 2;
                            else
                                allPackersList[i]->getDirection() = true;
                    }
                    if (allPackersList[i]->getProcess(index).delay == DELAY_THREE)
                    {
                        areaOne.setter(allPackersList[i]->getAspiration(), allPackersList[i]->getPosition());
                    }
                    temp = allPackersList[0]->getProcess(index).delay;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(temp));
                index++;
                if (index > 3)
                    index = 0;
            }

            counter++;
            if (counter == 5000000)
                theNarrator.draw(110);
            if (counter == 10000000)
            {
                theNarrator.draw(1);
                theNarrator.draw(120);
            }

            if (counter == 20000000)
                counter = 1000;

            if (runningOne == false)
            {
                // Note packers send their regards! :)
                runningTwo = false;
                loader.clear();
            }
        } while (runningTwo);
    }

    // back to system default
    //SetConsoleOutputCP ( consoleOutputCPstorage );


    screen.release();
    theInput.release();

}
