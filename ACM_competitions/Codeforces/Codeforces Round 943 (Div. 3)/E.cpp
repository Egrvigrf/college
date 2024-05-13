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
    if(n == 1)
        cout << 1 << " " << 1<<endl;
    else if(n==2)
    {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if(n == 3)
    {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 3 << " " << 1 << endl;
    }    
    else
    {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 3 << " " << 1 << endl;
        for (int i = 4; i <= n; i++)
            cout << i << " " << i << endl;
    }


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