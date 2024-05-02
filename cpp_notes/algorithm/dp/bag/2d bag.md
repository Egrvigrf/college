# 二维背包
## 2d 0-1背包
### 源代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int V, M, n;
    cin >> V >> M >> n;
    int c[n + 1], v[n + 1], m[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> v[i] >>m[i]>> c[i];
    // 二维数组实现
    int a[n + 1][V + 1][M + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)//放置第i件物品
    {
        for (int j = 1; j <= V; j++)//j为当前体积
        {
            for (int k = 1; k <= M; k++)//k为当前质量
            {
                if (j - v[i] < 0 || k - m[i] <0)
                {
                    a[i][j][k] = a[i - 1][j][k];
                }
                else
                {
                    a[i][j][k] = max(a[i - 1][j][k], a[i - 1][j - v[i]][k-m[i]] + c[i]);
                }
            }
        }
    }//一维数组实现
    int b[V + 1][M + 1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--) // j为当前体积
        {
            for (int k = M; k >= m[i]; k--) // k为当前质量
            {
                b[j][k] = max(b[j][k], b[j - v[i]][k - m[i]] + c[i]);
            }
        }
    }
    cout << a[n][V][M];
    return 0;
}
```
## 题目
- [P1507 NASA的食物计划](https://www.luogu.com.cn/problem/P1507)