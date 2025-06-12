#include <gtest/gtest.h>

// 题目：输入数字 n，按顺序打印出从 1 到最大的 n 位数的十进制数。
#include <iostream>
#include <string>

// 从字符串 res 开头开始，模拟加法运算处理，出现进位时 i++，同时 res[0] = 1，res[1]...res[i] 都为 0。
class Solution17 {
public:
    void Print1ToMaxOfNDigits(int n) {
        if (n <= 0) {
            return;
        }

        std::string sep;
        std::string res;
        res.resize(n);
        int i = 0;
        res[i] = '1';
        while (true) {
            std::cout << sep << res;
            if (sep.empty()) {
                sep = " ";
            }
            if (res[i] < '9') {
                res[i]++;
            } else {
                res[i] = '0';
                int j = i - 1;
                while (j >= 0) {
                    if (res[j] < '9') {
                        res[j]++;
                        break;
                    } else {
                        res[j] = '0';
                    }
                    j--;
                }
                if (j < 0) {
                    i++;
                    if (i == n) {
                        // 溢出了
                        break;
                    }
                    res[i] = '0';
                    res[0] = '1';
                    continue;
                }
            }
        }
        std::cout << std::endl;
    }
};

TEST(ut_17, Print1ToMaxOfNDigits) {
    Solution17 s;

    s.Print1ToMaxOfNDigits(1);
    s.Print1ToMaxOfNDigits(2);
    s.Print1ToMaxOfNDigits(3);
}
