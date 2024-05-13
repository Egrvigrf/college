/**
 * author:  Egrvigrf
 * created: 2024-05-10 23:26:38
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
    int n, k, q;
    cin >> n >> k >> q;
    int a[k + 1];
    int b[k + 1];
    int qq[q + 1];
    int t[k + 1];
    forr(i, 1, k)
    {
        cin >> a[i];
    }
    forr(i, 1, k)
    {
        cin >> b[i];
    }
    forr(i, 1, q)
    {
        cin >> qq[i];
    }
    int j = 1;
    a[0] = 0;
    b[0] = 0;
    forr(i, 1, q)
    {
        int key = qq[i];
        int f = 1;
        int ba = k;
        int m = (f + ba) / 2;
        bool find = false;
        while (f <= ba)
        {
            if (a[m] == key)
            {
                find = true;
                break;
            }
            else if (a[m] > key)
            {
                ba = m - 1;
            }
            else
            {
                f = m + 1;
            }
            m = (f + ba) / 2;
        }
        if (find)
        {
            cout << b[m] << " ";
        }
        else
        {
            ll ans = b[ba]+(key - a[ba]) * (b[ba + 1] - b[ba]) / (a[ba + 1] - a[ba]);
            cout << ans << " ";
        }
    }
    cout << endl;
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