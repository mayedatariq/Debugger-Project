#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <conio.h>
#include "memory.h"
#include "registers.h"

//to input command
static char takeCommand()
{
    char mode;
    cout << "\n-" << flush;
    mode = _getch();
    cout << mode;
    mode = tolower(mode);
    return mode;
}

//for 'h' command
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
    Register AX;
    Register BX;
    Register CX;
    Register DX;
    Register SI;
    Register DI;
    Register SP;
    Register BP;
    Register DS;
    Register CS;
    Register ES;
    Register SS;
    Register IP;

    public:
    //launches Debugger
    void start()
    {
        char mode = takeCommand();

        //take instructions until q entered (loop)
        while (mode != 'q')
        {
            switch(mode)
            {
                //if pressed "Enter"
                case '\r':
                {
                    mode = takeCommand();
                    break;
                }

                //d instruction for dumping memory
                case 'd':
                {
                    char a;
                    int startP = 0, endP = 0;
                    cin.get(a);
                    if (a != '\n')
                    {
                        cin >> hex >> startP;
                        cin.get(a);
                        if (a != '\n')
                        {
                            cin >> hex >> endP;
                            cin.ignore();
                        }
                    }
                    myMemory.dumpMemory(startP, endP);
                    mode = takeCommand();
                    break;
                }

                //c for comparing memory
                case 'c':
                {
                    int point1, point2, start;
                    cin >> hex >> point1 >> point2 >> start;

                    myMemory.compareMemory(point1, point2, start);
                    mode = takeCommand();
                    break;
                }
                

                //e for entering a value in memory
                case 'e': 
                {
                    unsigned short int address, value;
                    cin >> hex >> address >> value;
                    cin.ignore();

                    myMemory.enterMemory(address, value);
                    mode = takeCommand();
                    break;
                }

                //f for filling a range with some value in memory
                case 'f':
                {
                    unsigned short int point1, point2, value;
                    cin >> hex >> point1 >> point2 >> value;
                    cin.ignore();

                    myMemory.fillMemory(point1, point2, value);
                    mode = takeCommand();
                    break;
                }

                //h for performing arithmetic on two given values
                case 'h':
                {
                    performArithemetic();
                    mode = takeCommand();
                    break;
                }

                //m for moving(copying) in memory
                case 'm':
                {
                    short int point1, point2, start;

                    cin >> hex >> point1 >> point2 >> start;
                    cin.ignore();
                    
                    myMemory.moveMemory(point1, point2, start);
                    mode = takeCommand();
                    break;
                }
                

                //r for showing registers
                case 'r':
                char str[4];
                cin.getline(str, 4);
                if (strlen(str) == 0)
                {
                    displayAllRegisters();
                }
                else
                {
                    displayRegister(str);
                }
                mode = takeCommand();
                break;

                //s for searching in memory
                default:                //case 's':
                {
                    unsigned short int start, end, value;

                    cin >> hex >> start >> end >> value;
                    cin.ignore();

                    myMemory.searchMemory(start, end, value);
                    mode = takeCommand();
                    break;
                }
                
            }
        }
        cin.get(mode);
        return;
    }

    //displays all registers
    void displayAllRegisters()
    {
        cout << hex << uppercase << "AX=" << setw(4) << setfill('0') << AX.getValue() << "  BX=" << setw(4) << setfill('0') << BX.getValue() << "  CX=" << setw(4) << setfill('0') << CX.getValue() << "  DX=" << setw(4) << setfill('0') << DX.getValue() << "  SP=" << setw(4) << setfill('0') << SP.getValue() << "  BP=" << setw(4) << setfill('0') << BP.getValue() << "  SI=" << setw(4) << setfill('0') << SI.getValue() << "  DI=" << setw(4) << setfill('0') << DI.getValue() << '\n';
        cout << "DS=" << setw(4) << setfill('0') << DS.getValue() << "  ES=" << setw(4) << setfill('0') << ES.getValue() << "  SS=" << setw(4) << setfill('0') << SS.getValue() << "  CS=" << setw(4) << setfill('0') << CS.getValue() << "  IP=" << setw(4) << setfill('0') << IP.getValue();
    }

    //displays a single register and uses upadteValue to update its value
    void displayRegister(char* str)
    {
        char registerName[3];
        registerName[0] = tolower(str[1]);
        registerName[1] = tolower(str[2]);
        registerName[2] = '\0';

        if (strcmp(registerName, "ax") == 0)
        {
            cout << "AX " << hex << setw(4) << setfill('0') << AX.getValue() << "\n:";
            updateRegister(AX);
        }
        else if (strcmp(registerName, "bx") == 0)
        {
            cout << "BX " << hex << setw(4) << setfill('0') << BX.getValue() << "\n:";
            updateRegister(BX);
        }
        else if (strcmp(registerName, "cx") == 0)
        {
            cout << "CX " << hex << setw(4) << setfill('0') << CX.getValue() << "\n:";
            updateRegister(CX);
        }
        else if (strcmp(registerName, "dx") == 0)
        {
            cout << "DX " << hex << setw(4) << setfill('0') << DX.getValue() << "\n:";
            updateRegister(DX);
        }
        else if (strcmp(registerName, "si") == 0)
        {
            cout << "SI " << hex << setw(4) << setfill('0') << SI.getValue() << "\n:";
            updateRegister(SI);
        }
        else if (strcmp(registerName, "di") == 0)
        {
            cout << "DI " << hex << setw(4) << setfill('0') << DI.getValue() << "\n:";
            updateRegister(DI);
            
        }
        else if (strcmp(registerName, "sp") == 0)
        {
            cout << "SP " << hex << setw(4) << setfill('0') << SP.getValue() << "\n:";
            updateRegister(SP);
        }
        else if (strcmp(registerName, "bp") == 0)
        {
            cout << "BP " << hex << setw(4) << setfill('0') << BP.getValue() << "\n:";
            updateRegister(BP);
        }
        else if (strcmp(registerName, "ds") == 0)
        {
            cout << "DS " << hex << setw(4) << setfill('0') << DS.getValue() << "\n:";
            updateRegister(DS);
        }
        else if (strcmp(registerName, "ss") == 0)
        {
            cout << "SS " << hex << setw(4) << setfill('0') << SS.getValue() << "\n:";
            updateRegister(SS);
        }
        else if (strcmp(registerName, "es") == 0)
        {
            cout << "ES " << hex << setw(4) << setfill('0') << ES.getValue() << "\n:";
            updateRegister(ES);
        }
        else if (strcmp(registerName, "cs") == 0)
        {
            cout << "CS " << hex << setw(4) << setfill('0') << CS.getValue() << "\n:";
            updateRegister(CS);
        }
        else
        {
            cout << "IP " << hex << setw(4) << setfill('0') << IP.getValue() << "\n:";
            updateRegister(IP);
        }

    }

    //updates register value
    void updateRegister(Register& r)
    {
        unsigned short int a;
        cin >> hex >> a;
        cin.ignore();
        r.setValue(a);
            
    }
};

#endif