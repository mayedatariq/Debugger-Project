#ifndef DEBUG_H
#define DEBUG_H


#include <iostream>
#include "functions.h"
#include <conio.h>
using namespace std;

void debug()
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
            d();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'c':
            c();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'e': 
            e();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'f':
            f();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'h':
            h();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'm':
            m();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            case 'r':
            r();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
            default:                //case 's':
            s();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            mode = tolower(mode);
            break;
        }
    }
    return;
}


#endif