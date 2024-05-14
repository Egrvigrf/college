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
void solve()//如果gcd(a,b) = g , a = p*g, b = q*g.可证gcd(p,q) = 1(反证).
{           //化简p = q(kg - 1),则根据gcd(p,q) = 1, kg - 1 >= 1,可知q = 1
    int n, m;//根据q = 1原式子化简 a+b = kb*b,根据1 =< a <= n,可得(1+b)/b*b =< k <= (n+b) / b*b  
    cin >> n >> m;//注意到当且仅当b = 1 时 k >= 2,所以ans最后减掉1
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