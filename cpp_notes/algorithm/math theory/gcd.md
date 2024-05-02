## 辗转相除求gcd
>    辗转相除：
>    设a>b（a<b也同理，执行一次后变为a>b,%的特性）
>   设x为他们的最大公因数，则a/x =y1 && b/x=y2,(y1>y2)
>   则(a-b)/x = y3
>   y1,y2,y3都是正整数
>   所以gcd(a,b) = gcd(b,a-b) 多次操作-> gcd(a,b) = gcd(b,a%b),(等效)
>   a%b == 0时b为gcd
>   这时下一次操作,a=原先的b,b = 0,
>   运行到最后必有b=0
>   此外，LCM(a,b) = a*b/GCD(a,b)
## 源代码
```c++
#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int GCD2(int a, int b)
{
    return a % b == 0 ? b : GCD2(b, a % b);
}
int main()
{
    long long a, b;
    cin >> a >> b;
    long long LCM = a / GCD(a, b) * b;
    cout << LCM << endl;
    cout << GCD2(a, b);
    return 0;
}
```