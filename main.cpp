//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Muriel Dulieu on 8/15/14.
//  Copyright (c) 2014 Muriel Dulieu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cctype>

class TicTacToe{
    int table[9];  // Table in which the game is played. 0 means the position is empty, 1 means 0, 4 means X
    int ComputerGetsXorO; // 0 means it has not been initialized, 1 means the computer plays O and plays second, 4 means the computer plays X and plays first
    int turns; // the number of turns left
    int WhoWins; // 0 means the game is still going or nobody won, 1 means the computer wins, 2 means the guest wins
public:
    TicTacToe();  // initialize all entries of table[9] to 0
    void Show(); // Show the table
    void ShowPositions(); // Show the numbers corresponding to the positions in the table
    void Play(); // play one game
    void Reset(); // reinitialize the game
    void WhoPlayFirst(); // decide randomly who starts playing
    inline int WhoWinsTheGame() {return WhoWins;}
};

int main(int argc, const char * argv[])
{
    using std::cout;
    using std::endl;
    using std::cin;
    int NumberWinsComputer = 0;
    int NumberWinsGuest = 0;
    TicTacToe Game;
    char PlayAgain;
    cout << "Do you want to play a game of Tic Tac Toe?" << endl << "If yes type \'y\' else type \'n\': ";
    cin >> PlayAgain;
    cout << endl;
    while (tolower(PlayAgain) == 'y')
    {
        Game.Reset();
        Game.Play();
        if (Game.WhoWinsTheGame() == 1)
            ++ NumberWinsComputer;
        else if (Game.WhoWinsTheGame() == 2)
            ++ NumberWinsGuest;
        cout << "Do you want to play another game? If yes type \'y\' else type \'n\': ";
        cin >> PlayAgain;
        cout << endl;
    }
    cout << "I won " << NumberWinsComputer << " game(s) and you won " << NumberWinsGuest << " game(s)." << endl;
    cout << "Thank you for playing!" << endl;
    
    return 0;
}

TicTacToe::TicTacToe()
{
    Reset();
}

void TicTacToe::Show()
{
    using std::cout;
    using std::endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << " ------------- " << endl;
        for (int j = 0; j < 3; ++j)
        {
            cout << " | ";
            if (table[(i * 3) + j] == 0)
                cout << " ";
            else if (table[(i * 3) + j] == 1)
                cout << "O";
            else if (table[(i * 3) + j] == 4)
                cout << "X";
        }
        cout << " | " << endl;
    }
    cout << " ------------- " << endl;
}

void TicTacToe::ShowPositions()
{
    using std::cout;
    using std::endl;
    cout << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << " ------------- " << endl;
        for (int j = 0; j < 3; ++j)
        {
            cout << " | ";
            cout << (i * 3) + j + 1;
        }
        cout << " | " << endl;
    }
    cout << " ------------- " << endl << endl;
}

void TicTacToe::Reset()
{
    for (int i = 0; i < 9; ++i)
        table[i] = 0;
    ComputerGetsXorO = 0;
    turns = 9;
    WhoWins = 0;
}

