#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        reorder_array_core(array, is_odd);
    }

private:
    typedef bool (*Func)(const int v);

    void reorder_array_core(vector<int> &array, Func func) {
        int i = 0;
        int j = array.size()-1;
        while (i != j) {
            while (i < j && func(array[i])) {
                ++i;
            }
            while (i < j && !func(array[j])) {
                --j;
            }
            swap(array, i, j);
        }
    }

    static bool is_odd(const int v) {
        return v&1;
    }

    static void swap(vector<int> &array, int i, int j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 3, 3, 4, 5, 6 };
    vector<int> v(arr, arr+NELEM(arr));
    Solution().reOrderArray(v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
