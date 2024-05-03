#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

// 文件拷贝函数
void copyFile(const string &sourcePath, const string &destinationPath)
{
    ifstream sourceFile(sourcePath, ios::binary);
    ofstream destinationFile(destinationPath, ios::binary);

    if (!sourceFile.is_open() || !destinationFile.is_open())
    {
        cerr << "Failed to open file!" << endl;
        return;
    }

    destinationFile << sourceFile.rdbuf();

    cout << "File copied successfully!" << endl;

    sourceFile.close();
    destinationFile.close();
}

// 生成九九乘法表并写入文件
void createMultiplicationTable(const string &filePath)
{
    ofstream file(filePath);

    if (!file.is_open())
    {
        cerr << "Failed to open file!" << endl;
        return;
    }

    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            file << j << " * " << i << " = " << (i * j) << "\t";
        }
        file << endl;
    }

    cout << "Multiplication table created successfully!" << endl;

    file.close();
}

// 解析BMP文件头
void parseBMPHeader(ifstream &file, int32_t &width, int32_t &height)
{
    file.seekg(18, ios::beg); // 跳过18字节，到达宽度和高度信息处

    file.read(reinterpret_cast<char *>(&width), sizeof(width));
    file.read(reinterpret_cast<char *>(&height), sizeof(height));

    cout << "BMP image width: " << width << " pixels" << endl;
    cout << "BMP image height: " << height << " pixels" << endl;
}

// 修改BMP文件中心区域像素颜色
void modifyBMPImage(const string &sourcePath, const string &destinationPath)
{
    ifstream sourceFile(sourcePath, ios::binary);
    ofstream destinationFile(destinationPath, ios::binary);

    if (!sourceFile.is_open() || !destinationFile.is_open())
    {
        cerr << "Failed to open file!" << endl;
        return;
    }

    // 拷贝BMP文件头和信息头
    vector<char> header(54);
    sourceFile.read(header.data(), header.size());
    destinationFile.write(header.data(), header.size());

    // 读取BMP像素数据
    int32_t width, height;
    parseBMPHeader(sourceFile, width, height);

    int bytesPerPixel = *(reinterpret_cast<int16_t *>(header.data() + 28)) / 8;
    int imageSize = width * height * bytesPerPixel;
    vector<char> pixelData(imageSize);
    sourceFile.read(pixelData.data(), imageSize);

    // 修改中心区域像素颜色
    int centerX = width / 2;
    int centerY = height / 2;
    int startX = max(centerX - 4, 0);
    int startY = max(centerY - 4, 0);
    int endX = min(centerX + 4, width - 1);
    int endY = min(centerY + 4, height - 1);

    int colorIndex = 0;
    for (int y = startY; y <= endY; ++y)
    {
        for (int x = startX; x <= endX; ++x)
        {
            int index = (y * width + x) * bytesPerPixel;
            if (colorIndex % 3 == 0)
            {
                pixelData[index] = 0xFF;     // 设置红色分量为最大值
                pixelData[index + 1] = 0x00; // 设置绿色分量为最小值
                pixelData[index + 2] = 0x00; // 设置蓝色分量为最小值
            }
            else if (colorIndex % 3 == 1)
            {
                pixelData[index] = 0x00;     // 设置红色分量为最小值
                pixelData[index + 1] = 0xFF; // 设置绿色分量为最大值
                pixelData[index + 2] = 0x00; // 设置蓝色分量为最小值
            }
            else
            {
                pixelData[index] = 0x00;     // 设置红色分量为最小值
                pixelData[index + 1] = 0x00; // 设置绿色分量为最小值
                pixelData[index + 2] = 0xFF; // 设置蓝色分量为最大值
            }
            colorIndex++;
        }
    }

    // 写入修改后的像素数据
    destinationFile.write(pixelData.data(), imageSize);
    sourceFile.close();
    destinationFile.close();

    cout << "BMP image modified successfully!" << endl;
}

int main()
{
    // 任务1：将一个文本文件拷贝到另外一个文件中
    copyFile("source.txt", "destination.txt");

    // 任务2：创建一个文本文件，在文件中输出一个九九乘法表
    createMultiplicationTable("multiplication_table.txt");

    // 任务3：解析一个BMP文件的文件头和信息头，并输出图像的宽度和高度
    ifstream bmpFile("source.bmp", ios::binary);
    if (!bmpFile.is_open())
    {
        cerr << "Failed to open BMP file!" << endl;
        return 1;
    }
    int32_t width, height;
    parseBMPHeader(bmpFile, width, height);
    bmpFile.close();

    // 任务4：解析一个BMP文件的文件格式信息，并且拷贝到另外一个文件中，将图片中心的9*9像素区域设置为红绿蓝间隔快
    modifyBMPImage("source.bmp", "destination.bmp");

    return 0;
}
