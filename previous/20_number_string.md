# 表示数值的字符串

> 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串”+100”,”5e2”,”-123”,”3.1416”和”-1E-16”都表示数值。 但是”12e”,”1a3.14”,”1.2.3”,”+-5”和”12e+4.3”都不是。

``` cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 表示数值的字符串有如下两种形式：
    // （1）A[.[B]][e|EC]，eg: 2 2. 2e3 2.e3
    // （2）.B[e|EC]，eg: .2e3
    // 其中，A、C是有符号数，B是无符号数。
    bool isNumeric(char* string) {
        if (!string || !string[0]) {
            return false;
        }

        bool numberic = scan_int(string);
        if (*string == '.') {
            numberic = scan_uint(++string) || numberic;
        }
        if (*string == 'E' || *string == 'e') {
            numberic = scan_int(++string) && numberic;
        }

        return numberic && *string == '\0';
    }

private:
    static bool scan_int(char *&string) {
        if (*string == '+' || *string == '-') {
            ++string;
        }
        return scan_uint(string);
    }

    static bool scan_uint(char *&string) {
        char *save = string;
        while (*string && *string >= '0' && *string <= '9') {
            ++string;
        }
        return string > save; // got some digits
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().isNumeric(const_cast<char*>(string("2").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.1e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string(".1e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("1e+3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("1e").c_str())) << endl;

    return 0;
}
```

> 输出结果：  
1  
0  
1  
0  
1  
1  
1  
1  
1  
0