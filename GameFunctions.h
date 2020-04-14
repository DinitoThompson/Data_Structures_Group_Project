#pragma once
#ifndef GAMEFUCNTIONS_H
#define GAMEFUCNTIONS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"
#include "GuessedQueue.h"

using namespace std;

// The single instance of The Wheel & PlayerBase class that will be used.
WheelLinkedList TheWheel;
ContestantLinkedList PlayerBase;

// Function Declarations
int SectionIdentifier(int, int);
int SpinTheWheel();
int GamePlayMenu();
int GameContinue();

void MemoryAllocator();
void TheWheelCreator();
void ThePlayerBaseCreator();

// Functions Used
int SectionIdentifier(int x, int y)
{
    /*Generates a random number inbetween
    two indicated values.*/
    srand(time(NULL));
    //return rand() % (y - x + 1) + x;
    return x + (rand() % y);
}

int SpinTheWheel()
{
    WheelSection Wheel;
    // PlaySound(TEXT("playback.wav"),NULL,SND_ASYNC);// plays Wheel of fortune theme song. (.wav file has to be in the same folder)
    int i = 0, sectionID = 1;
    for (i = 0; i <= SectionIdentifier(10, 20); i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i | FOREGROUND_INTENSITY); // uses the loop increment to change the section color based of the color number scheme
        // Clear Screen
        system("cls");
        sectionID = SectionIdentifier(1, 23);

        // Call Search Method . Display Method
        Wheel.getSectionColor(i); // uses the loop increment to change the section color based of the color number scheme
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t---> "
             << "" << TheWheel.Search(sectionID)->getSectionData().getSectionType() << " <---" << endl;
        // Sleep for .5 seconds
        Sleep(0300);
    }
    return sectionID;
}

void TheWheelCreator()
{
    // Variables to make sure the correct amount of sections are created.
    int i, Bankrupt = 3, LoseATurn = 2,
           FiveHundred = 4, FiveFifty = 1,
           SixHundred = 4, SixFifty = 3, SevenHundred = 3,
           EightHundred = 1, EightFifty = 1, TwoThousandFive = 1;

    for (i = 1; i <= 23; i++) // uses this loop to give each section a particular color from the colour spectrum
    {
        for (int n = 1; n <= 23; n++)
        {
            if (Bankrupt != 0)
            {
                WheelSection Section(n, 0, "Bankrupt", i);
                TheWheel.InsertIntoWheel(Section);
                Bankrupt--;
            }
            else if (LoseATurn != 0)
            {
                WheelSection Section(n, 0, "Lose A Turn", i);
                TheWheel.InsertIntoWheel(Section);
                LoseATurn--;
            }
            else if (FiveHundred != 0)
            {
                WheelSection Section(n, 500, "$500", i);
                TheWheel.InsertIntoWheel(Section);
                FiveHundred--;
            }
            else if (FiveFifty != 0)
            {
                WheelSection Section(n, 500, "$550", i);
                TheWheel.InsertIntoWheel(Section);
                FiveFifty--;
            }
            else if (SixHundred != 0)
            {
                WheelSection Section(n, 600, "$600", i);
                TheWheel.InsertIntoWheel(Section);
                SixHundred--;
            }
            else if (SixFifty != 0)
            {
                WheelSection Section(n, 650, "$650", i);
                TheWheel.InsertIntoWheel(Section);
                SixFifty--;
            }
            else if (SevenHundred != 0)
            {
                WheelSection Section(n, 700, "$700", i);
                TheWheel.InsertIntoWheel(Section);
                SevenHundred--;
            }
            else if (EightHundred != 0)
            {
                WheelSection Section(n, 800, "$800", i);
                TheWheel.InsertIntoWheel(Section);
                EightHundred--;
            }
            else if (EightFifty != 0)
            {
                WheelSection Section(n, 850, "$850", i);
                TheWheel.InsertIntoWheel(Section);
                EightFifty--;
            }
            else if (TwoThousandFive != 0)
            {
                WheelSection Section(n, 2500, "$2500", i);
                TheWheel.InsertIntoWheel(Section);
                TwoThousandFive--;
            }
        }
    }
}

void ThePlayerBaseCreator()
{
    int i = 0;
    string playerName = "Default";
    for (i = 1; i <= 3; i++)
    {
        system("cls");
        cout << "Player #" << i << endl;
        cout << "Enter Player Name: ";
        cin >> playerName;
        Contestant Player;
        Player.setContestantName(playerName);
        Player.setContestantGrandTotal(0);
        Player.setContestantNumber(i);

        PlayerBase.insertAtBack(Player);
    }
    cout << "Players have been added..." << endl;
    system("pause"); 
    system("cls");
}

int GamePlayMenu()
{
    int playerOpt, flag = 0;

    while (flag != 1)
    {
        playerOpt = 0;
        cout << "\n\n1. Spin The Wheel" << endl;
        cout << "2. Buy A Vowel ($150)." << endl;
        cout << "3. Guess the entire word." << endl;
        cout << "4. Guess another letter." << endl; 
        cin >> playerOpt;

        if (playerOpt == 1 || playerOpt == 2 || playerOpt == 3 || playerOpt == 4)
            flag = 1;

        system("cls");
    }

    return playerOpt;
}

int GameContinue()
{
    int playerOpt = 0, flag = 0;

    while (flag != 1)
    {
        cout << "Would you like to Play Again?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> playerOpt;

        if (playerOpt == 1 || playerOpt == 2)
            flag = 1;

        system("cls");
    }

    return playerOpt;
}

void MemoryAllocator()
{
    PlayerBase.~ContestantLinkedList();
    TheWheel.~WheelLinkedList();
}

#endif // GAMEFUCNTIONS_H
