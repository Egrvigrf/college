// #pragma GCC optimize(2)
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << "\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld pi = acosl(-1);
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    stack<int> stk;
    string s;
    cin >> s;
    int p = 1, q = n;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s[i] == 'L')
            p++;
        else
            q--;
    }
    p--;
    q++;
    int sum = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            sum = sum * a[p] % m;
            p--;
        }
        else
        {
            sum = sum * a[q] % m;
            q++;
        }
        stk.push(sum);
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}