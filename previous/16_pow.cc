#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        bool negative_exp = false;
        if (exponent < 0) {
            negative_exp = true;
            exponent = -exponent;
        }

        if (equal(base, 0) && exponent == 0) {
            // 0^0, illegale
            return 0;
        }

        double res = power_core(base, exponent);
        if (negative_exp) {
            if (res == 0) {
                return 0;
            }
            return 1 / res;
        } else {
            return res;
        }
    }

private:
    double power_core(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }

        if (exponent & 1) {
            return base * power_core(base * base, exponent >> 1);
        } else {
            return power_core(base * base, exponent >> 1);
        }
    }

    // 判断两个浮点数是否相等的算法，注意千万别在简单的地方翻船啊！
    // 写算法永远用最最简单、最直接的方法来实现，不要在细枝末节处乱抠技巧。Think clearly.
    static bool equal(float val, float target) {
        return abs(val - target) <= __DBL_EPSILON__;

        // 下面这个代码估计是喝醉酒时候写的！
        // return val - target <= __DBL_EPSILON__ || target - val <= __DBL_EPSILON__;
    }
};

int main(int argc, char const* argv[]) {
    cout << Solution().Power(2, 4) << endl;
    cout << Solution().Power(0, 0) << endl;
    cout << Solution().Power(0, 2) << endl;
    cout << Solution().Power(0, -2) << endl;
    cout << Solution().Power(2, 0) << endl;

    return 0;
}
