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
    string a[2];         
    cin >> a[0] >> a[1]; 
    string d;
    d = a[0][0];
    string ans = "";
    int k;
    for (int i = 0; i < a[0].length()-1; i++)
    {
        if(a[0][i+1] == a[1][i])
        {

        }
        else if()
    }
    cout << ans << endl;
    cout << k << endl;
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