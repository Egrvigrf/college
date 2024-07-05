#include <bits/stdc++.h>
using namespace std;
template <typename T>
class DList
{
private:
    struct Node
    {
        T item;
        Node *next = nullptr;
        Node *pre = nullptr;
    };
    int len;
    Node *head;
    Node *tail;

public:
    DList() : len(0), head(nullptr), tail(nullptr) {}
    DList(const DList &d2) : len(0), head(nullptr), tail(nullptr)
    {
        Node *current = d2.head;
        while (current != nullptr)
        {
            append(current->item);
            current = current->next;
        }
    }
    DList &operator=(const DList &d2)
    {
        if (this == &d2)
            return *this;
        Node *p = head;
        while (p != nullptr)
        {
            Node *next = p->next;
            delete p;
            p = next;
        }
        head = nullptr;
        tail = nullptr;
        len = 0;
        Node *current = d2.head;
        while (current != nullptr)
        {
            append(current->item);
            current = current->next;
        }
        return *this;
    }
    ~DList()
    {
        Node *p = head;
        Node *t = p->next;
        while (t->next != nullptr)
        {
            delete p;
            p = t;
            t = t->next;
        }
        delete p;
        delete t;
        cout << "析构函数被执行！";
    }
    void append(T x)
    {
        Node *t = new Node;
        t->item = x;
        if (len == 0)
        {
            head = t;
            tail = t;
        }
        else
        {
            t->pre = tail;
            tail->next = t;
            tail = t;
        }
        len++;
    }
    void discard(int index)
    {
        if (index == 1)
        {
            Node *t = head;
            head = head->next;
            head->pre = nullptr;
            delete t;
        }
        else if (index == len)
        {
            Node *t = tail;
            tail = tail->pre;
            tail->next = nullptr;
            delete t;
        }
        else
        {
            Node *t = head;
            while (--index)
                t = t->next;
            (t->pre)->next = t->next;
            (t->next)->pre = t->pre;
        }
        len--;
    }
    int find(T x)
    {
        int count = 1;
        Node *t = head;
        if (head->item == x)
            return 1;
        while (t->item != x)
        {
            t = t->next;
            count++;
        }
        return count;
    }
    void insert(int index, T x)
    {
        Node *t = new Node;
        t->item = x;
        if (index == 0)
        {
            t->next = head;
            head = t;
        }
        else if (index == len)
        {
            tail->next = t;
            t->pre = tail;
            tail = t;
        }
        else
        {
            Node *tmp = head;
            while (--index)
                tmp = tmp->next;
            t->pre = tmp;
            t->next = tmp->next;
            (t->next)->pre = t;
            tmp->next = t;
        }
    }
    T get(int index)
    {
        if (index == 1)
        {
            return head->item;
        }
        else
        {
            Node *t = head;
            while (--index)
                t = t->next;
            return t->item;
        }
    }
    void printDList()
    {
        Node *t = head;
        while (t != nullptr)
        {
            cout << t->item << " ";
            t = t->next;
        }
    }
};
int main()
{
    DList<int> l;
    for (int i = 1; i <= 20; i++)
        l.append(i);
    DList<int> l2(l);
    DList<int> l3;
    cout << "对第一个Dlist对象l的操作:\n";
    l.printDList();
    cout << "\n"
         << l.get(10) << "\n";
    l.discard(10);
    l.printDList();
    cout << "\n";
    cout << l.find(1);
    l.insert(9, 10);
    cout << "\n";
    l.printDList();
    cout << endl;
    cout << "对第二个Dlist对象l2的操作以检验l2是否被完全复制:\n";
    l2.printDList();
    cout << "\n"
        << l2.get(10) << "\n";
    l2.discard(10);
    l2.printDList();
    cout << "\n";
    cout << l2.find(1);
    l2.insert(9, 10);
    cout << "\n";
    l2.printDList();
    l3 = l2;
    cout << "\n打印第三个Dlist对象l3的内容以检验=运算符是否被正确重载:\n";
    l3.printDList();
    cout << "\n";
    return 0;
}