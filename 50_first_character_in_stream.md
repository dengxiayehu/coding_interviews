# 字符流中第一个不重复的字符

> 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述：
> 如果当前字符流没有存在出现一次的字符，返回#字符。

``` cpp
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    Solution() : index_(0) {
        for (int i = 0; i < 256; i++) {
            hash_table_[i] = -1;
        }
    }

    void Insert(char ch) {
        if (hash_table_[static_cast<int>(ch)] == -1) {
            // First apperance of char |ch|.
            hash_table_[static_cast<int>(ch)] = index_;
        } else if (hash_table_[static_cast<int>(ch)] >= 0) {
            // Char |ch| already found, set to -2 to indicates duplication.
            hash_table_[static_cast<int>(ch)] = -2;
        }
        index_++;
    }

    char FirstAppearingOnce() {
        char res = '#';
        int min_idx = INT_MAX;
        for (int i = 0; i < 256; i++) {
            if (hash_table_[i] >= 0) { // 字符i出现了一次
                if (hash_table_[i] <= min_idx) { // 字符i出现的位置比较靠前
                    min_idx = hash_table_[i];
                    res = static_cast<char>(i);
                }
            }
        }
        return res;
    }

private:
    int hash_table_[256];
    int index_;
};

int main(int argc, char *argv[])
{
    Solution s;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('l');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;

    return 0;
}
```

> 输出结果：

``` txt
g
g
g
#
l
l
```