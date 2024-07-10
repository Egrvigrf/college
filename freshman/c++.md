# 面向对象

## 对象
包含属性和行为，多个对象之间存在联系。

## 特性
1. 抽象
- 归纳共性
2. 封装
- 对象之间相互独立，互不干扰
- 隐蔽内部细节，只留下接口进行交互
3. 继承
- 提高代码重用性
4. 多态
- 不同对象对相同消息的响应不同

## 类的声明

类似于结构体的声明
```c++
struct Student {
    string name;
    int num;
};
```

```c++
class Student {
private:
    
public:
    void display();
};
```
## 三种成员
类中的私有成员是不能被外界直接访问，只能通过public中的函数间接访问或调用，保护成员和私有成员的区别在于能被继承，而公有成员可以被对象直接访问

定义对象(C++方式)
`Student stu1,stu2;`

## 成员函数

在类外定义成员函数要在名称前加上**作用域限符**(避免二义性)
`void Student::display() {...}`

类成员函数的存储
代码部分公用，数据部分单独存储（节省空间）
输出类对象占用的字节数
`cout<<sizeof(Student)<<endl;`

对象成员的引用

```c++
class Time {
public:
int hour,minite;
};
int main() {
    Time t1,*p;
    p = &t1;
    cout<<p->name<<" "<<(*p).name<<" "<<t1.name;
}

```
三种形式等价
`p->name` `(*p).name` `t1.name`  

引用访问(t2是t1的别名)
`Time &t2 = t1;`
`cout<<t2.hour<<endl`

### 构造函数
- 特殊的成员函数
- 名字与类名相同
- 在对象被创建时调用

可使用参数列表初始化
`Box::Box(int l, int w, int h) : length(l), width(w), hight(h) {...}`

### 析构函数
- 特殊的成员函数
- 名字为类名前加上~
- 在对象生命周期结束时执行
- 不能被重载，没有参数，不能定义类型，没有返回值

函数体推荐使用delete删除对象用new开辟的空间，因为销毁对象啊时系统会回收对象占用的空间而不会回收使用new开辟的空间

## this指针
- 指向当前对象的地址
- 隐式调用

## 静态成员
- 该类的所有对象共享同一个静态成员

在类外初始化,不能使用参数列表初始化
`int Box::height = 10;`

## 静态成员函数
- 和非静态成员函数的区别在于没有this指针
- 只能用于访问静态成员数据，不能访问非静态成员数据

## 友元
- 必须在类的定义中说明
- 可以访问类的所有成员

### 友元函数
```c++
class A {
private:
    int x,y;
public:
    A(int x,int y) : x(x),y(y) {}
    friend void display(A &);
};
void display(A &a) {
    cout<<a.x<<" "<<a.y;
}
int main() {
    IOS;
    A a(3,5);
    display(a);
    return 0;
}
```

### 友元成员函数
```c++
class B; //前向声明类
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
void A::display(B &b) { //用到了b的成员，必须在B声明之后
    cout<< b.x + b.y;
};
int main() {
    B b;
    A a;
    a.display(b);
    return 0;
}
```

### 友元类
```c++
class A {
public:
    friend class B;
    ...
}
class B {...}
```

- 关系是单向的(B的对象能访问A的对象的所有，反之不行)
- 友元关系不能传递（A是B的友元类，B是C的友元类，则A不是C的友元类）

## 运算符重载

```c++
operate+(int a, int b) {
    return a + b;
}
```

也是成员函数，名称是operate+

单目运算符：
只有一个操作数，但是要区分前后
```c++
class A
{ 
private:
    float x, y;
public:
   A(float a=0, float b=0){  x=a;  y=b;  }
   A operator ++( ){A  t;  t.x=++ x; t.y=++y;  return t;}
   A operator ++(int) {  A  t;  t.x=x++;  t.y=y++;  return t;}
};
void main(void) {
    A a(2,3), b;
    b = ++a;
    b = a++;
}
```

## 类型转换
```c++
class Complex {
    float real, image;
public:
    Complex(float r=0,float i=0)  {  real=r; image=i; }
    void Show(void) {cout<<"Real="<<Real<<'\t'<<"Image="<<Image<<endl;	}
    operator float();	//成员函数，定义类转换 Complex－>float
};
Complex::operator float()  {	return real*real+image*image;  }
void main(void)  {	
    Complex c(10,20);
    c.Show ();
    cout<<c<<endl;//可以直接输出c，因为已经进行类型转换	
}
```

## 继承

1. 基类(派生) -> 子类(继承) 

class 派生类名：[继承方式] 基类名 {
    派生类新增加的成员
};

### 继承方式(默认为private)

