#include <iostream>
#include <vector>
#include <queue>

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
        const int n = array.size();
        int k = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (func(array[i])) {
                array[k++] = array[i];
            } else {
                q.push(array[i]);
            }
        }
        while (!q.empty()) {
            array[k++] = q.front();
            q.pop();
        }
    }

    static bool is_odd(const int v) {
        return v&1;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> v(arr, arr+NELEM(arr));
    Solution().reOrderArray(v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
