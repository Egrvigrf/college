#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
void Snap(int t)
{
    chrono::milliseconds pauseTime(t); // 间隔单位为毫秒
    this_thread::sleep_for(pauseTime);
}
void printVisualization(const vector<int> &arr, int i, int j, int key)
{
    cout << "\033[2J\033[H"; // 清屏
    for (int k = 0; k < int(arr.size()); ++k)
    {
        if (k <= i || key == -1)
        {
            cout << "\033[1;32m"; // 绿色
        }
        else
        {
            cout << "\033[0m"; // 默认颜色
        }
        // 输出*序列
        for (int l = 0; l < arr[k]; l++)
        {
            if ( k == j +1 )
                cout << "\033[1;31m";
            cout << "*"; // 用 * 表示数的大小
        }
        // 在 * 序列后输出数值和循环变量值
        cout << " " << arr[k];
        // 在数值后输出循环变量i和j的值（如果k等于i或j）
        if (k == i)
        {
            cout << " (i=" << i << ")"; // 显示i的值
        }
        if (k == j + 1)
        {
            cout << " (j=" << j + 1 << ")"; // 显示j+1的值
            if (arr[j+1] != key)
            {
                cout << " compare with " << key;
            }
            else if (i == j+1)
            {
                cout << " keep value " << key;
            }
            else
            {
                cout << " insert " << key;
            }
            cout << " ";
            for (int i1 = 0; i1 < key; i1++)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    if (key == -1)
    {
        cout << "\033[1;32m";
        cout << "Done";
    }
    else
    {
        cout << "\033[0m";
        cout << "Sorting..." << endl;
    }
    Snap(300);//间隔时间0.8秒
}
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        printVisualization(arr, i, j, key);
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            printVisualization(arr, i, j-1, key);
            j--;
            printVisualization(arr, i, j, key);
        }
        arr[j + 1] = key;
        printVisualization(arr, i, j, key);
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<int> nums;// 生成随机乱序序列
    const int size = rand() % 10 + 10;
    for (int i = 0; i < size; ++i)
    {
        nums.push_back(rand() % 20 + 1); // 生成1到20范围内的随机数
    }
    insertionSort(nums); // 进行插入排序并可视化过程
    printVisualization(nums, int(nums.size()), -2, -1);
    return 0;
}