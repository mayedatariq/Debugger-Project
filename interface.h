#include <iostream>
using namespace std;

string toLowerCase(string str)
{
    int length = str.length();

    for (int i = 0; i < length; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void interface()
{
    string startInput;

    //mounting c loop
    cout << "Z:\\>";
    getline(cin, startInput);

    startInput = toLowerCase(startInput);

    while (startInput != "mount c c:\\8086")
    {
        if (startInput == "mount")
        {
            cout << "Current mounted drives are: \nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (startInput == "mount c")
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (startInput == "mount c c" || startInput == "mount c c:")
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (startInput == "mount c c:\\")
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is mounted as local directory c:\\\n";
        }
        else
        {
            if (startInput.length() != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }
        
        cout << "Z:\\>";
        getline(cin, startInput);
    }

    cout << "Drive C is mounted as local directory c:\\8086\\\n";

    //entering c loop
    cout << "Z:\\>";
    getline(cin, startInput);

    startInput = toLowerCase(startInput);

    while (startInput != "c:")
    {
        if (startInput == "mount")
        {
            cout << "Current mounted drives are: \nDrive C is mounted as local directory c:\\8086\\\nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (startInput == "mount c")
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (startInput == "mount c c" || startInput == "mount c c:")
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (startInput == "mount c c:\\")
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is already mounted as local directory c:\\\n";
        }
        else if (startInput == "mount c c:\\8086")
        {
            cout << "Drive C is already mounted with local directory c:\\8086\\\n";
        }
        else
        {
            if (startInput.length() != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }

    }
    
    //entering debugger loop
    cout << "C:\\>";
    getline(cin, startInput);

    startInput = toLowerCase(startInput);

    while (startInput != "debug")
    {
        if (startInput == "mount")
        {
            cout << "Current mounted drives are: \nDrive Z is mounted as Internal Virtual Drive\n";
        }
        else if (startInput == "mount c")
        {
            cout << "Usage \033[34m MOUNT Drive-Letter Local-Directory\033[0m\n";
            cout << "For example: MOUNT c d:\\dosprogs\n";
            cout << "This makes the directory d:\\dosprogs act as the C: drive inside DOSBox. \nThe directory has to exist. \n";
        }
        else if (startInput == "mount c c" || startInput == "mount c c:")
        {
            cout << "Directory C doesn't exist. \n";
        }
        else if (startInput == "mount c c:\\")
        {
            cout << "\033[31mMounting c:\\ is NOT recommended. Please mount a (sub)directory next time.\033[0m\nDrive C is mounted as local directory c:\\\n";
        }
        else
        {
            if (startInput.length() != 0)
            {
            cout << "Illegal command: " << startInput << '\n';
            }
        }
        
        cout << "Z:\\>";
        getline(cin, startInput);
    }

    cout << "-";

    
}