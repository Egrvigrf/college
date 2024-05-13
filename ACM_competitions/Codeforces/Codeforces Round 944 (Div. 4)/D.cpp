/**
 * author:  Egrvigrf
 * created: 2024-05-10 22:58:53
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
        cout << 1 << endl;
        return;
    }
    int ans = 0;
    bool first = true;
    int i = 1;
    while (i <= s.length()-1)
    {
        if(s[i] == s[i-1])
        {
            if(i == s.length()-1)
            {
                ans++;
            }
            i++;
            continue;
        }
        else
        {
            if(s[i] == '0' && s[i-1] == '1')
            {
                if(i == s.length()-1)
                {
                    ans += 2;
                }
                else
                {
                    ans++;
                }
            }
            else if (s[i] == '1' && s[i - 1] == '0')
            {
                if(first)
                {
                    first = false;
                    if(i == s.length()-1)
                        ans++;
                }
                else
                {
                    if (i == s.length() - 1)
                    {
                        ans += 2;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        i++;
    }
    
    cout << ans << endl;
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