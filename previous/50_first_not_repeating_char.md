# 第一个只出现一次的字符

> 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

``` cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        int hash_table[128] = { 0 };
        for (const char *p = str.c_str(); *p; p++) {
            hash_table[static_cast<int>(*p)]++;
        }
        for (const char *p = str.c_str(); *p; p++) {
            if (hash_table[static_cast<int>(*p)] == 1) {
                return p-str.c_str();
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().FirstNotRepeatingChar("") << endl;
    cout << Solution().FirstNotRepeatingChar("abc") << endl;
    cout << Solution().FirstNotRepeatingChar("aabc") << endl;
    cout << Solution().FirstNotRepeatingChar("aabbcc") << endl;
    cout << Solution().FirstNotRepeatingChar("abbc") << endl;

    return 0;
}
```

> 输出结果：

``` txt
-1
0
2
-1
0
```