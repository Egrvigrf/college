#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const float Enlargerate = 0.1; // 以横62个点竖10个点为基准
    const float A = 1; // y=Asin(x*B)
    const float B = 1;
    const int X = int(32 * Enlargerate * 2/B+10);
    const int Y = int(32 * Enlargerate * A+10);
    const float pi = 3.141592653;
    char m[X][Y];
    for (int x = 0; x <= X - 1; x++)
    {
        for (int y = 0; y <= Y - 1; y++)
        {
            m[x][y] = ' ';
        }
    }
    for (float x1 = round(pi * 10 * Enlargerate); x1 <= round(3 * pi * 10 * Enlargerate); x1++) 
    {
        m[int((x1 - round(pi * 10 * Enlargerate))/B)][int(round(sin(x1 / 10 / Enlargerate) * 10 * Enlargerate * A)) + int(Y / 2) + 1] = '*';
    }
    for (int y = 0; y <= Y - 1; y++)
    {
        for (int x = 0; x <= X - 1; x++)
        {
            cout << m[x][y];
        }
        cout << endl;
    }
    return 0;
}