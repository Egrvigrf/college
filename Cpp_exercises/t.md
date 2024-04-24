# 动态规划

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int V, n;
    cin >> V >> n;
    int c[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> c[i];
    // 二维数组实现
    int m[n + 1][V + 1];
    for (int i = 0; i <= V; i++)
        m[0][i] = 0;
    for (int i = 1; i <= n; i++)
        m[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (j - v[i] < 0)
            {
                m[i][j] = m[i - 1][j];
            }
            else
            {
                m[i][j] = max(m[i - 1][j], m[i - 1][j - v[i]] + c[i]);
            }
        }
    }
    // 一维数组实现
    int M[V + 1];
    for (int i = 0; i <= V; i++)
        M[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--) // 从后往前更新防止重复放置同一种物品
        {
            M[j] = max(M[j], M[j - v[i]] + c[i]);
        }
    }
    cout << M[V];
    // cout << m[n][V];
    return 0;
}
```
- 1.
- 1.
- 2.
$$
\frac{x}{1+x^2}
$$


