#ifndef INTERFACE_H
#define INTERFACE_H


#include <iostream>
#include <cstring>
#include "debugger.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//to convert command into lowercase (because assembly language is not case-sensitive)
static void toLowerCase(char* a)
{
    for (int i = 0; i < 16; i++)
    {
        a[i] = tolower(a[i]);
    }
}

//to mount C drive
static void mountC()
{
    char startInput[16];

    //mounting c loop
    cout << "Z:\\>";
    cin.getline(startInput, 16);

    toLowerCase(startInput);

    while (strcmp(startInput, "mount c c:\\8086") != 0)
    {
        if (strcmp(startInput, "mount") == 0)
        {
            cout << "Current mounted drives are: \nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (strcmp(startInput, "mount c") == 0)
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (strcmp(startInput, "mount c c") == 0 || strcmp(startInput, "mount c c:") == 0)
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (strcmp(startInput, "mount c c:\\") == 0)
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is mounted as local directory c:\\\n";
        }
        else
        {
            if (strcmp(startInput, "") != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }
        
        cout << "Z:\\>";
        cin.getline(startInput, 16);
        toLowerCase(startInput);
    }

    cout << "Drive C is mounted as local directory c:\\8086\\\n";

}


//to enter Drive C
static void enterC()
{
    char startInput[16];

    //entering c loop
    cout << "Z:\\>";
    cin.getline(startInput, 16);

    toLowerCase(startInput);

    while (strcmp(startInput, "c:") != 0)
    {
        if (strcmp(startInput, "mount") == 0)
        {
            cout << "Current mounted drives are: \nDrive C is mounted as local directory c:\\8086\\\nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (strcmp(startInput, "mount c") == 0)
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (strcmp(startInput, "mount c c") == 0 || strcmp(startInput, "mount c c:") == 0)
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (strcmp(startInput, "mount c c:\\") == 0)
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is already mounted as local directory c:\\\n";
        }
        else if (strcmp(startInput, "mount c c:\\8086") == 0)
        {
            cout << "Drive C is already mounted with local directory c:\\8086\\\n";
        }
        else
        {
            if (strcmp(startInput, "") != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }
        cout << "Z:\\>";
        cin.getline(startInput, 16);
        toLowerCase(startInput);
    }
}


//to enter Debugger
static void enterDebugger()
{
    char startInput[16];

    //entering debugger loop
    cout << "C:\\>";
    cin.getline(startInput, 16);

    toLowerCase(startInput);

    while (strcmp(startInput, "debug") != 0)
    {
        if (strcmp(startInput, "mount") == 0)
        {
            cout << "Current mounted drives are: \nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (strcmp(startInput, "mount c") == 0)
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (strcmp(startInput, "mount c c") == 0 || strcmp(startInput, "mount c c:") == 0)
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (strcmp(startInput, "mount c c:\\") == 0)
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is mounted as local directory c:\\\n";
        }
        else
        {
            if (strcmp(startInput, "") != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }
        
        cout << "C:\\>";
        cin.getline(startInput, 16);
        toLowerCase(startInput);
    }

    cout << "-";
}

void interface()
{
    //mounts C drive
    mountC();

    //enters C drive
    enterC();

    //enters Debugger mode
    enterDebugger();   

    //new Debugger object created
    Debugger myDebugger;

    //Debugger Launched
    myDebugger.start();
}


#endif