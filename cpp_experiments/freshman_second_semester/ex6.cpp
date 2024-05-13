#include <iostream>
using namespace std;

template <typename T>
class DList
{
public:
    virtual void Insert(T item) = 0;
    virtual T Delete() = 0;
    virtual void Print() = 0;
};

template <typename T>
class DQueue : public DList<T>
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *front;
    Node *back;

public:
    DQueue() : front(nullptr), back(nullptr) {}
    void Insert(T item) override
    {
        Node *newNode = new Node{item, nullptr};
        if (back == nullptr)
            front = back = newNode;
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }
    T Delete() override
    {
        if (front == nullptr)
        {
            cerr << "Queue is empty!" << endl;
            exit(1);
        }
        T item = front->item;
        Node *temp = front;
        if (front == back)
            front = back = nullptr;
        else
            front = front->next;
        delete temp;
        return item;
    }
    void Print() override
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

template <typename T>
class DStack : public DList<T>
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *top;

public:
    DStack() : top(nullptr) {}
    void Insert(T item) override
    {
        Node *newNode = new Node{item, top};
        top = newNode;
    }
    T Delete() override
    {
        if (top == nullptr)
        {
            cerr << "Stack is empty!" << endl;
            exit(1);
        }
        T item = top->item;
        Node *temp = top;
        top = top->next;
        delete temp;
        return item;
    }
    void Print() override
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DList<int> *queue = new DQueue<int>();
    for (int i = 1; i <= 10; i++)
        queue->Insert(i);
    queue->Print();
    cout << queue->Delete() << endl;
    cout << queue->Delete() << endl;
    queue->Print();
    
    DList<int> *stack = new DStack<int>();
    for (int i = 1; i <= 10; i++)
        stack->Insert(i);
    stack->Print();
    cout << stack->Delete() << endl;
    cout << stack->Delete() << endl;
    stack->Print();
    return 0;
}
