#include <iostream>
#include <string>
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

int main()
{
    string startInput;
    cout << "Z:\\>";
    getline(cin, startInput);

    startInput = toLowerCase(startInput);

    while (startInput != "mount c c:\\8086")
    {
        cout << "Z:\\>";
        getline(cin, startInput);
    }


    return 0;
}