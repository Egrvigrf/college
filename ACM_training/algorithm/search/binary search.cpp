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
    int a[10] = {1, 4, 5, 8, 9, 12, 17, 25, 30, 40};
    int n;
    cout << "please input a number you what to find\n";
    cin >> n;
    int i = 0, j = 9;
    int m,n_index = 0;
    bool f = false;
    while (i <= j)
    {
        m = (i + j) / 2;
        if (n > a[m])
        {
            i = m + 1;
        }
        else if (n == a[m])
        {
            n_index = m;
            f = true;
            break;
        }
        else
        {
            j = m - 1;
        }
    }
    if (f)
    {
        cout << n_index;
    }
    else
    {
        cout << "not find";
    }
    return 0;
}