# 扑克牌顺子

> LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

``` cpp
#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

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
            } else if (i > 0 && numbers[i-1] != 0) { // 注意这里的条件，参考的前一张牌不能是0
                int gap = numbers[i]-numbers[i-1];
                if (gap == 0) {
                    // 出现了对子，不可能是顺子了。
                    return false;
                }
                gap_total += (gap-1);
            }
        }

        return gap_total <= jack_count;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 1, 0, 4, 3, 5 };
        cout << Solution().IsContinuous(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 1, 0, 4, 3, 6 };
        cout << Solution().IsContinuous(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 1, 0, 4, 3, 1 };
        cout << Solution().IsContinuous(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 0, 3, 2, 6, 4 };
        cout << Solution().IsContinuous(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}
```

> 输出结果：

``` txt
1
0
0
1
```
