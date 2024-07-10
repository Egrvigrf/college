#include <bits/stdc++.h>
#if !defined(ONLINE_JUDGE) && defined(LOCAL)
#include "debug.h"
#else
#define dbg(...) ((void)0)
#define dbg_ctn(v) ((void)0)
#endif
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define _for(i,start,end) for(int i = (start); i < (end); i++)
#define _rep(i,start,end) for(int i = (start); i <= (end); i++)
#define for_(i,end,start) for(int i = (end); i > (start); i--)
#define rep_(i,end,start) for(int i = (end); i >= (start); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inf 0x3f3f3f3f // 1e9
#define endl '\n'

class B;
class A {
public:
    void display(B &);
};

class B {
private:
    int x,y;
public:
    B() {
        x = 1,y =1;
    }
    friend void A::display(B &b);
};
void A::display(B &b) {
    cout<< b.x + b.y;
};
int main() {
    IOS;
    B b;
    A a;
    a.display(b);
    return 0;
}

/**
 * author:  Egrvigrf
 * created: 2024-07-10 08:55
**/