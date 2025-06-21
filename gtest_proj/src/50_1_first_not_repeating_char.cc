#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>

// 题目：字符流中第一个只出现一次的字符。
class Solution50_1 {
public:
    void Insert(char ch) {
        ++m_count;
        int idx = ch;
        if (m_hash[idx] == 0) {
            m_hash[idx] = m_count;
        } else {
            m_hash[idx] = -1;
        }
    }

    char FirstAppearingOnce() {
        int min_idx = -1;
        for (int i = 0; i < kNChars; ++i) {
            if (m_hash[i] > 0) {
                min_idx = min_idx == -1 ? i : std::min(min_idx, i);
            }
        }
        if (min_idx != -1) {
            return min_idx;
        }

        return 0;
    }

private:
    static constexpr size_t kNChars = 256;
    int m_hash[kNChars] = {0};
    int m_count = 0;
};

TEST(ut_50_1, firstAppearingOnce) {
    Solution50_1 s;

    s.Insert('g');
    EXPECT_EQ(s.FirstAppearingOnce(), 'g');
    s.Insert('o');
    EXPECT_EQ(s.FirstAppearingOnce(), 'g');
    s.Insert('o');
    EXPECT_EQ(s.FirstAppearingOnce(), 'g');
    s.Insert('g');
    EXPECT_EQ(s.FirstAppearingOnce(), 0);
}
