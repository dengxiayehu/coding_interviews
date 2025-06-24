#include <gtest/gtest.h>

#include <iostream>
#include <string>

class Solution17_1 {
public:
    void FullArrangement(int n) {
        if (n <= 0) {
            return;
        }

        std::string res;
        res.resize(n, '0');
        std::string sep;
        full_arrangement_internal(0, res, sep);
        std::cout << std::endl;
    }

private:
    void full_arrangement_internal(int idx, std::string& res, std::string& sep) {
        if (idx >= res.size()) {
            // 一个全排列找到了，打印结果
            print_number(res, sep);
            return;
        }
        for (int i = 0; i < 10; i++) {
            // 处理当前元素
            res[idx] = '0' + i;
            // 递归处理后一个元素，退出条件在这个函数的一开始
            full_arrangement_internal(idx + 1, res, sep);
        }
    }

    void print_number(const std::string& res, std::string& sep) {
        // 忽略前置的 '0'
        int i = 0;
        size_t res_sz = res.size();
        while (i < res_sz) {
            if (res[i] != '0') {
                break;
            }
            i++;
        }
        if (i != res.size()) {
            // 不全为 '0'
            std::cout << sep << res.substr(i);
            if (sep.empty()) {
                sep = " ";
            }
        }
    }
};

TEST(ut_17_1, FullArrangement) {
    Solution17_1 s;

    s.FullArrangement(1);
    s.FullArrangement(2);
}
