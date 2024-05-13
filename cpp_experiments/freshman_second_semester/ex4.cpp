#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Big
{
private:
    string value;     // 用字符串存储大整数
    bool negative = false; // 是否为负数
public:
    // 构造函数
    Big(string s)
    {
        if (s[0] == '-')
        {
            negative = true;
            s = s.substr(1);
        }
        value = s;
    }
    Big():value("0"),negative(false) {}
    // 输入运算符重载
    friend istream &operator>>(istream &in, Big &num)
    {
        string input;
        in >> input;
        num = Big(input); 
        return in;
    }
    // 输出运算符重载
    friend ostream &operator<<(ostream &out, const Big &num)
    {
        string output = num.value;
        if (num.negative)
        {
            out << '-';
        }
        out << output;
        return out;
    }

    // 赋值运算符重载
    Big &operator=(const Big &other)
    {
        value = other.value;
        negative = other.negative;
        return *this;
    }
    int compare(string str1, string str2) const
    {
        if (str1.length() > str2.length())
            return 1;
        else if (str1.length() < str2.length())
            return -1;
        else
            return str1.compare(str2);
    }
    string add(string str1, string str2) const // 高精度加法
    {
        string str;
        int len1 = str1.length();
        int len2 = str2.length();
        // 前面补0，弄成长度相同
        if (len1 < len2)
        {
            for (int i = 1; i <= len2 - len1; i++)
                str1 = "0" + str1;
        }
        else
        {
            for (int i = 1; i <= len1 - len2; i++)
                str2 = "0" + str2;
        }
        len1 = str1.length();
        int cf = 0;
        int temp;
        for (int i = len1 - 1; i >= 0; i--)
        {
            temp = str1[i] - '0' + str2[i] - '0' + cf;
            cf = temp / 10;
            temp %= 10;
            str = char(temp + '0') + str;
        }
        if (cf != 0)
            str = char(cf + '0') + str;
        return str;
    }
    string sub(string str1, string str2) const 
    {
        bool belowzero = false;
        if (str1.length() < str2.length() || (str1.length()==str2.length()&& str1 < str2))
        {
            swap(str1,str2);
            belowzero = true;
        }
        string str;
        int tmp = str1.length() - str2.length();
        int cf = 0;
        for (int i = str2.length() - 1; i >= 0; i--)
        {
            if (str1[tmp + i] < str2[i] + cf)
            {
                str = char(str1[tmp + i] - str2[i] - cf + '0' + 10) + str;
                cf = 1;
            }
            else
            {
                str = char(str1[tmp + i] - str2[i] - cf + '0') + str;
                cf = 0;
            }
        }
        for (int i = tmp - 1; i >= 0; i--)
        {
            if (str1[i] - cf >= '0')
            {
                str = char(str1[i] - cf) + str;
                cf = 0;
            }
            else
            {
                str = char(str1[i] - cf + 10) + str;
                cf = 1;
            }
        }
        str.erase(0, str.find_first_not_of('0')); // 去除结果中多余的前导0
        if(belowzero)
        {
            return "-"+str;
        }
        else
        {
            return str;
        }
    }
    string mul(string str1, string str2) const
    {
        string str;
        int len1 = str1.length();
        int len2 = str2.length();
        string tempstr;
        for (int i = len2 - 1; i >= 0; i--)
        {
            tempstr = "";
            int temp = str2[i] - '0';
            int t = 0;
            int cf = 0;
            if (temp != 0)
            {
                for (int j = 1; j <= len2 - 1 - i; j++)
                    tempstr += "0";
                for (int j = len1 - 1; j >= 0; j--)
                {
                    t = (temp * (str1[j] - '0') + cf) % 10;
                    cf = (temp * (str1[j] - '0') + cf) / 10;
                    tempstr = char(t + '0') + tempstr;
                }
                if (cf != 0)
                    tempstr = char(cf + '0') + tempstr;
            }
            str = add(str, tempstr);
        }
        str.erase(0, str.find_first_not_of('0'));
        return str;
    }
    string div(string dividend, string divisor) const
    {
        string quotient;
        unsigned long long divisorInt = stoi(divisor);
        unsigned long long remainder = 0;

        for (char &digit : dividend)
        {
            unsigned long long currentDigit = digit - '0' + remainder * 10;
            quotient += to_string(currentDigit / divisorInt);
            remainder = currentDigit % divisorInt;
        }

        // Remove leading zeros from quotient
        quotient.erase(0, min(quotient.find_first_not_of('0'), quotient.size() - 1));

        return quotient;
    }
    // 加法运算符重载
    Big operator+(const Big &other) const
    {
        string result = add(other.value, value);
        return Big(result);
    }

    // 减法运算符重载
    Big operator-(const Big &other) const
    {
        string result = sub(value,other.value);
        return Big(result);
    }

    // 乘法运算符重载
    Big operator*(const Big &other) const
    {
        string result = mul(value,other.value);
        return Big(result);
    }
    
    Big operator/(const Big &other) const
    {
        string result = div(value, other.value);
        return Big(result);
    }
    
    // 与基本类型的混合运算
    Big operator+(int num) const
    {
        return add(value, to_string(num));
    }
    Big operator-(int num) const
    {
        return sub(value, to_string(num));
    }
    Big operator*(int num) const
    {
        return mul(value, to_string(num));
    }
    Big operator/(int num) const
    {
        return div(value, to_string(num));
    }

};
int main(){
    Big a, b;
    cout << "Enter the a: ";
    cin >> a;
    cout << "Enter the b: ";
    cin >> b;
    //Big c = b;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a + 1000 = " << (a + 1000)<<endl;
    cout << "a - 1000 = " << (a - 1000) << endl;
    cout << "a * 1000 = " << (a * 1000) << endl;
    cout << "a / 1000 = " << (a / 1000) << endl;
    return 0;
}