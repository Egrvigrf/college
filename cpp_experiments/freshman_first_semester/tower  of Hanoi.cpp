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
void mov(int l,char x, char y, char z);
int ans = 0;
int main()
{
    int n;
    cin >> n;
    mov(n, 'a', 'b', 'c');
    cout << ans;
    return 0;
}
void mov(int l, char x, char y, char z)
{
    if (l == 2)
    {
        cout << x << "->" << y << endl;
        cout << x << "->" << z << endl;
        cout << y << "->" << z << endl;
        ans += 3;
    }
    else
    {
        mov(l-1, x, z, y);
        cout << x << "->" << z << endl;
        ans++;
        mov(l - 1, y, x, z);
    }
}