## 图论基础

### 1. 基本定义

1.   图

     **图 (graph)** 是一个二元组 $G=(V,E)$, 其中 V 是顶点集, E 是边集.

     图有多种，包括 **无向图 (undirected graph)**，**有向图 (directed graph)**，**混合图 (mixed graph)** 等。

     <img src="图论基础，搜索、搜索剪枝（状态图），简单dp.assets/image-20240109104601636.png" alt="image-20240109104601636" style="zoom:33%;" /><img src="图论基础，搜索、搜索剪枝（状态图），简单dp.assets/image-20240109104617874.png" alt="image-20240109104617874" style="zoom:33%;" />

     

     每条边还可以带相应**权值**. 

     

     形象地说，图是由若干点以及连接点与点的边构成的。

     **简单图**(没有自环和重边) / **多重图**(有自环或重边)

     

2.   度

     与一个顶点 ![v](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 关联的边的条数称作该顶点的 **度 (degree)**, 对于有向图, 又分**出度**和**入度**.

     **握手定理** : $d=2m$

     

4.   树

     树的定义：是由n个节点组成的具有层次关系的图

     

     **一些基本概念：** 

     每个节点有多个或零个**子节点** 

     没有父节点的节点称为**根节点** 

     没有子节点的节点称为**叶子节点**

      n个顶点的树有n-1条边 

     <img src="图论基础，搜索、搜索剪枝（状态图），简单dp.assets/image-20240109104744180.png" alt="image-20240109104744180" style="zoom: 67%;" />

### 2. 存图

#### 1.邻接矩阵

二维数组

```c++
vector<int,vector<int> >G(n,vector<int>(m,0));
	//<=>int G[n][m];
	//G[a][b]=w, 表示 a,b 之间有边, 边权为 w
```

快速查询, 浪费空间

#### 2.邻接表

邻接表: 记录每个节点的相连的点 / 出度 / 入度

```c++
vetcor<pair<int,int> >e(n+1);
e[u].push_back({v,w});//插入一条与 v 相连, 权值为 w 的边

for(auto c:e[u]){//遍历与 u 连的点
    cout<<u<<"->"<<c.first<<" "<<c.second<<endl;
}
```

不方便查询和修改

eg: 使用 vector 做邻接表时, 每次 vector 扩充两倍，会被卡内存

#### 3.链式向前星

数组模拟邻接表，节省内存

![image-20230416212836315](图论基础，搜索、搜索剪枝（状态图），简单dp.assets/image-20230416212836315.png)

```c++
struct E
{	int to;//每条出度的终点
    int w;//每条出度的权值
    int next;//链中下一个当前节点的出度的数组脚标
    E(){}
    E (int a,int b,int c):to(a),w(b),next(c){}
};
E edge[M];//按顺序记录M条边
int hand[N]={0};//有N个节点

//存入一个出度
edge[i]=E(v,w,hand[u]);
head[u]=i;

//遍历某个点的全部出度
 for(int j = head[i]; j != 0; j = edge[j].next)//遍历以i为起点的边
   	 cout << i << " " << edge[j].to << " " << edge[j].w << endl;
```

## 搜索

主要两类: BFS, DFS.

分别形成了广度优先搜索树/BFS序, 深度优先搜索树/DFS序

### 1.DFS

一般递归实现(用 stack 实现 ?)

简单地说：“一条道走到黑”，”走不了了再倒回去“

伪代码 :

```c++
DFS(v){//v 可以是图中的一个顶点
    for u in v 的相邻节点{
        if (u 没有打过访问标记){
            在 u 上打标记
            DFS(u)
            消除 u 上的标记
        }
    }
}
```

时间复杂度为$O(m+n)$

eg: [全排列问题](https://www.luogu.com.cn/problem/P1706)

```c++
int vis[11] = {0}, n, ans[11];
void dfs(int len) {
	if (len >= n + 1) {
		for (int i = 1; i <= n; i++) {
			cout <<"    "<< ans[i];
		}
		cout << endl;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		ans[len] = i;
		dfs(len + 1);
		vis[i] = 0;
	}
}
void solve() {
	cin >> n;

	dfs(1);
}
signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int _ = 1;
	//cin>>_;
	while (_--) {
		solve();
	}
}
```

eg: [八皇后](https://www.luogu.com.cn/problem/P1219)

### 2.BFS

一般使用队列实现( 用递归实现 ? )

主要策略是一层一层的走, 将一个图 / 树一层一层地剥开, 用队列存上一层的节点(接下来要访问他的子节点)

伪代码 :

```c++
while (队列不为空) {
  int u = 队首;
  弹出队首;
  for (枚举 u 的邻居) {
    更新数据
    if (...)
      添加到队首;
    else
      添加到队尾;
  }
}
```

eg: [走出迷宫](https://ac.nowcoder.com/acm/contest/23156/1002)

```c++
int n, m, vis[510][510];
int dir[][2] = { -1, 0, 0, -1, 0, 1, 1, 0};
string s[510];
void solve() {
	memset(vis, 0, sizeof(vis));
	// cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'S') {
				//bfs开始
				queue<pair<int, int> >q;
				q.emplace(i, j);//将起点插入队列
				vis[i][j] = 1;
				while (!q.empty()) {//一直循环到队列空
					pair<int, int> tp = q.front(); q.pop();
                    //弹出队头元素,并搜索他的相邻点
					for (int z = 0; z <= 3; z++) {
						int x = tp.first + dir[z][0], y = tp.second + dir[z][1];
						if (x >= n || y >= m || x < 0 || y < 0)continue;
						if (vis[x][y])continue;
						if (s[x][y] == '#')continue;

						if (s[x][y] == 'E') {
							cout << "Yes" << endl;
							return ;
						}
						vis[x][y] = 1;
						q.emplace(x, y);
					}
				}
				//bfs结束
				cout << "No" << endl;
				break;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (cin >> n >> m) {
		solve();
	}
}
```

eg: [马的遍历](https://www.luogu.com.cn/problem/P1443)

-   优先队列 BFS(一种剪枝 ?)

    STL 中提供了 [`std::priority_queue`](https://oi-wiki.org/lang/csl/container-adapter/)，可以方便我们使用优先队列。

    在基于优先队列的 BFS 中，我们每次从队首取出代价最小的结点进行进一步搜索。容易证明这个贪心思想是正确的

### 3.搜索剪枝

[一篇博客](https://www.cnblogs.com/fenghaoran/p/6391016.html#:~:text=%E5%89%AA%E6%9E%9D%E7%9A%84%E5%8E%9F%E5%88%99%EF%BC%9F%201%201.%E5%8F%AF%E8%A1%8C%E6%80%A7%E5%89%AA%E6%9E%9D%E3%80%82%20%E5%A6%82%E6%9E%9C%E5%BD%93%E5%89%8D%E6%9D%A1%E4%BB%B6%E4%B8%8D%E5%90%88%E6%B3%95%E5%B0%B1%E4%B8%8D%E5%86%8D%E7%BB%A7%E7%BB%AD%E6%90%9C%E7%B4%A2%EF%BC%8C%E7%9B%B4%E6%8E%A5return%E3%80%82%20%E8%BF%99%E6%98%AF%E9%9D%9E%E5%B8%B8%E5%A5%BD%E7%90%86%E8%A7%A3%E7%9A%84%E5%89%AA%E6%9E%9D%EF%BC%8C%E6%90%9C%E7%B4%A2%E5%88%9D%E5%AD%A6%E8%80%85%E9%83%BD%E8%83%BD%E8%BD%BB%E6%9D%BE%E5%9C%B0%E6%8E%8C%E6%8F%A1%EF%BC%8C%E8%80%8C%E4%B8%94%E4%B9%9F%E5%BE%88%E5%A5%BD%E6%83%B3%E3%80%82%20%E4%B8%80%E8%88%AC%E7%9A%84%E6%90%9C%E7%B4%A2%E9%83%BD%E4%BC%9A%E5%8A%A0%E4%B8%8A%E3%80%82%20...%202,%E5%AE%83%E7%9A%84%E5%85%B3%E9%94%AE%E6%98%AF%EF%BC%9A%E5%A6%82%E6%9E%9C%E5%AF%B9%E4%BA%8E%E7%9B%B8%E5%90%8C%E6%83%85%E5%86%B5%E4%B8%8B%E5%BF%85%E5%AE%9A%E7%AD%94%E6%A1%88%E7%9B%B8%E5%90%8C%EF%BC%8C%E5%B0%B1%E5%8F%AF%E4%BB%A5%E6%8A%8A%E8%BF%99%E4%B8%AA%E6%83%85%E5%86%B5%E7%9A%84%E7%AD%94%E6%A1%88%E5%80%BC%E5%AD%98%E5%82%A8%E4%B8%8B%E6%9D%A5%EF%BC%8C%E4%BB%A5%E5%90%8E%E5%86%8D%E6%AC%A1%E6%90%9C%E7%B4%A2%E5%88%B0%E8%BF%99%E7%A7%8D%E6%83%85%E5%86%B5%E6%97%B6%E5%B0%B1%E5%8F%AF%E4%BB%A5%E7%9B%B4%E6%8E%A5%E8%B0%83%E7%94%A8%E3%80%82%20...%204%204.%E6%90%9C%E7%B4%A2%E9%A1%BA%E5%BA%8F%E5%89%AA%E6%9E%9D%20%E5%9C%A8%E4%B8%80%E4%BA%9B%E8%BF%B7%E5%AE%AB%E9%A2%98%EF%BC%8C%E7%BD%91%E6%A0%BC%E9%A2%98%EF%BC%8C%E6%88%96%E8%80%85%E5%85%B6%E4%BB%96%E6%90%9C%E7%B4%A2%E4%B8%AD%E5%8F%AF%E4%BB%A5%E8%B4%AA%E5%BF%83%E7%9A%84%E9%A2%98%EF%BC%8C%E6%90%9C%E7%B4%A2%E9%A1%BA%E5%BA%8F%E6%98%BE%E5%BE%97%E5%8D%81%E5%88%86%E9%87%8D%E8%A6%81%E3%80%82%20%E6%88%91%E7%BB%8F%E5%B8%B8%E5%90%AC%E8%A7%81%E6%9C%89%E4%BA%BA%E8%AF%B4%20%28%E6%88%91%E8%87%AA%E5%B7%B1%E4%B9%9F%E8%AF%B4%E8%BF%87%29%EF%BC%9A%E2%80%9C%E4%BB%8E%E5%B7%A6%E8%BE%B9%E6%90%9C%E4%BC%9AT%EF%BC%8C%E4%BB%8E%E5%8F%B3%E8%BE%B9%E6%90%9C%E5%B0%B1A%E4%BA%86%E2%80%9D%E4%B9%8B%E7%B1%BB%E7%9A%84%E8%AF%AD%E5%8F%A5%E3%80%82%20)

进程近似一颗树

剪枝就是一种生动的比喻：把不会产生答案的，或不必要的枝条“剪掉”。

1.   可行性剪枝

     当某些点不符合题设, 立即 return(如 : "走出迷宫"中坐标到了迷宫大小 (N*M) 外 ).

2.   最优性剪枝

     实时维护当前知道的最优解, 如果当前条件所创造出的答案必定比之前的答案大, 那么剩下的搜索就毫无必要, 就return.

3.   记忆化搜索

     如果对于相同情况下必定答案相同, 就可以把这个情况的答案值存储下来, 以后再次搜索到这种情况时就可以直接调用。

4.   搜索顺序剪枝

     在一些迷宫题，网格题，或者其他搜索中可以贪心的题，搜索顺序显得十分重要。

     “从左边搜会T，从右边搜就AC了”

      其实在迷宫、网格类的题目中，右下左上就明显比左上右下优秀。

      在一些推断搜索题中，从已知信息最多的地方开始搜索显然更加优秀。

      在一些题中，先搜某个值大的，再搜某个值小的(比如树的度数，产生答案的预计(A*))，速度明显会比乱搜更快。

      搜索的复杂度明显讲不清，这种剪枝自然是能加就加。

[小猫爬山](https://www.acwing.com/problem/content/167/)

```c++
int n, w, c[20], cnt, cab[20], ans = inf;

void bfs(int now) {
	if (cnt >= ans)return;

	if (now >= n + 1) {
		ans = min(ans, cnt);
		return ;
	}

	for (int i = 1; i <= cnt; i++) {
		if (c[now] + cab[i] <= w) {
			cab[i] += c[now];
			bfs(now + 1);
			cab[i] -= c[now];
		}
	}

	cab[++cnt] += c[now];
	bfs(now + 1);
	cab[cnt--] -= c[now];
}

void solve() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	// sort(c + 1, c + n + 1, greater<int>());

	bfs(1);
	cout << ans << endl;
}
```



### 一些图的算法

求最短路算法, 拓扑排序, 最小生成树

连通性的判断,

## 简单动态规划

就是不同状态的转移, 核心求转移方程



线性DP$\begin{cases}背包问题\\子序列问题 \end{cases}$



### 背包问题

**[01背包 ](https://www.acwing.com/problem/content/2/):**

有 n 件物品和一个容量为 m 的背包。第 i 件物品的体积是 c[i] ，价值是 w[i] 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

用`dp[i][j]`来表示前 i 件物品恰放入一个容量为 j 的背包可以获得的最大价值。

........

得到转移方程 : $dp[i][j]=max\left( dp[i-1][j],dp[i-1][v-c[i]]+w[i]\right)$, 第 i 个放或不放

(在 Max 函数中加上 `dp[i][j-1]`呢 ?)

....DP的一个**重点** :  初始化 . ----> 在这里只需要全零就好

```c++
int n, v;
int dp[1010][1010] = {0};
int c[1010], w[1010];
void solve() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= v; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= c[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + w[i]);
		}
	}
	cout << dp[n][v];
}
```

优化一下 :

把DP数组减去一维.

```c++
int n, v;
int dp[1010] = {0};
int c[1010], w[1010];
void solve() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 1; j--) {
			if (j >= c[i])
				dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
		}
	}
	cout << dp[v];
}
```

第二个 for 循环是反着的 ? ? ? ? ?

如果正着变成什么情况了



背包问题大致可以概括成：

有一堆物品，每个物品有对应价值和体积，我们如何在给定体积下选择尽可能多的价值？即最经典的 -- 01背包问题

对于每个物品若能重复取--完全背包问题

如果每种物品能取的数量有上限--多重背包问题

如果取物品同时存在体积和重量，我需要满足体积和重量都不超过限制--二维费用背包问题

.....

大家可以参考背包九讲：https://zhuanlan.zhihu.com/p/139368825 

练题的话, 可以刷一刷acwing题库的前几道题

### 子序列问题

#### [最长上升子序列](https://www.luogu.com.cn/problem/B3637)

```c++
void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans=0;
	vector<int>dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;//初始化问题, 考虑每个点的初始状态
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j])dp[i] = max(dp[i], dp[j] + 1);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans << endl;
}
```

还有其他子序列问题 : 最长递减子序列, 最长回文子序列, 最长公共子序列......

其他还有哪些DP :(来自Oi wiki)

![image-20240110220430628](图论基础，搜索、搜索剪枝（状态图），简单dp.assets/image-20240110220430628.png)

   **不能贪图知识广度, 注意学习深度和熟练度**
