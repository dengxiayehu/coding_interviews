#include <iostream>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int LongestSubstringWithoutDuplication(const string& str) {
        if (str.empty()) {
            return 0;
        }
        int pos[26];  // 记录前一次出现某字符的索引
        for (int i = 0; i < 26; i++) {
            pos[i] = -1;
        }
        int* dp = new int[str.length()]();  // 记录以当前索引为结束点的最长不重复字符串长度
        dp[0] = 1;                          // 首元素，最长不重复字符串长度为1
        pos[str[0] - 'a'] = 0;
        int longest = dp[0];
        for (int i = 1; i < str.length(); i++) {
            int begin = i - dp[i - 1];            // dp[i-1]最长不重复子串的起始位置
            int last_appear = pos[str[i] - 'a'];  // 上一次出现的位置
            if (last_appear < begin) {            // 上一次出现的位置不在dp[i-1]表示的最长不重复字符串中
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = i - last_appear;  // 在其中，我们计算当前最长不重复字符串的长度为i-last_appear
            }
            pos[str[i] - 'a'] = i;
            if (dp[i] > longest)
                longest = dp[i];
        }
        delete[] dp;

        return longest;
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().LongestSubstringWithoutDuplication("arabcacfr") << endl;

    return 0;
}