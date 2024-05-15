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
const int N = 2e3 + 52;
int ans[N];
void solve()
{
    int r;
    cin >> r;
    cout << ans[r + 1] - ans[r] << endl;
}
signed main()
{
    fastIO();
    for (int i = 1; i <= N; i++)
    {
        int r = i;
        int j = i - 1;
        ll cnt = 0;
        while (2 * j * j >= r * r)
            j--;
        cnt += (j + 1) * (j + 1);
        for (int k = j + 1; k < r; k++)
        {
            int p = j;
            while (p * p + k * k >= r * r)
                p--;
            cnt += (p+1) * 2;
        }
        cnt = cnt * 4 - (r - 1) * 4;
        ans[i] = cnt;
    }
    int t;
    cin >> t;
    while (t--)
            solve();
    return 0;
}