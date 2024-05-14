/**
 * author:  Egrvigrf
 * created: 2024-05-14 18:26:12
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
#define forr(vari,begin,end) for(ll vari=ll(begin); vari<=ll(end); vari++)
void fastIO() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void solve()
{
    int n;
    cin >> n;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 2 << endl;
    if(n >= 3)
    {
        for (int i = 3; i <= n; i++)
            cout << i << " " << i << endl;
    }
}
signed main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}