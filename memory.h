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
    void dumpMemory(int startP, int endP)
    {
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


    void compareMemory(int point1, int point2, int start)
    {
        int counter = point2 - point1;

        for (int i = 0; i <= counter; i++)
        {
            if (memory[point1 + i] != memory[start + i])
            {
                cout << "073F:" << hex << uppercase << setw(4) << setfill('0') << point1 + i << "  " << setw(2) << setfill('0') << int(memory[point1 + i]) << "  " << setw(2) << setfill('0') << int(memory[start + i]) << "  073F:" << setw(4) << setfill('0') << start + i << '\n';
            }
        }
    }

    void enterMemory(unsigned short int address, unsigned short int value)
    {
        memory[address] = value;
    }

    void fillMemory(unsigned short int point1, unsigned short int point2, unsigned short int value)
    {

        for (int i = point1; i <= point2; i++)
        {
            memory[i] = value;
        }
    }

    void moveMemory(unsigned short int point1, unsigned short int point2, unsigned short int start)
    {
        while(point1 <= point2)
        {
            memory[start] = memory[point1];
            point1++;
            start++;
        }
    }

    void searchMemory(unsigned short int start, unsigned short int end, unsigned short int value)
    {
        for (short int i = start; i <= end; i++)
        {
            if (memory[i] == value)
            {
                cout << "073F:" << setw(4) << setfill('0') << i << '\n';
            }
        }
    }

};

#endif

