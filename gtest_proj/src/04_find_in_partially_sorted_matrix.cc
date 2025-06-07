#include <gtest/gtest.h>

#include <vector>

// LCR 121. 寻找目标值 - 二维数组
class Solution04 {
public:
    bool Find(int target, const std::vector<std::vector<int>>& array) {
        if (array.empty()) {
            return false;
        }
        const size_t row_num = array.size();
        const size_t col_num = array[0].size();
        // 定位二维数组的右上角元素并从它开始探测
        int r = 0;
        int c = col_num - 1;
        while (r < row_num && c >= 0) {
            int cur_val = array[r][c];
            if (cur_val == target) {
                return true;
            } else if (cur_val > target) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};

TEST(ut_04, FindTopRight) {
    Solution04 s;

    std::vector<std::vector<int>> array{{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    EXPECT_TRUE(s.Find(7, array));
    EXPECT_TRUE(s.Find(11, array));
    EXPECT_TRUE(s.Find(1, array));
    EXPECT_FALSE(s.Find(5, array));
}
