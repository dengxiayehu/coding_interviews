#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        const int numbers_size = numbers.size();
        if (numbers.size() < 5) {
            // 牌数量太少，不可能是顺子。
            return false;
        }

        // 将扑克牌排序。
        sort(numbers.begin(), numbers.end());

        int jack_count = 0;
        int gap_total = 0;
        for (int i = 0; i < numbers_size; i++) {
            if (numbers[i] == 0) {
                jack_count++;
            } else if (i > 0 && numbers[i - 1] != 0) {  // 注意这里的条件，参考的前一张牌不能是0
                int gap = numbers[i] - numbers[i - 1];
                if (gap == 0) {
                    // 出现了对子，不可能是顺子了。
                    return false;
                }
                gap_total += (gap - 1);
            }
        }

        return gap_total <= jack_count;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {1, 0, 4, 3, 5};
        cout << Solution().IsContinuous(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 0, 4, 3, 6};
        cout << Solution().IsContinuous(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 0, 4, 3, 1};
        cout << Solution().IsContinuous(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {0, 3, 2, 6, 4};
        cout << Solution().IsContinuous(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    return 0;
}