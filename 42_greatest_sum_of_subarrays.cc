#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }

        int max_so_far = array[0];
        int max_sum = array[0];
        for (int i = 1; i < array.size(); i++) {
            max_so_far = mymax(max_so_far+array[i], array[i]);
            if (max_so_far > max_sum) {
                max_sum = max_so_far;
            }
        }

        return max_sum;
    }

private:
    int mymax(int a, int b) {
        return a > b ? a : b;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
        cout << Solution().FindGreatestSumOfSubArray(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { -10, -2, -3, -4, -9 };
        cout << Solution().FindGreatestSumOfSubArray(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}