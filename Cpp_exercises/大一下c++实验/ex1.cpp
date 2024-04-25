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
   
    cout <<"ѭ������Ԫ�ز����ȫ��Ԫ�أ�"<< endl;
	t1.print();
	cout<<endl;
    cout <<"������ȣ�"<< t1.length() << endl;
    cout <<"�ж��Ƿ�Ϊ�գ�"<< t1.is_empty() << endl;
    cout<<"����ֵΪ3��Ԫ��������"<<t1.find(3)<<endl;
	t1.del(4);
    cout<<"���ɾ������4��Ԫ�صĽ����"<<endl;
	t1.print();
    return 0;
}