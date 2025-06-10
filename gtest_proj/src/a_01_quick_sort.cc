#include <gtest/gtest.h>

#include <functional>
#include <stack>
#include <utility>
#include <vector>

// 从 a, b, c 中取中间大的数
int medium3(int* arr, int i, int m, int j) {
    return arr[i] > arr[m] ? (arr[m] > arr[j] ? m : (arr[i] > arr[j] ? j : i))
                           : (arr[i] > arr[j] ? i : (arr[m] > arr[j] ? j : m));
}

void myswap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class Solutiona_01 {
public:
    void qsort(int* arr, int length) {
        if (arr == nullptr || length <= 1) {
            return;
        }
        qsort_internal(arr, 0, length - 1);
    }

    void qsort_no_recursive(int* arr, int length) {
        if (arr == nullptr || length <= 1) {
            return;
        }
        // 核心思路是用栈来模拟递归的过程
        std::stack<std::pair<int, int>> st;
        st.push(std::make_pair(0, length - 1));
        while (!st.empty()) {
            auto range = st.top();
            st.pop();
            int target_idx = qsort_partition(arr, range.first, range.second);
            // [lo, target_idx - 1]
            if (target_idx - range.first > 1) {
                st.push(std::make_pair(range.first, target_idx));
            }
            if (range.second - target_idx > 1) {
                st.push(std::make_pair(target_idx + 1, range.second));
            }
        }
    }

private:
    void qsort_internal(int* arr, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int target_idx = qsort_partition(arr, lo, hi);
        qsort_internal(arr, lo, target_idx - 1);
        qsort_internal(arr, target_idx + 1, hi);
    }

    int qsort_partition(int* arr, int lo, int hi) {
        // 三取样，将 arr[lo], arr[m], arr[hi] 三个元素的中间值交换到 arr[lo] 上
        int m = lo + ((hi - lo) >> 1);
        int medium_idx = medium3(arr, lo, m, hi);
        if (medium_idx != lo) {
            myswap(arr, medium_idx, lo);
        }
        int i = lo + 1;
        int j = hi;
        while (i < j) {
            while (i < j && arr[i] <= arr[lo])
                i++;
            while (i < j && arr[j] >= arr[lo])
                j--;
            if (i < j) {
                myswap(arr, i, j);
            }
        }
        myswap(arr, i - 1, lo);

        return i - 1;
    }
};

TEST(ut_a_01, medium3) {
    std::vector<int> arr = {0, 1, 2, 3};
    EXPECT_EQ(medium3(arr.data(), 1, 2, 3), 2);
    EXPECT_EQ(medium3(arr.data(), 1, 3, 2), 2);
    EXPECT_EQ(medium3(arr.data(), 2, 1, 3), 2);
    EXPECT_EQ(medium3(arr.data(), 2, 3, 1), 2);
    EXPECT_EQ(medium3(arr.data(), 3, 1, 2), 2);
    EXPECT_EQ(medium3(arr.data(), 3, 2, 1), 2);

    EXPECT_EQ(medium3(arr.data(), 2, 2, 1), 2);
    EXPECT_EQ(medium3(arr.data(), 2, 2, 2), 2);
    EXPECT_EQ(medium3(arr.data(), 2, 3, 2), 2);
    EXPECT_EQ(medium3(arr.data(), 2, 3, 3), 3);
}

TEST(ut_a_01, qsort) {
    Solutiona_01 s;

    std::vector<int> arr = {1, 5, 3, 2, 4, 6, 8, 10, 0};
    s.qsort(arr.data(), arr.size());
    EXPECT_TRUE(std::adjacent_find(arr.begin(), arr.end(), std::greater<int>()) == arr.end());
}

TEST(ut_a_01, qsort_no_recursive) {
    Solutiona_01 s;

    std::vector<int> arr = {1, 5, 3, 2, 4, 6, 8, 10, 0};
    s.qsort_no_recursive(arr.data(), arr.size());
    EXPECT_TRUE(std::adjacent_find(arr.begin(), arr.end(), std::greater<int>()) == arr.end());
}
