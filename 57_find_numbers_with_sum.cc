#include <iostream>
#include <vector>

using namespace std;

#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> res;
        if (array.size() < 2) {
            // 少于两个数，不符合题意的输入。
            return res;
        }

        int begin = 0;
        int end = array.size() - 1;
        while (begin < end) {
            int tmp_sum = array[begin] + array[end];
            if (tmp_sum == sum) {
                // 找到一个候选项。
                if (res.empty() || array[begin] * array[end] < res[0] * res[1]) {
                    res.push_back(array[begin]);
                    res.push_back(array[end]);
                }
                begin++;
                end--;
            } else if (tmp_sum > sum) {
                end--;
            } else {
                begin++;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {1, 2, 4, 7, 11, 15};
        vector<int> res = Solution().FindNumbersWithSum(vector<int>(arr, arr + NELEM(arr)), 15);
        cout << res[0] << ", " << res[1] << endl;
    }

    {
        int arr[] = {1, 2, 3, 4, 5};
        vector<int> res = Solution().FindNumbersWithSum(vector<int>(arr, arr + NELEM(arr)), 6);
        cout << res[0] << ", " << res[1] << endl;
    }

    return 0;
}