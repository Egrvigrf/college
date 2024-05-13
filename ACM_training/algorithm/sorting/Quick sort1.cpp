#include <iostream>
#include <iomanip>
using namespace std;
void quicksort(int *a, int i, int j);
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// 从小到大
void quicksort(int *a, int begin, int end)
{
    int left = begin, right = end;
    int k = a[begin];
    int hole = begin;
    while (left < right)
    {
        while(a[right] > k && right > left)
        {
            right--;
        }
        a[hole] = a[right];
        hole = right;
        while (a[left] < k && left < right)
        {
            left++;
        }
        a[hole] = a[left];
        hole = left;
    }
    a[hole] = k;
    if (begin < end)
    {
        quicksort(a, begin, hole - 1);
        quicksort(a, hole + 1, end);
    }
}        