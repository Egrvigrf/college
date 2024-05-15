/**
 * author:  Egrvigrf
 * created: 2024-05-15 15:22:14
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
#define debug(x) cout << #x << " = " << x << "\n"
void fastIO() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const int N = 3e5 + 1;
int a[N];
int s[10][N];
void solve()
{
    int n,k;
    cin >> n>>k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[0][i] = s[0][i - 1] + a[i];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            s[i][j] = s[i - 1][j];
        }
        for (int j = k+1; j <= n; j++)
        {
            if(s[i-1][j] - abs(a[j]-a[j-1]) < s[i][j-1]+a[j])
            {
                s[i][j] = s[i - 1][j] - abs(a[j] - a[j - 1]);  
            }
            else
            {      
                s[i][j] = s[i][j-1]+a[j];
            }
        }
    } 
    cout << s[k][n]<<endl;
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