# 包含min函数的栈

> 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

``` cpp
#include <iostream>
#include <stack>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    void push(int value) {
        s_.push(value);
        if (min_s_.empty()) {
            min_s_.push(value);
        } else {
            if (value < min_s_.top()) {
                min_s_.push(value);
            } else {
                min_s_.push(min_s_.top());
            }
        }
    }

    void pop() {
        if (!s_.empty()) {
            s_.pop();
            min_s_.pop();
        }
    }

    int top() {
        if (s_.empty()) {
            return -1;
        }

        return s_.top();
    }

    int min() {
        if (min_s_.empty()) {
            return -1;
        }

        return min_s_.top();
    }

private:
    stack<int> s_;
    stack<int> min_s_;
};

int main(int argc, char *argv[])
{
    Solution s;
    s.push(1);
    cout << s.min() << endl;
    s.pop();
    s.push(3);
    s.push(5);
    cout << s.min() << endl;
    return 0;
}
```

> 输出结果：  
1  
3