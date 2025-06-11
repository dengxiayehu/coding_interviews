#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) {
            return 0;
        }

        int target = numbers[0];
        int times = 1;  // initial times is 1
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] == target) {
                ++times;
            } else {
                --times;
                if (times == 0) {
                    target = numbers[i];
                    times = 1;  // reset initial times to 1
                }
            }
        }

        // Check whether target is really more than half.
        times = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == target) {
                ++times;
            }
        }

        return times > numbers.size() / 2 ? target : 0;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        cout << Solution().MoreThanHalfNum_Solution(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1};
        cout << Solution().MoreThanHalfNum_Solution(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 2};
        cout << Solution().MoreThanHalfNum_Solution(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 1};
        cout << Solution().MoreThanHalfNum_Solution(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 2, 1};
        cout << Solution().MoreThanHalfNum_Solution(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    return 0;
}