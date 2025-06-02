#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        // Sanity check.
        if (matrix.empty()) {
            return res;
        }
        // Check rows and cols.
        int cols = matrix[0].size();
        if (cols == 0) {
            return res;
        }
        int rows = matrix.size();
        for (int i = 1; i < rows; i++) {
            if ((int)matrix[i].size() != cols) {
                return res;
            }
        }

        // Get the number of circles.
        int circles = ((rows < cols ? rows : cols) + 1) >> 1;
        for (int c = 0; c < circles; c++) {
            // Top horizontal line.
            for (int j = c; j < cols - c; j++) {
                res.push_back(matrix[c][j]);
            }
            // Right vertical line.
            for (int i = c + 1; i < rows - c; i++) {
                res.push_back(matrix[i][cols - 1 - c]);
            }
            if (rows - 1 - c > c) {
                // Bottom horizontal line.
                for (int j = cols - 2 - c; j >= c; j--) {
                    res.push_back(matrix[rows - 1 - c][j]);
                }
            }
            if (cols - 1 - c > c) {
                // Left vertical line.
                for (int i = rows - 2 - c; i > c; i--) {
                    res.push_back(matrix[i][c]);
                }
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    {
        int row0[] = {1, 2, 3, 4, 5};
        int row1[] = {6, 7, 8, 9, 10};
        int row2[] = {11, 12, 13, 14, 15};
        int row3[] = {16, 17, 18, 19, 20};
        int row4[] = {21, 22, 23, 24, 25};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));
        matrix.push_back(vector<int>(row1, row1 + NELEM(row1)));
        matrix.push_back(vector<int>(row2, row2 + NELEM(row2)));
        matrix.push_back(vector<int>(row3, row3 + NELEM(row3)));
        matrix.push_back(vector<int>(row4, row4 + NELEM(row4)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int row0[] = {1, 2};
        int row1[] = {3, 4};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));
        matrix.push_back(vector<int>(row1, row1 + NELEM(row1)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int row0[] = {1, 2};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int row0[] = {1};
        int row1[] = {2};
        int row2[] = {3};
        int row3[] = {4};
        int row4[] = {5};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));
        matrix.push_back(vector<int>(row1, row1 + NELEM(row1)));
        matrix.push_back(vector<int>(row2, row2 + NELEM(row2)));
        matrix.push_back(vector<int>(row3, row3 + NELEM(row3)));
        matrix.push_back(vector<int>(row4, row4 + NELEM(row4)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int row0[] = {1};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int row0[] = {1, 2};
        int row1[] = {3, 4};
        int row2[] = {5, 6};
        int row3[] = {7, 8};
        int row4[] = {9, 10};
        vector<vector<int>> matrix;
        matrix.push_back(vector<int>(row0, row0 + NELEM(row0)));
        matrix.push_back(vector<int>(row1, row1 + NELEM(row1)));
        matrix.push_back(vector<int>(row2, row2 + NELEM(row2)));
        matrix.push_back(vector<int>(row3, row3 + NELEM(row3)));
        matrix.push_back(vector<int>(row4, row4 + NELEM(row4)));

        vector<int> res = Solution().printMatrix(matrix);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
