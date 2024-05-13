/**
 * author:  Egrvigrf
 * created: 2024-05-13 18:15:30
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
int a[200001];
void solve()
{
    int n;
    cin >> n;
    cout << a[n] << endl;
}
signed main()
{
    fastIO();
    for (int i = 1; i <= 200000; i++)
    {
        int t = i;
        int s = 0;
        while (t > 0)
        {
            s += t % 10;
            t /= 10;
        }
        a[i] = a[i - 1] + s;
    }
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}