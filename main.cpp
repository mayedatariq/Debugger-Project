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
    string start;
    cout << "Z:\\>";
    cin >> start;


    while (start != "mount c c:\\8086" && start != "mount")



    return 0;
}