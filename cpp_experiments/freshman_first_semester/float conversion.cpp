#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <random>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    double n;
    int m;
    char trans[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    cout << "Please input a float number less than 1:";
    cin >> n;
    cout << "Please input a base number:";
    cin >> m;
    cout << "0.";
    while (n > 0)
    {
        n *= m;
        cout << trans[int(n)];
        n -= int(n);
    }
    return 0;
}