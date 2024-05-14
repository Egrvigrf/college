/**
 * author:  Egrvigrf
 * created: 2024-05-14 18:38:59
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
int p[200001];
int a[200001];
void solve()
{
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll maxb = 0,maxs = 0;
    ll cntb = 0, cnts = 0;
    for (int i = 1; i <= min(k, n); i++)
    {
        cntb += a[pb];
        maxb = max(cntb + (k - i) * a[pb],maxb);
        pb = p[pb];
        cnts += a[ps];
        maxs = max(cnts + (k - i) * a[ps], maxs);
        ps = p[ps];
    }
    if(maxb > maxs)
        cout << "Bodya";
    else if (maxb < maxs)
        cout << "Sasha";
    else
        cout << "Draw";
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