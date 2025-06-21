#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
class Solution63 {
public:
    int maxProfit(const std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int max_profit = 0;
        int min_price = prices[0];
        const int prices_size = prices.size();
        for (int i = 1; i < prices_size; ++i) {
            if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }

            if (min_price > prices[i]) {
                min_price = prices[i];
            }
        }

        return max_profit;
    }
};

TEST(ut_63, tn_63) {
    Solution63 s;

    EXPECT_EQ(s.maxProfit(std::vector<int>{7, 1, 5, 3, 6, 4}), 5);
}
