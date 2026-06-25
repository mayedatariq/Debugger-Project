#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <conio.h>
#include "memory.h"

class Debugger
{
    private:
    Memory myMemory;

    public:
    void start()
    {
        char mode;

        mode = _getch();
        cout << mode;

        mode = tolower(mode);

        while (mode != 'q')
        {
            switch(mode)
            {
                case 'd':
                myMemory.dumpMemory();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'c':
                //c();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'e': 
                //e();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'f':
                //f();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'h':
                //h();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'm':
                //m();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                case 'r':
                //r();
                cout << "\n-";
                mode = _getch();
                cout << mode;
                mode = tolower(mode);
                break;
                default:                //case 's':
                //s();
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