#ifndef REGISTERS_H
#define REGISTERS_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


class Register
{
    private:
    unsigned short int value;

    public:
    unsigned short int getValue()
    {
        return value;
    }

    void setValue(unsigned short int a)
    {
        value = a;
    }
};


#endif