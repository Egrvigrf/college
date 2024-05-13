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
    int n;
    cin >> n;
    int a[n + 1];
    int mm = -1;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> a[i];
        if(a[i] > mm)
            mm = a[i];
    }
    int b[n + 1];
    b[0] = mm+1;
    for (int i = 1; i <= n-1; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 0; i <= n-1; i++)
        cout << b[i]<<" ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}