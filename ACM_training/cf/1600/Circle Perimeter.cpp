/**
 * author:  Egrvigrf
 * created: 2024-05-15 20:41:29
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
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int N = 1e5 + 10;
int ans[N];
ll travel(int i)
{
    if (ans[i])
        return ans[i];
    int r2 = i * i;
    int j = (int)(sqrt(r2 / 2));
    ll cnt = (j + 1) * (j + 1);
    int p = j;
    int cnt2 = 0;
    for (int k = j + 1; k < i; k++)
    {
        int nn = 0;
        while (p * p + k * k >= r2)
            p--;
        cnt2 += (p + 1);
    }
    cnt2 *= 2;
    ans[i] = (cnt + cnt2 - i + 1) * 4;
    return ans[i];
}
void solve()
{
    int r;
    cin >> r;
    cout << travel(r+1) - travel(r) << endl;
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