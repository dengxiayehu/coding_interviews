# 栈的压入、弹出序列

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

``` cpp
#include <iostream>
#include <vector>
#include <stack>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() && popV.empty()) {
            return true;
        }

        stack<int> s;
        int iin = 0;
        int iout = 0;
        int target;
        while (iout < popV.size()) {
            target = popV[iout]; // 当前需要弹出的数字
            if (s.empty() || s.top() != target) { // 栈为空或者栈顶元素不是我们想要的
                // 从输入序列中压入更多的数字，直到栈顶元素为目标数字
                while (iin < pushV.size() && pushV[iin] != target) {
                    s.push(pushV[iin]);
                    iin++;
                }
                if (iin >= pushV.size()) {
                    // 没有找到目标数字
                    return false;
                }
                iin++; // 从输入序列中取出target数字
            } else {
                s.pop();
            }
            iout++;
        }

        return iout == popV.size();
    }
};

int main(int argc, char *argv[])
{
    // 4,5,3,2,1 ok
    // 4,3,5,1,2 bad
    int arr_push[] = { 1, 2, 3, 4, 5 };
    // int arr_pop[] = { 4, 5, 3, 2, 1 };
    int arr_pop[] = { 4, 3, 5, 1, 2 };
    cout << Solution().IsPopOrder(vector<int>(arr_push, arr_push+NELEM(arr_push)), 
                                  vector<int>(arr_pop, arr_pop+NELEM(arr_pop)));
    return 0;
}
```