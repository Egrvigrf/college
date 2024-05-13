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
int a[200010], p[200010];
void solve()
{
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int rb[n + 1];
    int t = pb;
    rb[1] = a[pb];
    ll maxb = rb[1];
    int mb[n + 1];
    mb[1] = maxb;
    for (int i = 1; i <= n-1; i++)
    {
        rb[i + 1] = a[p[t]];
        t = p[t];
        if(rb[i+1] > maxb)
            maxb = rb[i + 1];
    }
    ll ansb = 0;
    for (int i = 1; i <= k; i++)
    {

    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}