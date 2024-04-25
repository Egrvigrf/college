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
        cout << "~Dlist() Done";
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
    int l() { return len; }
};
template <typename T>
class DStack : public DList<T>
{
    private:
    public:
        DStack():DList<T>() {}
        void pop()
        {
            this->discard(this->l()); 
        }
        T top()
        {
            return this->get(this->l()); 
        }
};
int main()
{
    DStack<int> l;
    for (int i = 1; i <= 10; i++)
        l.append(i);
    l.printDList();
    cout << endl;
    cout << l.top() << endl;
    l.pop();
    l.printDList();
    cout << endl;
    return 0;
}