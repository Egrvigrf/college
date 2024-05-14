/**
 * author:  Egrvigrf
 * created: 2024-05-14 19:08:13
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
#define debug(x) cerr << #x << " = " << x << "\n"
#define forr(vari, begin, end) for (ll vari = ll(begin); vari <= ll(end); vari++)
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += (n + i) / (i * i);
    }
    cout << ans - 1<< endl;
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