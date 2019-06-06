# 替换空格

> 请实现一个函数，将一个字符串中的每个空格替换为"%20"。例如，当字符串为"We Are Happy"，则经过替换之后的字符串为"We%20Are%20Happy"。

遇到需要将序列扩展的问题，可以先进行“预处理”，然后由后往前进行处理。

测试用例：

1. 字符串中无空格
2. 字符串中含有多个空格，且有连续的空格
3. 字符串中只有空格
4. 字符串为NULL

``` cpp
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
        if (!str || length <= 1) {
            return;
        }

        int space_count = 0;
        char *p = str;
        while (*p) {
            if (*p == ' ') {
                space_count++;
            }
            p++;
        }
        if (space_count == 0) {
            // No any space char, return.
            return;
        }
        p--; // points to the last char of str
        char *q = p;
        p += (space_count<<1); // p points to the last char of new str
        *(p+1) = '\0';
        while (q >= str) {
            if (*q == ' ') {
                *p-- = '0';
                *p-- = '2';
                *p-- = '%';
                q--;
            } else {
                *p-- = *q--;
            }
        }
	}
};

int main(int argc, char const *argv[])
{
    Solution s;

    char str[128] = "abc";
    s.replaceSpace(str, sizeof(str));
    cout << str << endl;

    char str1[128] = "a c";
    s.replaceSpace(str1, sizeof(str1));
    cout << str1 << endl;

    char str2[128] = "a c  ";
    s.replaceSpace(str2, sizeof(str2));
    cout << str2 << endl;

    char str3[128] = "   ";
    s.replaceSpace(str3, sizeof(str3));
    cout << str3 << endl;

    s.replaceSpace(NULL, 0);

    return 0;
}
```

> 输出结果：  
abc  
a%20c  
a%20c%20%20  
%20%20%20  