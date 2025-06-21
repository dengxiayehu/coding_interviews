#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <vector>

template <typename T, typename Compare>
static void merge_sort_internal(T* arr, int l, int r, T* tmp) {
    if (l >= r) {
        return;
    }
    Compare compare;
    int mid = l + ((r - l) >> 1);
    merge_sort_internal<T, Compare>(arr, l, mid, tmp);
    merge_sort_internal<T, Compare>(arr, mid + 1, r, tmp);
    // merge
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= r) {
        if (compare(arr[i], arr[j])) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }
    while (j <= r) {
        tmp[k++] = arr[j++];
    }
    // 临时数组中内容再拷贝回去
    for (k = l; k <= r; k++) {
        arr[k] = tmp[k];
    }
}

// Compare 表示最终排序之后数组中各元素的状态
template <typename T, typename Compare = std::less_equal<T>>
void merge_sort(T* arr, int num) {
    if (arr == nullptr || num <= 1) {
        return;
    }

    T* tmp = new T[num];
    merge_sort_internal<T, Compare>(arr, 0, num - 1, tmp);
    delete[] tmp;
}

TEST(ut_a_03, merge_sort) {
    std::vector<int> arr = {1, 5, 3, 2, 4, 6, 8, 10, 0};
    merge_sort(arr.data(), arr.size());
    EXPECT_TRUE(std::adjacent_find(arr.begin(), arr.end(), std::greater<int>()) == arr.end());

    merge_sort<int, std::greater<int>>(arr.data(), arr.size());
    EXPECT_TRUE(std::adjacent_find(arr.begin(), arr.end(), std::less<int>()) == arr.end());
}
