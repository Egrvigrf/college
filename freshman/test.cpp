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

class Student {
public:
    Student(int, string, float);           //声明构造函数
    virtual void display();                             //声明输出函数
protected:                                      //受保护成员，派生类可以访问 
    int num;  
    string name;   
    float score;
};

// Student类成员函数的实现
Student::Student(int n, string nam, float s) {                     //定义构造函数
    num = n;
    name = nam;
    score = s;
}

void Student::display() {                                        //定义输出函数
    cout << "num: " << num << "\nname: " << name << "\nscore: " << score << "\n\n";
}

class Graduate : public Student {   //声明公用派生类Graduate 
public:
    Graduate(int, string, float, float);              //声明构造函数
    void display();                                             //声明输出函数
private:
    float pay;
};

// Graduate类成员函数的实现
Graduate::Graduate(int n, string nam, float s, float p) :
    Student(n, nam, s), pay(p) {}

void Graduate::display() {                                      //定义输出函数
    cout << "num: " << num << "\nname: " << name << "\nscore: " << score
        << "\npay: " << pay << endl;
}

int main() {
    Student stud1(1001, "Li", 87.5);                   //定义Student类对象stud1
    Graduate grad1(2001, "Wang", 98.5, 563.5); //定义Graduate类对象grad1
    Student* pt = &stud1;                              //定义指向基类对象的指针变量pt
    pt->display();
    pt = &grad1;
    pt->display();
    return 0;
}

/**
 * author:  Egrvigrf
 * created: 2024-07-09 23:24
**/