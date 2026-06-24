#include <iostream>
#include "functions.h"
#include <conio.h>
using namespace std;

void debug()
{
    char mode;

    mode = _getch();
    cout << mode;

    while (mode != 'q')
    {
        switch(mode)
        {
            case 'd':
            d();
            cout << "\n-";
            mode = _getch();
            cout << mode;
            case 'c':
            c();
        }
    }
    
}