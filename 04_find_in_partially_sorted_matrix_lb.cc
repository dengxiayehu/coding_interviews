#include <iostream>
#include <vector>

using namespace std;

#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        // Sanity check.
        if (array.empty() || array[0].empty()) {
            return false;
        }
        unsigned col_num = array[0].size();
        for (unsigned i = 1; i < array.size(); i++) {
            if (array[i].size() != col_num) {
                return false;
            }
        }

        unsigned row_num = array.size();
        unsigned rows_skipped = 0;
        unsigned cols_skipped = 0;
        while (rows_skipped < row_num && cols_skipped < col_num) {
            int j = cols_skipped;
            vector<int>& row = array[row_num - rows_skipped - 1];
            int val = row[j];
            if (val == target) {
                // Find the target.
                return true;
            } else if (val < target) {
                // Target cant be in this col.
                cols_skipped++;
            } else {
                // Target cant be in this row.
                ++rows_skipped;
            }
        }

        return false;
    }
};

int main(int argc, char const* argv[]) {
    // Init the matrix.
    vector<vector<int>> array;
    int r0[] = {1, 2, 8, 9};
    vector<int> v0(r0, r0 + NELEM(r0));
    int r1[] = {2, 4, 9, 12};
    vector<int> v1(r1, r1 + NELEM(r1));
    int r2[] = {4, 7, 10, 13};
    vector<int> v2(r2, r2 + NELEM(r2));
    int r3[] = {6, 8, 11, 15};
    vector<int> v3(r3, r3 + NELEM(r3));
    array.push_back(v0);
    array.push_back(v1);
    array.push_back(v2);
    array.push_back(v3);

    // Print the matrix.
    for (vector<vector<int>>::iterator it = array.begin(); it != array.end(); it++) {
        for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
            printf("%d ", *it1);
        }
        printf("\n");
    }

    Solution s;

    // Search the matrix.
    int target;
    for (vector<vector<int>>::iterator it = array.begin(); it != array.end(); it++) {
        for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
            target = *it1;
            cout << "target " << target << (s.Find(target, array) ? " found" : " not found") << endl;
        }
    }

    target = -1;
    cout << "target " << target << (s.Find(target, array) ? " found" : " not found") << endl;

    target = 16;
    cout << "target " << target << (s.Find(target, array) ? " found" : " not found") << endl;

    return 0;
}
