#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

class Solution61 {
public:
    bool isContinuous(std::vector<int> numbers) {
        const int numbers_size = numbers.size();
        if (numbers.size() < 5) {
            // 牌数量太少，不可能是顺子。
            return false;
        }

        // 将扑克牌排序。
        sort(numbers.begin(), numbers.end());

        int jack_count = 0;
        int gap_total = 0;
        for (int i = 0; i < numbers_size; ++i) {
            if (numbers[i] == 0) {
                ++jack_count;
            } else if (i > 0 && numbers[i - 1] != 0) {  // 注意这里的条件，参考的前一张牌不能是 0
                int gap = numbers[i] - numbers[i - 1];
                if (gap == 0) {
                    // 出现了对子，不可能是顺子了
                    return false;
                }
                gap_total += (gap - 1);
            }
        }

        return gap_total <= jack_count;
    }
};

TEST(ut_61, isContinous) {
    Solution61 s;

    EXPECT_TRUE(s.isContinuous(std::vector<int>{1, 0, 4, 3, 5}));
    EXPECT_FALSE(s.isContinuous(std::vector<int>{1, 0, 4, 3, 6}));
    EXPECT_FALSE(s.isContinuous(std::vector<int>{1, 0, 4, 3, 1}));
    EXPECT_TRUE(s.isContinuous(std::vector<int>{0, 3, 2, 6, 4}));
}