void TicTacToe::Play()
{
    using std::cout;
    using std::endl;
    using std::cin;
    cout << "Below is your tic tac toe table with the numbers corresponding to the positions in the table: " << endl;
    ShowPositions();
    WhoPlayFirst();
    srand (time(NULL));
    int ComputerPosition = rand() % turns;  // to choose randomly where the computer is going to play
    if(ComputerGetsXorO == 4)
    {
        table[ComputerPosition] = ComputerGetsXorO;
        -- turns;
    }
    Show();
    int GuestPosition = 0;
    bool tryAgain = true;
    bool GuestPlays = true;
    int GuestGetsXorO = (ComputerGetsXorO + 3) % 6;
    while (turns > 0)
    {
        cout << endl;
        if (GuestPlays)
        {
            do  // guest plays
            {
                cout << "Your turn! \nType the number corresponding to the position in which you want to play: ";
                std::cin >> GuestPosition;
                if (GuestPosition > 0 && GuestPosition <= 9 && table[GuestPosition - 1] == 0)
                {
                    tryAgain = false;
                }
                else if (GuestPosition > 0 && GuestPosition <= 9 && table[GuestPosition - 1] != 0)
                {
                    cout << "The position you chose is already occupied, try again!" << endl;
                    cin.get();
                }
                else
                {
                    cout << "You did not type a number between 1 and 9, try again!" << endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                
            }while(tryAgain);
            tryAgain = true;
            table[GuestPosition - 1] = (ComputerGetsXorO + 3) % 6;
        }
        else
        {
            cout << "My turn: " << endl;
            // check if computer has two signs in one row/column/diagonal with a third position empty so he wins in this turn
            if (table[0] + table[1] + table[2] == 2 * ComputerGetsXorO)
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if (table[3] + table[4] + table[5] == 2 * ComputerGetsXorO)
            {
                for (int i = 3; i < 6; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if (table[6] + table[7] + table[8] == 2 * ComputerGetsXorO)
            {
                for (int i = 6; i < 9; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

                
            }
            else if (table[0] + table[3] + table[6] == 2 * ComputerGetsXorO)
            {
                for (int i = 0; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if (table[1] + table[4] + table[7] == 2 * ComputerGetsXorO)
            {
                for (int i = 1; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if(table[2] + table[5] + table[8] == 2 * ComputerGetsXorO)
            {
                for (int i = 2; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if (table[0] + table[4] + table[8] == 2 * ComputerGetsXorO)
            {
                for (int i = 0; i < 9; i += 4)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;

            }
            else if (table[2] + table[4] + table[6] == 2 * ComputerGetsXorO)
            {
                for (int i = 2; i < 9; i += 4)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
                -- turns;
                Show();
                WhoWins = 1;
                break;
            }

            
            // check if guest has two signs in one row/column/diagonal to block it
            
            else if (table[0] + table[1] + table[2] == 2 * GuestGetsXorO)
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
            }
            else if (table[3] + table[4] + table[5] == 2 * GuestGetsXorO)
            {
                for (int i = 3; i < 6; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }

            }
            else if (table[6] + table[7] + table[8] == 2 * GuestGetsXorO)
            {
                for (int i = 6; i < 9; ++i)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }

                
            }
            else if (table[0] + table[3] + table[6] == 2 * GuestGetsXorO)
            {
                for (int i = 0; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }

            }
            else if (table[1] + table[4] + table[7] == 2 * GuestGetsXorO)
            {
                for (int i = 1; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
            }
            else if(table[2] + table[5] + table[8] == 2 * GuestGetsXorO)
            {
                for (int i = 2; i < 9; i += 3)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
            }
            else if (table[0] + table[4] + table[8] == 2 * GuestGetsXorO)
            {
                for (int i = 0; i < 9; i += 4)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
            }
            else if (table[2] + table[4] + table[6] == 2 * GuestGetsXorO)
            {
                for (int i = 2; i < 9; i += 4)
                {
                    if (table[i] == 0)
                    {
                        table[i] = ComputerGetsXorO;
                        break;
                    }
                }
            }
            else
            {
                // Guest does not have two signs in one row/column/diagonal that need to be blocked
                ComputerPosition = rand() % turns;
                int i;
                for (i = 0; i < 9; ++i)
                {
                    if (table[i] == 0)
                    {
                        if (ComputerPosition == 0)
                            break;
                        -- ComputerPosition;
                    }
                }
                table[i] = ComputerGetsXorO;
            }
        }
        -- turns;
        Show();
        GuestPlays = !GuestPlays;
        
        // check if the guest wins
        
        if (table[0] + table[1] + table[2] == 3 * GuestGetsXorO || table[3] + table[4] + table[5] == 3 * GuestGetsXorO || table[6] + table[7] + table[8] == 3 * GuestGetsXorO || table[0] + table[3] + table[6] == 3 * GuestGetsXorO || table[1] + table[4] + table[7] == 3 * GuestGetsXorO || table[2] + table[5] + table[8] == 3 * GuestGetsXorO || table[0] + table[4] + table[8] == 3 * GuestGetsXorO || table[2] + table[4] + table[6] == 3 * GuestGetsXorO)
        {
            WhoWins = 2;
            break;
        }
        
    }
    if (WhoWins == 1)
        cout << "I win!";
    else if (WhoWins == 2)
        cout << "You win!";
    else
        cout << "Nobody wins!";
    cout << endl;
    
}

void TicTacToe::WhoPlayFirst()
{
    using std::cout;
    using std::endl;
    cout << "Let's see who plays first: ";
    srand (time(NULL));
    int guestFirst = rand() % 2;
    if (guestFirst == 0)
    {
        ComputerGetsXorO = 4;
        cout << "I play first!";
    }
    
    else
    {
        ComputerGetsXorO = 1;
        cout << "You play first!";
    }
    cout << endl;
    
}

