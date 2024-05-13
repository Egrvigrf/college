/**
 * author:  Egrvigrf
 * created: 2024-05-10 22:48:36
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = 0;
    int mi = min(a, b);
    int ma = max(a, b);
    if(c>mi && c <ma)
        t++;
    if (d > mi && d < ma)
        t++;
    if(t == 1)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
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