#include <iostream>
#include <windows.h>
using namespace std;

void movePlayerLeft(char[][32]);
void movePlayerRight(char[][32]);
void printBoard(char[][32]);
void printFire(char[][32]);
void moveFire(char[][32]);
bool isDetect(char[][32]);
main()
{
    char battleBoard[7][32] = {
        "###############################",
        "#  e       e     e        e   #",
        "#                             #",
        "#                             #",
        "#           p                 #",
        "#                             #",
        "###############################"};
    system("cls");
    printBoard(battleBoard);

    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            movePlayerLeft(battleBoard);
            system("cls");
            printBoard(battleBoard);
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
        {
            movePlayerRight(battleBoard);
            system("cls");
            printBoard(battleBoard);
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            printFire(battleBoard);
            system("cls");
            printBoard(battleBoard);
            bool flag = true;
            while (flag)
            {

                if (isDetect(battleBoard))
                {
                    moveFire(battleBoard);
                    system("cls");
                    printBoard(battleBoard);
                }
                else
                {
                    flag = false;
                    system("cls");
                    printBoard(battleBoard);
                }
            }
        }
    }
}

void printBoard(char arr[7][32])
{

    // Print the battle board
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void movePlayerLeft(char arr[7][32])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i][j] == 'p')
            {
                arr[i][j] = ' ';
                if (j > 1)
                {
                    arr[i][j - 1] = 'p';
                }
                else
                {
                    arr[i][j] = 'p';
                }

                break;
            }
        }
    }
}
void movePlayerRight(char arr[7][32])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i][j] == 'p')
            {
                arr[i][j] = ' '; // Clear the current position
                if (j < 29)      // Move right if not at the rightmost boundary
                {
                    arr[i][j + 1] = 'p';
                }
                else
                {
                    arr[i][j] = 'p';
                }
                break; // Break out of the loop once 'p' is found and moved
            }
        }
    }
}
void printFire(char arr[7][32])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i][j] == 'p')
            {
                arr[i - 1][j] = '.';
                break;
            }
        }
    }
}
void moveFire(char arr[7][32])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i][j] == '.')
            {
                arr[i][j] = ' '; // Clear the current position
                arr[i - 1][j] = '.';
            }
        }
    }
}

bool isDetect(char arr[7][32])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (arr[i][j] == '.' && i > 0 && arr[i - 1][j] == '#')
            {
                arr[i][j] = ' ';
                return false; // Collision detected, stop moving
            }
        }
    }
    return true; // No collision detected, continue moving
}