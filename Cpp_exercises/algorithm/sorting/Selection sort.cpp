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
    int n,k,t = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] > a[k])
            {
                k = j;
            }
        }
        t = a[i];//swap
        a[i] = a[k];
        a[k] = t;
    }
    for (int i = 0; i <= n - 1; i++)
    { 
        cout<<a[i] << " ";
    }
    return 0;
}