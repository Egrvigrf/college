# 比邻接矩阵更高效的存储结构--前向星
## 理解
&emsp;&emsp;比邻接矩阵更节省空间，遍历时可以跳过为空（不能到达）的部分，空间和时间复杂度更优。
## 源代码
```c++
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to, next, w;
} e[100];//在一个结构体数组里存储了很多链表
int cnt = 0;
int head[100];//head[i] 表示第i个节点的头指针“地址”
void addedge(int x, int y, int v)
{
    e[++cnt].next = head[x];//添加的过程是不断在父节点为x的链表的头节点插入元素
    e[cnt].to = y;
    e[cnt].w = v;
    head[x] = cnt;//更新该链表的首指针
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, wei;
        cin >> a >> b >> wei;
        addedge(a, b, wei);
        // 如果是无向图，还要addedge(b,a,wei);
    }
    //遍历与x节点相连的所有节点
    int x;
    cin >> x;
    for (int i = head[x]; i != 0; i = e[i].next)
    {
        cout << x << "->" << e[i].to << " value:" << e[i].w<<endl;
    }
    return 0;
}
```