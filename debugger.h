#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <conio.h>
#include "memory.h"

static void performArithemetic()
{
    short int a, b;
    cin >> hex >> a >> b;

    cout << setw(4) << setfill('0') << hex << a + b << "   " << setw(4) << setfill('0') << a - b;
}

class Debugger
{
    private:
    Memory myMemory;

    public:
    //launches Debugger
    void start()
    {
        char mode;

        mode = _getch();
        cout << mode;

        mode = tolower(mode);

        //take instructions until q entered (loop)
        while (mode != 'q')
        {
            switch(mode)
            {
                //d instruction for dumping memory
                case 'd':
                myMemory.dumpMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //c for comparing memory
                case 'c':
                myMemory.compareMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //e for entering a value in memory
                case 'e': 
                myMemory.enterMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //f for filling a range with some value in memory
                case 'f':
                myMemory.fillMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //h for performing arithmetic on two given values
                case 'h':
                performArithemetic();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //m for moving(copying) in memory
                case 'm':
                myMemory.moveMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //r for showing registers
                case 'r':
                //r();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;

                //s for searching in memory
                default:                //case 's':
                myMemory.searchMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
            }
        }
    return;
    }
};

#endif