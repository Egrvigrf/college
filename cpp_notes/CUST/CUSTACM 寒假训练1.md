# CUSTACM 寒假训练1



## 时间复杂度与空间复杂度

**算法中的基本操作的执行次数，称为算法的时间复杂度。**

一秒可以处理1e8

O(1)

O($n$)																$n<1e8$

O($n*\log_2 n$)											 	$n<=1e6$

O($n*\sqrt{n}$ or $n*(\log_2 n)^2$)						$n<1e5$

O($n^2$)														  	$n<5000$

O($n^3$)														  	$n<300$

O($2^n$)													      	$n<25$

O($n!$)												   			$n<11$

**对算法在运行过程中临时占用存储空间大小的度量。**

![1704681380927](D:\微信\WeChat Files\wxid_i7osohhqpgpt21\FileStorage\Temp\1704681380927.png)

可以开$1.6e7$的一维数组 或者 4000*4000的二维数组



## 模拟

**顾名思义 就是将题意写成代码**

模拟题目通常具有码量大、操作多、思路繁复的特点。由于它码量大，经常会出现难以查错的情况，如果在考试中写错是相当浪费时间的。

tips：

- 在动手写代码之前，在草纸上尽可能地写好要实现的流程。
- 在代码中，尽量把每个部分模块化，写成函数、结构体或类。
- 对于一些可能重复用到的概念，可以统一转化，方便处理：如，某题给你 "YY-MM-DD 时：分" 把它抽取到一个函数，处理成秒，会减少概念混淆。
- 调试时分块调试。模块化的好处就是可以方便的单独调某一部分。
- 写代码的时候一定要思路清晰，不要想到什么写什么，要按照落在纸上的步骤写。



## 枚举

枚举（英语：Enumerate）是基于已有知识来猜测答案的一种问题求解策略。

枚举的思想是不断地猜测，从可能的集合中一一尝试，然后再判断题目的条件是否成立。



## 双指针

**双指针（Two Pointers）**：指的是在遍历元素的过程中，不是使用单个指针进行访问，而是使用两个指针进行访问，从而达到相应的目的。如果两个指针方向相反，则称为「对撞指针」。如果两个指针方向相同，则称为「快慢指针」。如果两个指针分别属于不同的数组 / 链表，则称为「分离双指针」。

**对撞指针**：指的是两个指针 `left`、`right` 分别指向序列第一个元素和最后一个元素，然后 `left` 指针不断递增，`right` 不断递减，直到两个指针的值相撞（即 `left == right`），或者满足其他要求的特殊条件为止。

1.使用两个指针 left，right。left 指向序列第一个元素，即：left = 0，right 指向序列最后一个元素，即：right = len(nums) - 1。

2.在循环体中将左右指针相向移动，当满足一定条件时，将左指针右移，left += 1。当满足另外一定条件时，将右指针左移，right -= 1。

3.直到两指针相撞（即 left == right），或者满足其他要求的特殊条件时，跳出循环体。

对撞指针一般用来解决有序数组或者字符串问题：

**快慢指针**：指的是两个指针从同一侧开始遍历序列，且移动的步长一个快一个慢。移动快的指针被称为 「快指针（fast）」，移动慢的指针被称为「慢指针（slow）」。两个指针以不同速度、不同策略移动，直到快指针移动到数组尾端，或者两指针相交，或者满足其他特殊条件时为止。

1.使用两个指针 slow、fast。slow 一般指向序列第一个元素，即：slow = 0，fast 一般指向序列第二个元素，即：fast = 1。

2.在循环体中将左右指针向右移动。当满足一定条件时，将慢指针右移，即 slow += 1。当满足另外一定条件时（也可能不需要满足条件），将快指针右移，即 fast += 1。

3.到快指针移动到数组尾端（即 fast == len(nums) - 1），或者两指针相交，或者满足其他特殊条件时跳出循环体。

**分离双指针**：两个指针分别属于不同的数组 / 链表，两个指针分别在两个数组 / 链表中移动。

使用两个指针 left_1、left_2。left_1 指向第一个数组 / 链表的第一个元素，即：left_1 = 0，left_2 指向第二个数组 / 链表的第一个元素，即：left_2 = 0。

1.当满足一定条件时，两个指针同时右移，即 left_1 += 1、left_2 += 1。

2.当满足另外一定条件时，将 left_1 指针右移，即 left_1 += 1。

3.当满足其他一定条件时，将 left_2 指针右移，即 left_2 += 1。

4.当其中一个数组 / 链表遍历完时或者满足其他特殊条件时跳出循环体。



## 链表

