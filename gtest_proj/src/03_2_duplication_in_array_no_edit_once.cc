#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/find-the-duplicate-number/description/
// 数组大小为 n + 1，其数字均在 [1, n] 之间，若没有重复则最多有 n 个数字没法填满数组，所以肯定有一个重复的数字。
// 元素值作为下一个节点的索引，类比链表，元素的值指向下一个元素的索引（题目限制了肯定不会数组越界）
// 关于快慢指针的证明，环入口的检测参考：https://www.zhihu.com/question/23208893/answer/1893673351702086710
class Solution03_2 {
public:
    int findDuplicate(std::vector<int>& nums) {
        // 快慢指针都从“链表头”开始，相遇肯定在环内
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // 定位环的入口，新的指针从头开始
        int finder = 0;
        do {
            finder = nums[finder];
            slow = nums[slow];
        } while (finder != slow);
        // 指向了相同位置，也就是元素值重复
        return finder;
    }
};

TEST(ut_03_2, DuplicationInArrayNoEditOnce) {
    Solution03_2 s;

    std::vector<int> numbers = {1, 3, 4, 2, 2};
    EXPECT_EQ(s.findDuplicate(numbers), 2);

    // 2 9 1 5 3 6 8 7
    //   .         * |
    //  /|\          |
    //   |___________|
    std::vector<int> numbers1 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    EXPECT_EQ(s.findDuplicate(numbers1), 9);

    std::vector<int> numbers2 = {2, 3, 4, 1, 2};
    EXPECT_EQ(s.findDuplicate(numbers2), 2);
}
