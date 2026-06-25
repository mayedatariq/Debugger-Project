#ifndef MEMORY_H
#define MEMORY_H


#include <iostream>
#include <iomanip>
using namespace std;

class Memory
{
    private:
    char memory[65536];

    public:
    void dumpMemory()
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
    
        //when no range is given
        if (startP == 0 && endP == 0)
        {
            cout << "073F:" << hex << uppercase << setw(4) << setfill('0') << 256 << "  ";
            for(int j = 256; j < 272; j++)
            {
                    cout << setw(2) << int(memory[j]) << ' ';
            }
            cout << ' ';
            for (int j = 256; j < 272; j++)
            {
                if (memory[j] == 0)
                {   
                    cout << '.';
                }
                else
                {   
                    cout << memory[j];
                }
            }

            for (int i = 272; i < 384; i += 16)
            {
                cout << "\n073F:" << hex << uppercase << setw(4) << setfill('0') << i << "  ";
                for(int j = i; j < i + 16; j++)
                {
                        cout << setw(2) << int(memory[j]) << ' ';
                }
                cout << ' ';
                for (int j = i; j < i + 16; j++)
                {
                    if (memory[j] == 0)
                    {
                        cout << '.';
                    }
                    else
                    {
                        cout << memory[j];
                    }

                }   
            }
        }

        //when starting point is given
        if (startP != 0 && endP == 0)
        {
            cout << "073F:" << hex << uppercase << setw(4) << setfill('0') << startP << "  ";
            for(int j = startP; j < startP + 16; j++)
            {   
                    cout << setw(2) << int(memory[j]) << ' ';
            }
            cout << ' ';
            for (int j = startP; j < startP + 16; j++)
            {
                if (memory[j] == 0)
                {
                    cout << '.';
                }
                else
                {
                    cout << memory[j];
                }
            }

            for (int i = startP + 16; i < startP + 128; i += 16)
            {
                cout << "\n073F:" << hex << uppercase << setw(4) << setfill('0') << i << "  ";
                for(int j = i; j < i + 16; j++)
                {
                        cout << setw(2) << int(memory[j]) << ' ';
                }
                cout << ' ';
                for (int j = i; j < i + 16; j++)
                {
                    if (memory[j] == 0)
                    {
                        cout << '.';
                    }
                    else
                    {
                        cout << memory[j];
                    }

                }
            }
        }

        //when both starting point and ending point are given
        if (startP != 0 && endP != 0)
        {
            cout << "073F:" << hex << uppercase << setw(4) << setfill('0') << startP << "  ";
            for(int j = startP; j < startP + 16 && j <= endP; j++)
            {
                    cout << setw(2) << int(memory[j]) << ' ';
            }
            cout << ' ';
            for (int j = startP; j < startP + 16 && j <= endP; j++)
            {
                if (memory[j] == 0)
                {
                    cout << '.';
                }
                else
                {
                    cout << memory[j];
                }
            }

            for (int i = startP + 16; i <= endP; i += 16)
            {
                cout << "\n073F:" << hex << uppercase << setw(4) << setfill('0') << i << "  ";
                for(int j = i; j < i + 16 && j <= endP; j++)
                {
                        cout << setw(2) << int(memory[j]) << ' ';
                }
                cout << ' ';
                for (int j = i; j < i + 16 && j <= endP; j++)
                {
                    if (memory[j] == 0)
                    {
                        cout << '.';
                    }
                    else
                    {
                        cout << memory[j];
                    }

                }
            }
        }
    }

};



#endif

