#include <iostream>
#include <iomanip>
#include "memory.h"
using namespace std;

void d()
{
    cout << "\n073F:" << hex << setw(4) << setfill('0') << 256 << "  ";

    for (int i = 256; i <= 384; i++)
    {
        cout << setw(2) << memory[i] << ' ';
    }
}

void c()
{

}