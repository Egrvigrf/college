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
    int n, k, t = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] > a[j - 1])
            {
                t = a[j]; // swap
                a[j] = a[j - 1];
                a[j-1] = t;
            }
        }
    }
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}