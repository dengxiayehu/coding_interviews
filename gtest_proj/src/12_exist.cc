#include <gtest/gtest.h>

#include <string>
#include <vector>

// https://leetcode.cn/problems/word-search/description/
// 题目：请设计一个函数，用来判断在一个矩形中是否存在一条包含某字符串所有字符的路径。路径可以从矩形中的任意一格开始，每一步都可以在矩形中向左、右、上、下移动一格。如果一条路径经过了矩阵中的某一格，那么该路径不能再次进入该格子。
class Solution12 {
public:
    bool exist(const std::vector<std::vector<char>>& board, const std::string& word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        // 最好将 flag 二维数组空间申请放到循环外，后续要用时重置一下即可
        std::vector<std::vector<bool>> flag(m);
        for (int i = 0; i < m; i++) {
            flag[i].resize(n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // 在二维数组中找到了起始字符
                    // 重置标记数组
                    for (int ii = 0; ii < m; ii++) {
                        for (int jj = 0; jj < n; jj++) {
                            flag[ii][jj] = false;
                        }
                    }
                    if (search(board, word, &flag, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    // 下面的 search 其实就是 dfs 深度优先遍历算法
    bool search(const std::vector<std::vector<char>>& board, const std::string& word,
                std::vector<std::vector<bool>>* flag, int i, int j, int next) {
        // 已经找到了
        if (word.length() == next) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }

        // 不在路径上，或者已经找过了
        if (board[i][j] != word[next] || (*flag)[i][j]) {
            return false;
        }

        // 可能在路径上
        (*flag)[i][j] = true;

        // 继续找下一个字符
        next += 1;
        if (search(board, word, flag, i - 1, j, next) || search(board, word, flag, i + 1, j, next) ||
            search(board, word, flag, i, j + 1, next) || search(board, word, flag, i, j - 1, next)) {
            return true;
        }

        (*flag)[i][j] = false;

        return false;
    }
};

TEST(ut_12, exist) {
    Solution12 s;

    std::vector<std::vector<char>> board;
    board.push_back({'A', 'B', 'C', 'E'});
    board.push_back({'S', 'F', 'C', 'S'});
    board.push_back({'A', 'D', 'E', 'E'});
    ASSERT_TRUE(s.exist(board, "ABCCED"));
    ASSERT_TRUE(s.exist(board, "SEE"));
    ASSERT_FALSE(s.exist(board, "ABCB"));
}
