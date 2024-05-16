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
void printVisualization(const vector<int> &arr, int i, int j, int sortedIdx)
{
    cout << "\033[2J\033[H"; // 清屏，Windows系统使用"cls"
    for (int k = 0; k < int(arr.size()); k++)
    {
        if (k <= sortedIdx)
        {
            cout << "\033[1;32m"; // 绿色
        }
        else if (k == j || k == j - 1)
        {
            cout << "\033[1;31m"; // 红色
        }
        else
        {
            cout << "\033[0m"; // 默认颜色
        }
        // 输出*序列
        for (int l = 0; l < arr[k]; l++)
        {
            cout << "*"; // 用 * 表示数的大小
        }
        // 在 * 序列后输出数值和循环变量值
        cout << " " << arr[k];
        // 在数值后输出循环变量j和j+1的值（如果k等于j或j+1）
        if (k == j)
        {
            cout << " (j"
                 << "=" << k << ")"; // 显示j的值
        }
        // 在数值后输出循环变量i的值（如果k等于i）
        if (k == i)
        {
            cout << " (i=" << k << ")"; // 显示i的值
        }
        cout << endl;
    }
    cout << "\033[0m";
    cout << "Sorting..." << endl;
    Snap(500); // 可视化延迟500毫秒
}
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = n - 1; j > i; j--)
        {
            printVisualization(arr, i, j, i);
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                swapped = true;
                printVisualization(arr, i, j, i); // 显示循环变量i，j和j+1的值以及排序完成的部分
            }
        }
        if (!swapped)
        {
            printVisualization(arr, -1, -1, n - 1);
            cout << "\033[" << int(arr.size()) + 1 << ";" << 0 << "H";
            cout << "          ";
            cout << "\033[" << int(arr.size()) + 1 << ";" << 0 << "H";
            cout << "\033[1;32m";
            cout << "Done";
            break; // 如果没有发生交换，说明已排序完成
        }
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<int> nums;// 生成随机乱序序列
    const int size = rand() % 10 + 10;
    for (int i = 0; i < size; i++)
    {
        nums.push_back(rand() % 20 + 1); // 生成1到20范围内的随机数
    }
    bubbleSort(nums); // 进行冒泡排序并可视化过程
    printVisualization(nums, -1, -1, int(nums.size()) - 1);
    cout << "\033[" << int(nums.size()) + 1 << ";" << 0 << "H";
    cout << "          ";
    cout << "\033[" << int(nums.size()) + 1 << ";" << 0 << "H";
    cout << "\033[1;32m";
    cout << "Done";
    return 0;
}