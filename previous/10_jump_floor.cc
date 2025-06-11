#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }
        if (number == 2) {
            return 2;
        }
        int floor_minus_1 = 2;
        int floor_minus_2 = 1;
        int floor;
        for (int i = 3; i <= number; i++) {
            floor = floor_minus_1 + floor_minus_2;
            floor_minus_2 = floor_minus_1;
            floor_minus_1 = floor;
        }

        return floor;
    }
};

int main(int argc, char const* argv[]) {
    cout << Solution().jumpFloor(-1) << endl;
    cout << Solution().jumpFloor(0) << endl;
    cout << Solution().jumpFloor(1) << endl;
    cout << Solution().jumpFloor(4) << endl;

    return 0;
}
