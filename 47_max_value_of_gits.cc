#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int GetMaxValue(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }
        for (vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); it++) {
            if (it->size() != cols) {
                return 0;
            }
        }

        int rows = matrix.size();
        int *profits = new int[cols]();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int up = 0;
                if (i > 0) {
                    up = profits[j];
                }

                int left = 0;
                if (j > 0) {
                    left = profits[j-1];
                }

                profits[j] = max(left, up) + matrix[i][j];
            }
        }

        delete [] profits;

        return profits[cols-1];
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr0[] = { 1, 10, 3, 8 };
        int arr1[] = { 12, 2, 9, 6 };
        int arr2[] = { 5, 7, 4, 11 };
        int arr3[] = { 3, 7, 16, 5 };
        vector<vector<int> > matrix;
        matrix.push_back(vector<int>(arr0, arr0+NELEM(arr0)));
        matrix.push_back(vector<int>(arr1, arr1+NELEM(arr1)));
        matrix.push_back(vector<int>(arr2, arr2+NELEM(arr2)));
        matrix.push_back(vector<int>(arr3, arr3+NELEM(arr3)));
        cout << Solution().GetMaxValue(matrix) << endl;
    }

    return 0;
}