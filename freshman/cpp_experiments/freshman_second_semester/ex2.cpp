#include <iostream>
using namespace std;
template <typename T>
class DList
{
private:
    struct Node
    {
        T item;
        Node *next;
        Node *pre;
    };
	int len;
    Node *head;
    Node *tail;
public:
    DList() : len(0), head(0), tail(0) {}
    ~DList()
    {
        Node *p = head;
        Node *t = p->next;
        while (t->next != 0)
        {
            delete p;
            p = t;
            t = t->next;
        }
        delete p;
        delete t;
        cout << "构析函数已执行完成";
    }
    void append(T x)
    {
        Node *t = new Node;
		t->next = 0;
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
            head->pre = 0;
            delete t;
        }
        else if (index == len)
        {
            Node *t = tail;
            tail = tail->pre;
            tail->next = 0;
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
        while (t != 0)
        {
            cout << t->item << " ";
            t = t->next;
        }
    }
};
int main()
{
    DList<int> l;
	cout<<"添加元素并输出：\n";
    for (int i = 1; i <= 20; i++)
        l.append(i);
    l.printDList();
	cout<<"\n查询位置为2的元素值：";
    cout << "\n"
         << l.get(2) << "\n";
	cout<<"删除位置为10的元素并输出：\n";
    l.discard(10);
    l.printDList();
    cout << "\n";
	cout<<"查找元素值为5的元素位置：\n";
    cout << l.find(5)<<"\n";
	cout<<"在第15号元素后面插入100并输出：\n";
    l.insert(15, 100);
    l.printDList();
	cout<<"\n";
    return 0;
}