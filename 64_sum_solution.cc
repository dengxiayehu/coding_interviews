#include <iostream>

using namespace std;

class A {
public:
    A() {
        ++instance_count;
        sum += instance_count;
    }

    static int GetSum() {
        int res = sum;
        // 牛客网上提交需要加上Reset()，不然会通不过。
        // 会将之前测试case的值累加下来。
        Reset();
        return res;
    }

    static void Reset() {
        instance_count = 0;
        sum = 0;
    }

private:
    static int instance_count;
    static int sum;
};

int A::instance_count = 0;
int A::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        if (n <= 0) {
            return 0;
        }
        A* array = new A[n];
        delete [] array;
        return A::GetSum();
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().Sum_Solution(3) << endl;

    cout << Solution().Sum_Solution(0) << endl;

    cout << Solution().Sum_Solution(1) << endl;

    cout << Solution().Sum_Solution(5) << endl;

    return 0;
}