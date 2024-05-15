/**
 * author:  Egrvigrf
 * created: 2024-05-15 15:22:14
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
const int N = 3e5 + 1;
int a[N];
int s[11][N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[0][i] = s[0][i - 1] + a[i];
    for (int i = 1; i <= k; i++)
    {
        int tmin = a[1];
        s[i][1] = a[1];
        for (int j = 2; j <= i+1; j++)
        {
            tmin = min(tmin, a[j]);
            s[i][j] = tmin * j;
        }
        for (int j = i + 2; j <= n; j++)
        {
            s[i][j] = s[i][j - 1] + a[j];
            int mininum = a[j];
            for (int k = 1; k <= i; k++)
            {
                mininum = min(a[j - k], mininum);
                s[i][j] = min(s[i - k][j - k-1] + (k+1) * mininum, s[i][j]);//对于每一个s[i][j], 遍历i次求可能的存在的区间最小值
            }
        }
    }
    cout << s[k][n] << endl;
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