链表是一种用于存储数据的数据结构，通过如链条一般的指针来连接元素。

它的特点是插入与删除数据十分方便，但寻找与读取数据的表现欠佳。

~~~c++
struct Node {//单向链表
  int value;
  Node *next;
};
~~~



![img](https://oi-wiki.org/ds/images/list.svg)

~~~c++
struct Node {//双向链表
  int value;
  Node *left;
  Node *right;
};
~~~

![img](https://oi-wiki.org/ds/images/double-list.svg)

~~~c++
void insertNode(int i, Node *p) {//循环链表
  Node *node = new Node;
  node->value = i;
  node->next = NULL;
  if (p == NULL) {
    p = node;
    node->next = node;
  } else {
    node->next = p->next;
    p->next = node;
  }
}
~~~



## 队列

队列（queue）先进先出

![img](https://oi-wiki.org/ds/images/queue.svg)

## 堆

堆是一棵树，其每个节点都有一个键值，且每个节点的键值都大于等于/小于等于其父亲的键值。

每个节点的键值都大于等于其父亲键值的堆叫做小根堆，否则叫做大根堆。[STL 中的 `priority_queue`](https://oi-wiki.org/lang/csl/container-adapter/#优先队列) 其实就是一个大根堆。

![img](https://img-blog.csdnimg.cn/1809e5226c984dceaff25722ab12556b.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAT3dlbl9YcA==,size_20,color_FFFFFF,t_70,g_se,x_16)



## 栈

栈（stack）先进后出

![img](https://oi-wiki.org/ds/images/stack.svg)



## STL

### vector

动态数组

~~~c++
#include<vector>

vector<int> a; //定义了一个名为a的一维数组,数组存储int类型数据
vector<double> b;//定义了一个名为b的一维数组，数组存储double类型数据
vector<node> c;//定义了一个名为c的一维数组，数组存储结构体类型数据，node是结构体类型

vector<int> v(n);// 定义一个长度为n的数组，初始值默认为0，下标范围[0, n - 1]
vector<int> v(n, 1);// v[0] 到 v[n - 1]所有的元素初始值均为1
//注意：指定数组长度之后（指定长度后的数组就相当于正常的数组了）

vector<int> a{1, 2, 3, 4, 5};//数组a中有五个元素，数组长度就为5

vector<int> a(n + 1, 0);
vector<int> b(a); // 两个数组中的类型必须相同,a和b都是长度为n+1，初始值都为0的数组
vector<int> c = a; // 也是拷贝初始化,c和a是完全一样的数组

vector<int> v[5];//定义可变长二维数组
//注意：行不可变（只有5行）, 而列可变,可以在指定行添加元素
//第一维固定长度为5，第二维长度可以改变

//初始化二维均可变长数组
vector<vector<int>> v;//定义一个行和列均可变的二维数组
vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));//行列长度均固定 n + 1行 m + 1列初始值为0
vector a(n + 1, vector(m + 1, 0));//与上面的相同 C++17与C++20支持
~~~

~~~C++
c.front()							返回第一个数据O(1)
c.back()							返回数组中的最后一个数据O(1)
c.pop_back()						删除最后一个数据O(1)
c.push_back(element)				在尾部加一个数据O(1)
c.size()							返回实际数据个数（unsigned类型）O(1)
c.clear()							清除元素个数O(N)，N为元素个数
c.resize(n, v)						改变数组大小为n,n个空间数值赋为v，如果没有默认赋值为0
c.insert(it, x)						向任意迭代器it插入一个元素x ，O(N)
//例：c.insert(c.begin() + 2,-1)	   将-1插入c[2]的位置
c.erase(first,last)					删除[first,last)的所有元素，O(N)
c.begin()							返回首元素的迭代器（通俗来说就是地址）O (1)
c.end()								返回最后一个元素后一个位置的迭代器（地址）O(1)
c.empty()							判断是否为空，为空返回真，反之返回假 O(1)
sort(c.begin(), c.end())
~~~

访问：

1.下标访问:

2.迭代器访问:

~~~C++
vector<int>::iterator it;   
// 相当于声明了一个迭代器类型的变量it
// 通俗来说就是声明了一个指针变量

vector<int>::iterator it = vi.begin(); 
for(int i = 0; i < 5; i++)cout << *(it + i) << " ";
for(int i = 0; i < 5; i++)cout << v[i] << " ";
vector<int>::iterator it;
for(it = vi.begin(); it != vi.end();it ++)cout << *it << " ";
for(it=vi.rbegin();it!=vi.rend();i++)
//vi.end()指向尾元素地址的下一个地址

// 或者
auto it = vi.begin();
while (it != vi.end()) {
    cout << *it << "\n";
    it++;
}
~~~

3.auto:

~~~C++
vector<int> a(n);
for (auto &x: a) {
    cin >> x; // 可以进行输入，注意加引用
}

for(auto i : a) {
	cout << i << " ";
}
~~~

`vector`注意：

- `vi[i]` 和 `*(vi.begin() + i)` 等价，与指针类似。
- `vector`和`string`的`STL`容器支持`*(it + i)`的元素访问，其它容器可能也可以支持这种方式访问，但用的不多，可自行尝试。



### stack

栈

~~~C++
#include<stack>

stack<int> s;
stack<string> s;
stack<node> s;//node是结构体类型
struct stack{
    int size;
    int tot;
    v[maxn];
}
~~~

~~~C++
s.push(ele)						元素ele入栈，增加元素O(1) tot++; v[tot]=ele;
s.pop()							移除栈顶元素O(1)   tot--;
s.top()							取得栈顶元素（但不删除）O(1)
s.empty()						检测栈内是否为空，空为真 O(1)
s.size()						返回栈内元素的个数 O(1)
~~~



### queue

队列

~~~C++
#include<queue>

queue<int> q;
~~~

~~~c++
q.front()							返回队首元素 O(1) v[0]
q.back()							返回队尾元素 O(1) v[tot]
q.push(element)						尾部添加一个元素element进队 O(1)  tot++; v[tot]=ele;
q.pop()								删除第一个元素 出队 O(1)   
q.size()							返回队列中元素个数，返回值类型unsigned int O(1)
q.empty()							判断是否为空，队列为空，返回true O(1)
~~~



### deque

双端队列 首尾都可插入和删除

~~~C++
#include<deque>

deque<int> dq;
~~~

~~~C++
push_back(x)/push_front(x)					把x插入队尾后/队首 O(1)
back()/front()								返回队尾/队首元素 O(1)
pop_back()/pop_front()						删除队尾/队首元素 O(1)
auto  it=find(x)
erase(iterator it)							删除双端队列中的某一个元素
erase(iterator first,iterator last)			删除双端队列中[first,last)中的元素
empty()										判断deque是否空 O(1)
size()										返回deque的元素数量 O(1)
clear()										清空deque
~~~

~~~C++
sort(q.begin(), q.end())//从小到大

sort(q.begin(), q.end(), greater<int>());//从大到小排序
sort(q.begin(), q.end(), greater());//高版本C++才可以用
~~~



### map

映射

~~~C++
#include<map>
map<pair<int,int>,int>ma;
map<string, string> mp;
map<string, int> mp;
map<int, node> mp;//node是结构体类型
~~~

~~~C++
mp.find(key)	返回键为key的映射的迭代器O(logN)
注意：用find函数来定位数据出现位置，它返回一个迭代器。当数据存在时，返回数据所在位置的迭代器，数据不存在时，返回mp.end ()
mp.erase(it)	删除迭代器对应的键和值O(1)
mp.erase(key)	根据映射的键删除键和值 O(logN)
mp.erase(first,last)	删除左闭右开区间迭代器对应的键和值 O(last−first)
mp.size()	返回映射的对数O(1)
mp.clear()	清空map中的所有元素O(N)
mp.insert()	插入元素，插入时要构造键值对
mp.empty()	如果map为空，返回true，否则返回false
mp.begin()	返回指向map第一个元素的迭代器（地址）
mp.end()	返回指向map尾部的迭代器（最后一个元素的下一个地址）
mp.rbegin()	返回指向map最后一个元素的迭代器（地址）
mp.rend()	返回指向map第一个元素前面(上一个）的逆向迭代器（地址）
mp.count(key)	查看元素是否存在，因为map中键是唯一的，所以存在返回1，不存在返回0
mp.lower_bound()	返回一个迭代器，指向键值>= key的第一个元素
mp.upper_bound()	返回一个迭代器，指向键值> key的第一个元素
~~~

~~~C++
for(auto it=mp.begin();it!=mp.end();it++)cout << it->first << " " << it->second << "\n";//正序
for(auto it=mp.rbegin();it!=mp.rend();it++)cout << it->first << " " << it->second << "\n";//反序
for(auto i : mp)cout << i.first << " " << i.second << endl;//键，值
for(auto [x, y] : mp)cout << x << " " << y << "\n";//x,y对应键和值
~~~

**map**：内部用**红黑树**实现，具有**自动排序**（按键从小到大）功能。

**unordered_map**：内部用**哈希表**实现，内部元素无序杂乱。

**multimap**：键可以重复，即一个键对应多个值

map：

优点：内部用红黑树实现，内部元素具有有序性，查询删除等操作复杂度为O(logN)

缺点：占用空间，红黑树里每个节点需要保存父子节点和红黑性质等信息，空间占用较大。

unordered_map：

优点：内部用哈希表实现，查找速度非常快（适用于大量的查询操作）。
缺点：建立哈希表比较耗时。

- 使用`[]`查找元素时，如果元素不存在，两种容器**都是**创建一个空的元素；如果存在，会正常索引对应的值。所以如果查询过多的不存在的元素值，容器内部会创建大量的空的键值对，后续查询创建删除效率会**大大降低**。
- 查询容器内部元素的最优方法是：先判断存在与否，再索引对应值（适用于这两种容器）

map可以进行二分查找

~~~C++
lower_bound() upper_bound()
~~~



### priority_queue

优先队列是在正常队列的基础上加了优先级，保证每次的队首元素都是优先级最大的。

可以实现每次从优先队列中取出的元素都是队列中**优先级最大**的一个。

它的底层是通过**堆**来实现的。

~~~C++
#include<queue>

priority_queue<int> q;
~~~

~~~C++
q.top()								访问队首元素 O(1)
q.push()							入队 O(logN)
q.pop()								堆顶（队首）元素出队 O(logN)
q.size()							队列元素个数 O(1)
q.empty()							是否为空 O(1)
注意没有clear()！   不提供该方法
优先队列只能通过top()访问队首元素（优先级最高的元素）
~~~

~~~C++
priority_queue<int> pq; // 默认大根堆, 即每次取出的元素是队列中的最大值
priority_queue<int, vector<int>, greater<int>> q; // 小根堆, 每次取出的元素是队列中的最小值
less<int> 表示数字大的优先级大，堆顶为最大的数字
greater<int>表示数字小的优先级大，堆顶为最小的数字
int代表的是数据类型，也要填优先队列中存储的数据类型
自定义排序：
//定义的比较结构体
//注意：cmp是个结构体 
struct cmp {//自定义堆的排序规则 
	bool operator()(const Point& a,const Point& b) {
		return a.x < b.x;
	}
};
//初始化定义， 
priority_queue<Point, vector<Point>, cmp> q; // x大的在堆顶

默认先对pair的first进行降序排序，然后再对second降序排序
对first先排序，大的排在前面，如果first元素相同，再对second元素排序，保持大的在前面。
~~~



### set

set容器中的元素不会重复，当插入集合中已有的元素时，并不会插入进去，而且set容器里的元素自动从小到大排序。

~~~C++
#include<set>

set<int> s;
~~~

~~~c++
s.begin()			返回set容器的第一个元素的地址（迭代器）O(1)
s.end()				返回set容器的最后一个元素的下一个地址（迭代器）O(1)
s.rbegin()			返回逆序迭代器，指向容器元素最后一个位置O(1)
s.rend()			返回逆序迭代器，指向容器第一个元素前面的位置O(1)
s.clear()			删除set容器中的所有的元素,返回unsigned int类型 O(N)
s.empty()			判断set容器是否为空O(1)
s.insert()			插入一个元素
s.size()			返回当前set容器中的元素个数O(1)
erase(iterator)		删除定位器iterator指向的值
erase(first,second）	删除定位器first和second之间的值
erase(key_value)	删除键值key_value的值
查找
s.find(element)		查找set中的某一元素，有则返回该元素对应的迭代器，无则返回结束迭代器
s.count(element)	查找set中的元素出现的个数，由于set中元素唯一，此函数相当于查询element是否出现
s.lower_bound(k)	返回大于等于k的第一个元素的迭代器O(logN)
s.upper_bound(k)	返回大于k的第一个元素的迭代器O(logN)
~~~

迭代器访问与之前相同

~~~c++
set<int> s1; // 默认从小到大排序
set<int, greater<int> > s2; // 从大到小排序
~~~

`multiset`:元素可以重复，且元素有序

`unordered_set` ：元素无序且只能出现一次

`unordered_multiset` ： 元素无序可以出现多次



### pair

pair只含有两个元素，可以看作是只有两个元素的结构体。

~~~c++
#include<utility>
pair<int,int>pa
struct node{
    int firse,second;
}pa;
pair<string, int> p("wangyaqi",1);//带初始值的
pair<string, int> p;//不带初始值的

p = {"wang", 18};
p = make_pair("wang", 18);
p = pair<string, int>("wang", 18);

map<string, int> mp;
mp.insert(pair<string, int>("xingmaqi",1));
// mp.insert(make_pair("xingmaqi", 1));
// mp.insert({"xingmaqi", 1});

//定义结构体数组
pair<int,int> p[20];
for(int i = 0; i < 20; i++) {
	//和结构体类似，first代表第一个元素，second代表第二个元素
	cout << p[i].first << " " << p[i].second;
}
~~~



### string

string是一个字符串类，和`char`型字符串类似。

~~~c++
#include<string>

string str1; //生成空字符串

string str2("123456789"); //生成"1234456789"的复制品 

string str3("12345", 0, 3);//结果为"123" ，从0位置开始，长度为3

string str4("123456", 5); //结果为"12345" ，长度为5

string str5(5, '2'); //结果为"22222" ,构造5个字符'2'连接而成的字符串

string str6(str2, 2); //结果为"3456789"，截取第三个元素（2对应第三位）到最后
~~~

~~~c++
string字符串支持常见的比较操作符（>,>=,<,<=,==,!=），支持string与C-string的比较（如 str < "hello"）。

string s = s1 + s2;
~~~

~~~C++
cin >> s;//遇到回车结束

getline(cin, s);//读一行
~~~

~~~C++
s.size()和s.length()			返回string对象的字符个数，他们执行效果相同。
s.max_size()				返回string对象最多包含的字符数，超出会抛出length_error异常
s.capacity()				重新分配内存之前，string对象能包含的最大字符数
s.push_back()				在末尾插入
例：s.push_back('a')		   末尾插入一个字符a
s.insert(pos,element)		在pos位置插入element
例：s.insert(s.begin(),'1')  在第一个位置插入1字符
s.append(str)				在s字符串结尾添加str字符串
例：s.append("abc")		   在s字符串末尾添加字符串“abc”
    
auto p=find("abc")
erase(iterator p)			删除字符串中p所指的字符
erase(iterator first, iterator last)	删除字符串中迭代器区间[first,last)上所有字符
erase(pos, len)				删除字符串中从索引位置pos开始的len个字符
clear()						删除字符串中所有字符
s=""                                                    
s.replace(pos,n,str)		把当前字符串从索引pos开始的n个字符替换为str
s.replace(pos,n,n1,c)		把当前字符串从索引pos开始的n个字符替换为n1个字符c
s.replace(it1,it2,str)		把当前字符串[it1,it2)区间替换为str it1 ,it2为迭代器哦
tolower(s[i])				转换为小写
toupper(s[i])				转换为大写
s.substr(pos,n)				截取从pos索引开始的n个字符
s.find (str, pos)	在当前字符串的pos索引位置（默认为0）开始，查找子串str，返回找到的位置索引，-1表示查找不到子串
s.find (c, pos)		在当前字符串的pos索引位置（默认为0）开始，查找字符c，返回找到的位置索引，-1表示查找不到字符
s.rfind (str, pos)	在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，-1表示查找不到子串
s.rfind (c,pos)		在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符
s.find_first_of (str, pos)	在当前字符串的pos索引位置（默认为0）开始，查找子串s的字符，返回找到的位置索引，-1表示查找不到字符
s.find_first_not_of (str,pos)	在当前字符串的pos索引位置（默认为0）开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
s.find_last_of(str, pos)	在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符
s.find_last_not_of ( str, pos)	在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串
~~~

~~~C++
sort(s.begin(),s.end());  //按ASCII码排序
~~~





### lower_bound() upper_bound()

~~~C++
这两个二分查找操作可以在set，数组，vector，map中使用；

数组 或者 vector 中的语法：
序列是升序的（从小到大）
vector<int>ve;//10
lower_bound(ve.begin(),ve.end(),x)-ve.begin;
lower_bound(begin(),end(),x) //返回序列中第一个大于等于x的元素的地址
upper_bound(begin(),end(),x) //返回序列中第一个大于x的元素的地址

序列是降序的（从大到小）
lower_bound(begin(),end(),x,greater<tpye>()) //返回序列中第一个小于等于x的元素的地址
upper_bound(begin(),end(),x,greater<type>()) //返回序列中第一个小于x的元素的地址

set 或者 map 中的语法：
    auto it;
和数组差不多，只不过返回的是迭代器：
s.lower_bound(x) //返回序列中第一个大于等于x的元素的地址
s.upper_bound(x) //返回序列中第一个大于x的元素的地址

 
重点注意：如果当前序列中找不到符合条件的元素，那么返回end(),对于数组来说，返回查询区间的首地址位置，对于set来讲，返回end()-1后面元素的迭代器，也就是begin();
~~~

