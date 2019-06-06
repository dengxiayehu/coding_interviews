#include <iostream>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        if (!matrix || rows <= 0 || cols <= 0 || !str || !str[0]/*empty str*/) {
            return false;
        }
        if (strlen(matrix) != rows*cols) {
            return false;
        }

        bool found = false;
        bool *v = new bool[rows*cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                memset(v, false, rows*cols); // 重置标记数组
                if (has_path_core(matrix, rows, cols, str, v, i, j, 0)) {
                    found = true;
                    goto out;
                }
            }
        }

out:
        delete [] v;
        
        return found;
    }

private:
    bool has_path_core(const char *matrix, const int rows, const int cols, const char *str,
                       bool *v, const int i, const int j, const int idx) {
        if (str[idx] == '\0') {
            // 成功找到匹配。
            return true;
        }

        // 根据行列索引在二维数组中索引元素千万别犯低级错误，正确的应该是i*cols+j！

        if (i < 0 || i >= rows || j < 0 || j >= cols || v[i*cols+j]) {
            // 当前位置已经被占用或者非法，直接返回。
            return false;
        }

        bool res = false;
        // 当前位置没有被占用，判断当前位置的字符是否和对应的str中字符对应，若是，则占用此空间。
        if (str[idx] == matrix[i*cols+j]) {
            v[i*cols+j] = true;
            res = has_path_core(matrix, rows, cols, str, v, i-1, j, idx+1) ||
                  has_path_core(matrix, rows, cols, str, v, i+1, j, idx+1) ||
                  has_path_core(matrix, rows, cols, str, v, i, j-1, idx+1) ||
                  has_path_core(matrix, rows, cols, str, v, i, j+1, idx+1);
            v[i*cols+j] = false;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    /*
     * a b c e
     * s f c s
     * a d e e
     * */
    char matrix[] = "abcesfcsadee";
    char str[] = "bcced";
    if (Solution().hasPath(matrix, 3, 4, str)) {
        cout << str << " found" << endl;
    } else {
        cout << str << " not found" << endl;
    }

    char str1[] = "abcb";
    if (Solution().hasPath(matrix, 3, 4, str1)) {
        cout << str1 << " found" << endl;
    } else {
        cout << str1 << " not found" << endl;
    }

    return 0;
}
