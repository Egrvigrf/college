#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // 用于 sleep 函数

void printVisualization(const std::vector<int> &arr, int i, int j)
{
    system("cls"); // 清屏，Windows系统使用"cls"
    for (size_t k = 0; k < arr.size(); ++k)
    {
        if (k == i || k == j)
        {
            std::cout << "\033[1;31m"; // 红色
        }
        else
        {
            std::cout << "\033[0m"; // 默认颜色
        }

        // 输出*序列
        std::cout << "*";
        for (int l = 0; l < arr[k]; ++l)
        {
            std::cout << "*"; // 用 * 表示数的大小
        }

        // 在 * 序列后输出数值
        std::cout << " " << arr[k];

        // 在数值后输出循环变量i和j的值（如果k等于i或j）
        if (k == i)
        {
            std::cout << " (i=" << i << ")"; // 显示i的值
        }
        if (k == j)
        {
            std::cout << " (j=" << j << ")"; // 显示j的值
        }

        std::cout << std::endl;
    }
    std::cout << "Sorting..." << std::endl;
    sleep(2); // 可视化延迟1秒钟
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
            printVisualization(arr, i, j);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    printVisualization(arr, i + 1, high);
    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> nums;

    // 生成随机乱序序列
    const int size = 15;
    for (int i = 0; i < size; ++i)
    {
        nums.push_back(std::rand() % 20 + 1); // 生成1到20范围内的随机数
    }

    std::cout << "Original Array:" << std::endl;
    printVisualization(nums, -1, -1); // 输出初始乱序序列

    quickSort(nums, 0, nums.size() - 1); // 进行快速排序并可视化过程

    std::cout << "Sorted Array:" << std::endl;
    printVisualization(nums, -1, -1); // 输出排序后的序列

    return 0;
}