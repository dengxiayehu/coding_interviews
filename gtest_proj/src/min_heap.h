#pragma once

#include <vector>

// 1. 使用数组来实现最小堆，最小的元素在数组的索引 0
// 2. 一棵满二叉树
// 3. 父节点比左右子节点的值都小
// 4. 父节点索引 i，左子节点索引 2 * i + 1，右子节点索引 2 * i + 2
// 5. 左右子节点索引若为 i，父节点索引则为 (i - 1) / 2
// 其中 4, 5 两点非常关键，不能搞错。
template <typename T>
class MinHeap final {
public:
    MinHeap() {
    }

    ~MinHeap() {
    }

    // 新元素添加到数组的最后，然后做上浮操作
    void Insert(T val) {
        m_arr.push_back(val);
        Up(m_arr.size() - 1);
    }

    T ExtractMin() {
        T val = m_arr[0];
        m_arr[0] = m_arr.back();
        m_arr.pop_back();
        Down(0);

        return val;
    }

    T Min() const {
        return m_arr[0];
    }

    bool Empty() const {
        return m_arr.empty();
    }

    size_t Size() const {
        return m_arr.size();
    }

private:
    void Up(int idx) {
        if (idx > 0) {
            int parent_idx = ((idx - 1) >> 1);
            if (m_arr[parent_idx] > m_arr[idx]) {
                // 父节点值比当前值大，需要交换
                myswap(m_arr, parent_idx, idx);
                Up(parent_idx);
            }
        }
    }

    void Down(int idx) {
        int min_idx = idx;
        int left_idx = (idx << 1) + 1;
        int right_idx = (idx << 1) + 2;
        if (left_idx < m_arr.size() && m_arr[left_idx] < m_arr[idx]) {
            min_idx = left_idx;
        }
        if (right_idx < m_arr.size() && m_arr[right_idx] < m_arr[min_idx]) {
            min_idx = right_idx;
        }
        if (min_idx != idx) {
            myswap(m_arr, min_idx, idx);
            Down(min_idx);
        }
    }

    void myswap(std::vector<T>& arr, int i, int j) {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

private:
    std::vector<T> m_arr;
};
