#include <iostream>
#include <set>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    void Insert(int num) {
        if ((max_heap_.size() + min_heap_.size()) & 1) {  // odd, insert into left max_heap
            // First, check whether right min_heap's min value is smaller than num,
            // if so, pop a value from min_heap and insert it into max_heap.
            if (!min_heap_.empty()) {
                MinHeapIterator it = min_heap_.begin();
                if (*it < num) {
                    int min_right = *it;
                    min_heap_.erase(it);
                    min_heap_.insert(num);
                    num = min_right;
                }
            }

            max_heap_.insert(num);
        } else {  // even, insert into right min_heap
            if (!max_heap_.empty()) {
                MaxHeapIterator it = max_heap_.begin();
                if (*it > num) {
                    int max_left = *it;
                    max_heap_.erase(it);
                    max_heap_.insert(num);
                    num = max_left;
                }
            }

            min_heap_.insert(num);
        }
    }

    double GetMedian() {
        int strm_size = min_heap_.size() + max_heap_.size();
        if (strm_size == 0) {
            return 0;
        }
        if (strm_size & 1) {
            return *min_heap_.begin();
        }
        return ((double)(*min_heap_.begin()) + (double)(*max_heap_.begin())) / 2;
    }

private:
    typedef multiset<int, greater<int>>::iterator MaxHeapIterator;
    typedef multiset<int, less<int>>::iterator MinHeapIterator;
    multiset<int, greater<int>> max_heap_;
    multiset<int, less<int>> min_heap_;
};

int main(int argc, char* argv[]) {
    Solution s;
    cout << s.GetMedian() << endl;

    s.Insert(1);
    s.Insert(2);
    cout << s.GetMedian() << endl;

    s.Insert(3);
    cout << s.GetMedian() << endl;

    s.Insert(0);
    cout << s.GetMedian() << endl;

    return 0;
}