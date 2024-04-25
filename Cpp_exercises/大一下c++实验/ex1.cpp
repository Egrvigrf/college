#include <iostream>
using namespace std;
template <typename Temp>
class Slist
{
private:
    int len, capacity;
    Temp *p;

public:
    Slist() : len(0), capacity(10)
    {
        p = new Temp[capacity];
    }
    void append(Temp x)
    {
        len++;
        if (len == capacity)
        {
            capacity *= 2;
            Temp *np = new Temp[capacity];
            for (int i = 0; i <= len - 2; i++)
            {
                *(np + i) = *(p + i);
            }
            *(np + len - 1) = x;
            delete[] p;
            p = np;
        }
        else
        {
            *(p + len - 1) = x;
        }
    }
    void del(int index)
    {
        if ((index == 0 && len == 1) || (len > 1 && len == index - 1))
        {
            len--;
        }
        else if (index > 0)
        {
            for (int i = index; i <= len - 2; i++)
            {
                *(p + i) = *(p + i + 1);
            }
            len--;
        }
    }
    void print()
    {
        if (!is_empty())
        {
            for (int i = 0; i <= len - 1; i++)
            {
                cout << *(p + i) << " ";
            }
        }
    }
    bool is_empty()
    {
        return len == 0 ? true : false;
    }
    int length()
    {
        return len;
    }
	int find(Temp x)
    {
        int index = -1;
        for (int i = 0; i <= len - 1; i++)
        {
            if (*(p + i) == x)
            {
                index = i;
                break;
            }
        }
        return index;
    }
};
int main()
{
    Slist<int> t1;
    for (int i = 1; i <= 10; i++)
    {
        t1.append(i);
    }
   
    cout <<"循环输入元素并输出全部元素："<< endl;
	t1.print();
	cout<<endl;
    cout <<"输出长度："<< t1.length() << endl;
    cout <<"判断是否为空："<< t1.is_empty() << endl;
    cout<<"查找值为3的元素索引："<<t1.find(3)<<endl;
	t1.del(4);
    cout<<"输出删除索引4的元素的结果："<<endl;
	t1.print();
    return 0;
}