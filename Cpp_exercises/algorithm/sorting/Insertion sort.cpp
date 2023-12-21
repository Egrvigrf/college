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
    int n, k, j;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        k = a[i];
        j = i;
        while (k > a[j - 1] and j >= 1)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = k;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}