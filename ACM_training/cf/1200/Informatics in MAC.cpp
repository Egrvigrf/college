/**
 * author:  Egrvigrf
 * created: 2024-05-13 18:37:50
 **/
// #pragma GCC optimize(2)
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld pi = acosl(-1);
#define int long long
#define debug(x) cout << #x << " = " << x << "\n"
#define forr(vari, begin, end) for (ll vari = ll(begin); vari <= ll(end); vari++)
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void solve()
{
    int n;
    cin >> n;
    int num[n + 1];
    bool left[n + 1];
    memset(left, 0, sizeof(left));
    int mexleft[n + 1];
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        left[num[i]] = true;
        while (left[p])
            p++;
        mexleft[i] = p;
    }
    bool right[n + 1];
    memset(right, 0, sizeof(right));
    p = 0;
    for (int i = n; i >= 2; i--)
    {
        right[num[i]] = true;
        while (right[p])
            p++;
        if (p == mexleft[i - 1])
        {
            cout << 2 << endl<< 1 << " " << i - 1 << endl<< i << " " << n << endl;
            return;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    fastIO();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}