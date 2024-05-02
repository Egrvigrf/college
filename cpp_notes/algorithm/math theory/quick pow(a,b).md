# 快速幂

## 源代码
```c++
#include <bits/stdc++.h> //% 优先级低于 * /
using namespace std;     //(a+b)%p = (a%p+b%p)%p 取模为减去能被整除后剩下的，除为连续相减，乘为连续相加
int power(int a, int b)  // 求a^b O(n) -> O(logn) (a^b)%p = ((a%d)^b)%p
{                        //(a^b)%p = ((a1*d+r)^b)%p 二项展开后只有一项 r^b 不能被整除，r = a%p
    int ans = 1;         // a*b%p = (n1*p+a1)*(n2*p+b1)%p = a1*b1%p = (a%p)*(b%p)%p
    while (b != 0)
    {
        if (b % 2)
        {
            ans *= a; // ans = ans*a%p
            // 如果要对最终结果求余，化作对每一步求余 (((a^2)%p)^(b/2))%p = (a^b)%p
        }
        a *= a; // a = a*a%p
        b /= 2;
    }
    return ans;
}
int power2(int a, int b)
{
    int ans;
    if (b == 0)
        ans = 1;
    else
    {
        ans = power2(a * a, b / 2);
        if (b % 2)
            ans *= a;
    }
    return ans;
}
int main()
{
    cout << power2(2, 31) - 1;
    return 0;
}
```