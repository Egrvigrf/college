/**
 * author:  Egrvigrf
 * created: 2024-05-13 19:11:32
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
#define forr(vari, begin, end) for (ll vari = ll(begin); vari <= ll(end); vari++)
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void solve()
{
    priority_queue<int, vector<int>, greater<int>> c, d, h, s;
    int n;
    cin >> n;
    char k;
    cin >> k;
    string card;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> card;
        if (card[1] == 'C')
            c.push(card[0] - '0');
        else if (card[1] == 'D')
            d.push(card[0] - '0');
        else if (card[1] == 'H')
            h.push(card[0] - '0');
        else
            s.push(card[0] - '0');
    }
    if (k == 'C')
    {
        int cnt = 0;
        int size;
        if (c.empty())
            size = 0;
        else
            size = c.size();
        if (d.size() % 2 == 1)
            cnt++;
        if (h.size() % 2 == 1)
            cnt++;
        if (s.size() % 2 == 1)
            cnt++;
        if (cnt == 2)
        {
            if (size < 2)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        else if (cnt == 3)
        {
            if (size < 3)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        if (d.size() % 2 == 1)
        {
            cout << to_string(d.top()) + 'D' << " " << to_string(c.top()) + 'C' << endl;
            d.pop();
            c.pop();
        }
        while (!d.empty())
        {
            cout << to_string(d.top()) + 'D' << " ";
            d.pop();
            cout << to_string(d.top()) + 'D' << endl;
            d.pop();
        }

        if (h.size() % 2 == 1)
        {
            cout << to_string(h.top()) + 'H' << " " << to_string(c.top()) + 'C' << endl;
            h.pop();
            c.pop();
        }
        while (!h.empty())
        {
            cout << to_string(h.top()) + 'H' << " ";
            h.pop();
            cout << to_string(h.top()) + 'H' << endl;
            h.pop();
        }

        if (s.size() % 2 == 1)
        {
            cout << to_string(s.top()) + 'S' << " " << to_string(c.top()) + 'C' << endl;
            s.pop();
            c.pop();
        }
        while (!s.empty())
        {
            cout << to_string(s.top()) + 'S' << " ";
            s.pop();
            cout << to_string(s.top()) + 'S' << endl;
            s.pop();
        }

        while (!c.empty())
        {
            cout << to_string(c.top()) + 'C' << " ";
            c.pop();
            cout << to_string(c.top()) + 'C' << endl;
            c.pop();
        }
    }
    else if (k == 'D')
    {
        int cnt = 0;
        int size;
        if (d.empty())
            size = 0;
        else
            size = d.size();
        if (c.size() % 2 == 1)
            cnt++;
        if (h.size() % 2 == 1)
            cnt++;
        if (s.size() % 2 == 1)
            cnt++;
        if (cnt == 2)
        {
            if (size < 2)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        else if (cnt == 3)
        {
            if (size < 3)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }

        if (c.size() % 2 == 1)
        {
            cout << to_string(c.top()) + 'C' << " " << to_string(d.top()) + 'D' << endl;
            c.pop();
            d.pop();
        }
        while (!c.empty())
        {
            cout << to_string(c.top()) + 'C' << " ";
            c.pop();
            cout << to_string(c.top()) + 'C' << endl;
            c.pop();
        }

        if (h.size() % 2 == 1)
        {
            cout << to_string(h.top()) + 'H' << " " << to_string(d.top()) + 'D' << endl;
            h.pop();
            d.pop();
        }
        while (!h.empty())
        {
            cout << to_string(h.top()) + 'H' << " ";
            h.pop();
            cout << to_string(h.top()) + 'H' << endl;
            h.pop();
        }

        if (s.size() % 2 == 1)
        {
            cout << to_string(s.top()) + 'S' << " " << to_string(d.top()) + 'D' << endl;
            s.pop();
            d.pop();
        }
        while (!s.empty())
        {
            cout << to_string(s.top()) + 'S' << " ";
            s.pop();
            cout << to_string(s.top()) + 'S' << endl;
            s.pop();
        }

        while (!d.empty())
        {
            cout << to_string(d.top()) + 'D' << " ";
            d.pop();
            cout << to_string(d.top()) + 'D' << endl;
            d.pop();
        }
    }
    else if (k == 'H')
    {
        int cnt = 0;
        int size;
        if (h.empty())
            size = 0;
        else
            size = h.size();
        if (c.size() % 2 == 1)
            cnt++;
        if (d.size() % 2 == 1)
            cnt++;
        if (s.size() % 2 == 1)
            cnt++;
        if (cnt == 2)
        {
            if (size < 2)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        else if (cnt == 3)
        {
            if (size < 3)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }

        if (c.size() % 2 == 1)
        {
            cout << to_string(c.top()) + 'C' << " " << to_string(h.top()) + 'H' << endl;
            c.pop();
            h.pop();
        }
        while (!c.empty())
        {
            cout << to_string(c.top()) + 'C' << " ";
            c.pop();
            cout << to_string(c.top()) + 'C' << endl;
            c.pop();
        }

        if (d.size() % 2 == 1)
        {
            cout << to_string(d.top()) + 'D' << " " << to_string(h.top()) + 'H' << endl;
            d.pop();
            h.pop();
        }
        while (!d.empty())
        {
            cout << to_string(d.top()) + 'D' << " ";
            d.pop();
            cout << to_string(d.top()) + 'D' << endl;
            d.pop();
        }

        if (s.size() % 2 == 1)
        {
            cout << to_string(s.top()) + 'S' << " " << to_string(h.top()) + 'H' << endl;
            s.pop();
            h.pop();
        }
        while (!s.empty())
        {
            cout << to_string(s.top()) + 'S' << " ";
            s.pop();
            cout << to_string(s.top()) + 'S' << endl;
            s.pop();
        }

        while (!h.empty())
        {
            cout << to_string(h.top()) + 'H' << " ";
            h.pop();
            cout << to_string(h.top()) + 'H' << endl;
            h.pop();
        }
    }
    else
    {
        int cnt = 0;
        int size;
        if (s.empty())
            size = 0;
        else
            size = s.size();
        if (c.size() % 2 == 1)
            cnt++;
        if (d.size() % 2 == 1)
            cnt++;
        if (h.size() % 2 == 1)
            cnt++;
        if(cnt == 2)
        {
            if(size < 2)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        else if(cnt == 3)
        {
            if(size < 3)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        if (c.size() % 2 == 1)
        {
            cout << to_string(c.top()) + 'C' << " " << to_string(s.top()) + 'S' << endl;
            c.pop();
            s.pop();
        }
        while (!c.empty())
        {
            cout << to_string(c.top()) + 'C' << " ";
            c.pop();
            cout << to_string(c.top()) + 'C' << endl;
            c.pop();
        }

        if (d.size() % 2 == 1)
        {
            cout << to_string(d.top()) + 'D' << " " << to_string(s.top()) + 'S' << endl;
            d.pop();
            s.pop();
        }
        while (!d.empty())
        {
            cout << to_string(d.top()) + 'D' << " ";
            d.pop();
            cout << to_string(d.top()) + 'D' << endl;
            d.pop();
        }

        if (h.size() % 2 == 1)
        {
            cout << to_string(h.top()) + 'H' << " " << to_string(s.top()) + 'S' << endl;
            h.pop();
            s.pop();
        }
        while (!h.empty())
        {
            cout << to_string(h.top()) + 'H' << " ";
            h.pop();
            cout << to_string(h.top()) + 'H' << endl;
            h.pop();
        }

        while (!s.empty())
        {
            cout << to_string(s.top()) + 'S' << " ";
            s.pop();
            cout << to_string(s.top()) + 'S' << endl;
            s.pop();
        }
    }
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