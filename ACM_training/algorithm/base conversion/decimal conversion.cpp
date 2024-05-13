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
    int n,m;
    char trans[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    cout << "Please input a demical number:";
    cin >> n;
    cout << "Please input a base number:";
    cin >> m;
    stack<char> s;
    while (n > 0)
    {
        s.push(trans[n%m]);
        n /= m;
    }
    while (s.empty() == false)
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}