/**
 * author:  Egrvigrf
 * created: 2024-05-10 22:38:56
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
    string s;
    cin >> s;
    if(s.length() == 1)
    {
        cout << "NO" << endl;
        return;
    }
    char t = s[0];
    for (int i = 1; i <= s.length() - 1; i++)
    {
        if(s[i] != t)
        {
            cout << "YES\n"<< s[i] << s.substr(1, i - 1) << t << s.substr(i + 1) << endl;
            return;
        }
    }
    cout << "NO" << endl;
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