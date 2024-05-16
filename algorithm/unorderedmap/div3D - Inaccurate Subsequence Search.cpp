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
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, int> mp1, mp2;
    int a[n + 1];
    int b[m + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        mp1[x]++;
        mp2[a[i]]++;
    }
    int ans = 0;
    int count = 0;
    for (auto i = mp1.begin(); i != mp1.end(); i++)
    {
        count += min(i->second, mp2[i->first]);
    }
    for (int i = m; i <= n; i++)
    {
        if (count >= k)
            ans++;
        int next = a[i + 1];
        int pre = a[i - m + 1];
        if (mp1[next] > 0)
        {
            mp2[next]++;
            if (mp2[next] <= mp1[next])
                count++;
        }
        if (mp1[pre] > 0)
        {
            mp2[pre]--;
            if (mp2[pre] < mp1[pre])
                count--;
        }
    }
    cout << ans << endl;
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