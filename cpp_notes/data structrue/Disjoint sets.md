# 并查集
## 理解
&emsp;&emsp;合并更快

## 源代码
```c++
#include <bits/stdc++.h>
using namespace std;
int a[100];
int find(int x)
{
    while (a[x] != x) // 查询，最坏情况O(n)
        x = a[x];
    return x;
}
void merge(int x, int y)
{
    a[x] = y; // 合并，O(1)
}
int main()
{
    int n;
    cin >> n;
    // int a[n+1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    } // 每个节点初始化为根节点
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    return 0;
}
```