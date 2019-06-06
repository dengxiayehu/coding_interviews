# 矩阵中的路径

> 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

在矩阵中查找路径通常使用回溯法，通常需要结合标记数组一并进行。

``` cpp
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
```

> 运行结果：  
bcced found  
abcb not found