无论哪种继承方式
基类的私有成员无法被继承，为基类私有
1. public
基类的公用成员和保护成员在派生类中保持原有的访问属性
2. private
基类的公用成员和保护成员在派生类中成了私有成员
3. protected
基类的公有成员和保护成员在派生类中成了保护成员

- 派生类的成员函数可以访问派生类成员
- 基类的成员函数可以访问基类的成员，而不能访问派生类的成员
- 私有数据成员只能被同一类的成员函数访问

简单派生类的构造函数
`Student1(int n, string name, char s,int a,string ad) : Student(n,name,s),age(a),addr(ad) {}`

多重继承时，先执行基类的构造函数，再逐级往上执行
析构函数的执行顺序相反

单继承：一个类是从一个基类派生而来
多重继承：一个派生类有两个或多个基类
调用基类构造函数的顺序是按照声明派生类时基类出现的顺序

#### 二义性问题
多重继承出现重名，用::指定访问哪个基类
`c1.A::a = 3`
如果派生类中由同名的成员，那么基类的同名成员会被屏蔽，可以用::访问

## 虚基类
如果一个派生类有多个直接基类，而这些直接基类又有一个共同的基类，则在最终的派生类中会保留该间接共同基类数据成员的多份同名成员。

虚基类避免菱形继承问题，防止同一基类的多个实例

声明方式
class 派生类名: virtual 继承方式 基类名

## 多态

静态多态：
在编译时指定，比如函数重载

动态多态：在程序运行时指定，虚函数实现

### 虚函数
虚函数的作用是允许在派生类中重新定义与基类同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数
```c++
class Student {
public:
    Student(int, string, float);           //声明构造函数
    void display();                             //声明输出函数
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

```
不使用虚函数
num: 1001
name: Li
score: 87.5

num: 2001
name: Wang
score: 98.5

使用虚函数
num: 1001
name: Li
score: 87.5

num: 2001
name: Wang
score: 98.5
pay: 563.5

- 当一个成员函数被声明为虚函数后，其派生类中的同名函数都自动成为虚函数

静态关联和动态关联
1. 静态关联
静态关联：函数重载和通过对象名调用的虚函数，在编译时即可确定其调用的虚函数属于哪一个类，称为静态关联

2. 动态关联
动态关联：编译系统把它放到运行阶段处理，在运行阶段确定关联关系。在运行阶段，基类指针变量先指向了某一个类对象，然后通过此指针变量调用该对象中的函数。此时调用哪一个对象的函数无疑是确定的。由于是在运行阶段把虚函数和类对象“绑定”在一起的，因此，此过程称为动态关联

在运行阶段，指针可以先后指向不同的类对象，从而调用同一类族中不同类的虚函数。由于动态关联是在编译以后的运行阶段进行的，因此也称为滞后关联

什么时候使用虚函数
只能用virtual声明类的成员函数，使它成为虚函数，而不能将类外的普通函数声明为虚函数。因为虚函数的作用是允许在派生类中对基类的虚函数重新定义。显然，它只能用于类的继承层次结构中
一个成员函数被声明为虚函数后，在同一类族中的类就不能再定义一个非virtual的但与该虚函数具有相同的参数(包括个数和类型)和函数返回值类型的同名函数

### 纯虚函数
纯虚函数和抽象基类是C++中实现抽象和多态性的重要工具。它们在面向对象编程中用于定义接口和实现多态行为。

纯虚函数
纯虚函数是一种没有实现的虚函数，必须在派生类中进行实现。纯虚函数通过在函数声明的末尾添加 = 0 来表示。定义一个纯虚函数的类是抽象类，不能实例化。
```c++
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0; // 纯虚函数
};
```
在这个例子中，pureVirtualFunction 是一个纯虚函数，这意味着任何派生自 AbstractClass 的类都必须实现这个函数，否则该派生类也将成为抽象类，无法实例化。

有纯虚函数的类不能直接建立对象，必须继承后实现有纯虚函数的部分才能用派生类创建对象

抽象基类
抽象基类是包含至少一个纯虚函数的类。抽象基类用于定义接口，并强制派生类实现这些接口。由于包含纯虚函数，抽象基类不能被实例化。

```c++
#include <iostream>
#include <string>
using namespace std;

// 定义一个抽象基类 Shape，包含一个纯虚函数 draw
class Shape {
public:
    virtual void draw() = 0; // 纯虚函数
};

// Circle 类继承自 Shape，并实现了 draw 函数
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Square 类继承自 Shape，并实现了 draw 函数
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    // 创建 Circle 和 Square 对象，并使用 Shape 指针指向它们
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    
    shape1->draw(); // 输出：Drawing a Circle
    shape2->draw(); // 输出：Drawing a Square
    
    // 释放内存
    delete shape1;
    delete shape2;
    
    return 0;
}
```