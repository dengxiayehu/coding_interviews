《剑指 offer》 第二版刷题，总共有 66 道题。 为便于本地编译和运行，源码工程使用 cmake 管理，用例结合 gtest 验证。
#### 编译及运行
```
# 进入源码根目录
cd gtest_proj
# 编译
./build.sh
# 运行
./run.sh
```
#### 题解链接
| No. | 题目 | 题解 |
| :-: | :- | :- |
| 1 | 赋值运算符函数 | [01_assignment_operation.cc](gtest_proj/src/01_assignment_operation.cc)</br><blockquote>异常安全的赋值操作</blockquote> |
| 2 | 实现单例模式 | [02_singleton.cc](gtest_proj/src/02_singleton.cc)</br><blockquote>线程安全，程序退出时单例对象析构</blockquote> |
| 2_1 | 子类单例子模式 | [02_1_singleton_derived.cc](gtest_proj/src/02_1_singleton_derived.cc)</br><blockquote>基于同一个基类的所有子类均使用单例模式</blockquote> |
| 3 | 数组中重复的数字 | [03_duplication_in_array.cc](gtest_proj/src/03_duplication_in_array.cc)</br><blockquote>将数字放在应该出现的位置，会修改原数组</blockquote> |
| 3_1 | 不修改数组找出重复的数字 | [03_1_duplication_in_array_no_edit.cc](gtest_proj/src/03_1_duplication_in_array_no_edit.cc)</br><blockquote>使用两种办法求解：第一种是临时数组，第二种是类比二分法（分别数大于/小于指定数的个数）</blockquote> |
| 3_2 | 不修改数组找出重复的数字 | [03_2_duplication_in_array_no_edit_once.cc](gtest_proj/src/03_2_duplication_in_array_no_edit_once.cc)</br><blockquote>转换为环形链表检测求解，效率最高</blockquote> |
| 4 | 二维数组中的查找 | [04_find_in_partially_sorted_matrix.cc](gtest_proj/src/04_find_in_partially_sorted_matrix.cc)</br><blockquote>能想到从右上角（或左下角）开始“两分”查找</blockquote> |
| 5 | 替换空格 | [05_replace_spaces.cc](gtest_proj/src/05_replace_spaces.cc)</br><blockquote>先统计字符串中出现空格的次数，然后再从右往左处理</blockquote> |
| 5_1 | 替换空格 | [05_1_replace_spaces_faster.cc](gtest_proj/src/05_1_replace_spaces_faster.cc)</br><blockquote>既然 str 中空间足够，则直接从 str 最后位置开始处理，省去一次统计空格的操作</blockquote> |
| 6 | 从尾到头打印链表 | [06_print_list_in_reversed_order.cc](gtest_proj/src/06_print_list_in_reversed_order.cc)</br><blockquote>递归法</blockquote> |
| 6_1 | 从尾到头打印链表 | [06_1_print_list_in_reversed_order_stack.cc](gtest_proj/src/06_1_print_list_in_reversed_order_stack.cc)</br><blockquote>借助堆栈</blockquote> |
| 7 | 重建二叉树 | [07_construct_binary_tree.cc](gtest_proj/src/07_construct_binary_tree.cc)</br><blockquote>根据先序节点在中序节点数组中查找，左边为左子树，右边为右子树</blockquote> |
| 8 | 二叉树的下一个节点 | [08_next_node_in_binary_tree.cc](gtest_proj/src/08_next_node_in_binary_tree.cc)</br><blockquote>考虑节点是否有右子树</blockquote> |
| 9 | 用两个栈实现队列 | [09_queue_with_two_stacks.cc](gtest_proj/src/09_queue_with_two_stacks.cc)</br><blockquote>永远只在一个栈入栈</blockquote> |
| 9_1 | 用两个栈实现队列 | [09_1_stack_with_two_queues.cc](gtest_proj/src/09_1_stack_with_two_queues.cc)</br><blockquote>队列 1 拷贝到队列 2 仅保留一个元素，top 用成员变量记录</blockquote> |
| 10 | 青蛙跳台阶 | [10_jump_floor.cc](gtest_proj/src/10_jump_floor.cc)</br><blockquote>转换为斐波那契数列求解</blockquote> |
| 10_1 | 青蛙变态跳台阶 | [10_1_crasy_jump_floor.cc](gtest_proj/src/10_1_crasy_jump_floor.cc)</br><blockquote>每一阶台阶要么跳要么不跳，转换为快速乘方算法</blockquote> |
| 10_2 | 矩形覆盖 | [10_2_rect_cover.cc](gtest_proj/src/10_2_rect_cover.cc)</br><blockquote>转换为斐波那契数列求解</blockquote> |
| 11 | 旋转数组中的最小值 | [11_min_number_in_rotated_array.cc](gtest_proj/src/11_min_number_in_rotated_array.cc)</br><blockquote>两分思想，注意先用 m 和 hi 位置元素比较</blockquote> |
| 11 | 寻找旋转排序数组中的最小值 | [11_1_min_number_in_rotated_array_no_duplication.cc](gtest_proj/src/11_1_min_number_in_rotated_array_no_duplication.cc)</br><blockquote>leetcode 上类似题目，但没有重复元素，比《剑指 Offer》上的题目简单</blockquote> |
| 12 | 矩阵中的路径 | [12_exist.cc](gtest_proj/src/12_exist.cc)</br><blockquote>典型的 dfs 遍历算法，结合使用标记数组</blockquote> |
| 13 | 机器人的运动路径 | [13_moving_count.cc](gtest_proj/src/13_moving_count.cc)</br><blockquote>dfs 算法，结合使用标记数组</blockquote> |
| 14 | 剪绳子 | [14_cut_the_rope_memo.cc](gtest_proj/src/14_cut_the_rope_memo.cc)</br><blockquote>dp 备忘录算法，递归</blockquote> |
| 14_1 | 剪绳子 | [14_1_cut_the_rope_memo_no_recursive.cc](gtest_proj/src/14_1_cut_the_rope_memo_no_recursive.cc)</br><blockquote>dp 备忘录算法，迭代</blockquote> |
| 15 | 二进制中 1 的个数 | [15_hamming_weight.cc](gtest_proj/src/15_hamming_weight.cc)</br><blockquote>数二进制表示中 1 的个数，是否为负数算法不同</blockquote> |
| 16 | 数值的整数次方 | [16_power.cc](gtest_proj/src/16_power.cc)</br><blockquote>快速乘方算法</blockquote> |
| 17 | 打印从 1 到最大的 n 位数 | [17_print_1_to_max_of_n_digits.cc](gtest_proj/src/17_print_1_to_max_of_n_digits.cc)</br><blockquote>使用字符串模拟不断 +1 的过程</blockquote> |
| 17_1 | 打印从 1 到最大的 n 位数 | [17_1_print_1_to_max_of_n_digits_full_arrangement.cc](gtest_proj/src/17_1_print_1_to_max_of_n_digits_full_arrangement.cc)</br><blockquote>转换为全排列算法</blockquote> |
| 18 | 删除链表的节点 | [18_delete_node.cc](gtest_proj/src/18_delete_node.cc)</br><blockquote>头尾节点特殊处理，中间节点与下一个节点值交换再删除下一个节点</blockquote> |
| 18_1 | 删除链表的节点 | [18_1_delete_node.cc](gtest_proj/src/18_1_delete_node.cc)</br><blockquote>用一前一后两个指针遍历</blockquote> |
| 18_2 | 删除排序链表中的重复元素 | [18_2_delete_duplication.cc](gtest_proj/src/18_2_delete_duplication.cc)</br><blockquote>主要是能想到三指针算法</blockquote> |
| 19 | 正则表达式匹配 | [19_match_recursive.cc](gtest_proj/src/19_match_recursive.cc)</br><blockquote>递归法处理非最优，判断当前字符的下一个字符是否为 *</blockquote> |
| 20 | 表示数值的字符串 | [20_is_numeric_stupid.cc](gtest_proj/src/20_is_numeric_stupid.cc)</br><blockquote>注意校验规则，A[.[B]][e\|EC] 或者 .B[e\|EC]，过程有点啰嗦</blockquote> |
| 20_1 | 有效数字 | [20_1_is_numeric.cc](gtest_proj/src/20_1_is_numeric.cc)</br><blockquote>更清晰的解法</blockquote> |
| 21 | 调整数组顺序使奇数位于偶数前面 | [21_reorder_array.cc](gtest_proj/src/21_reorder_array.cc)</br><blockquote>类似快排里面的 partition 算法</blockquote> |
| 22 | 链表中倒数第 k 个节点 | [22_find_kth_to_tail.cc](gtest_proj/src/22_find_kth_to_tail.cc)</br><blockquote>注意鲁棒性</blockquote> |
| 22_1 | 删除链表的倒数第 N 个节点 | [22_1_remove_kth_to_tail.cc](gtest_proj/src/22_1_remove_kth_to_tail.cc)</br><blockquote>一前一后两个指针</blockquote> |
| 23 | 链表中环的入口节点 | [23_entry_node_of_loop.cc](gtest_proj/src/23_entry_node_of_loop.cc)</br><blockquote>快慢指针，定位环的入口</blockquote> |
| 24 | 反转链表 | [24_reverse_list.cc](gtest_proj/src/24_reverse_list.cc)</br><blockquote>将遍历的节点插入到新链表头</blockquote> |
| 25 | 合并两个排序的链表 | [25_merge.cc](gtest_proj/src/25_merge.cc)</br><blockquote>先一起处理两个链表，再拼接剩余的非空链表</blockquote> |
| 26 | 树的子结构 | [26_has_subtree.cc](gtest_proj/src/26_has_subtree.cc)</br><blockquote>先序检查（先根再左子树再右子树），递归</blockquote> |
| 27 | 二叉树的镜像 | [27_mirror_recursively.cc](gtest_proj/src/27_mirror_recursively.cc)</br><blockquote>交换节点的左右节点，再递归分别处理左右子树，原树结构被改变</blockquote> |
| 27_1 | 二叉树的镜像 | [27_1_mirror_recursively_dup.cc](gtest_proj/src/27_1_mirror_recursively_dup.cc)</br><blockquote>复制一颗镜像树，原树结构不变</blockquote> |
| 28 | 对称的二叉树 | [28_is_symmetric.cc](gtest_proj/src/28_is_symmetric.cc)</br><blockquote>定义两种遍历方式，l 是先序遍历，r 是先根后右再左</blockquote> |
| 29 | 顺时针打印矩阵 | [29_spiral_order.cc](gtest_proj/src/29_spiral_order.cc)</br><blockquote>思路要清晰，退出条件</blockquote> |
| 30 | 包含 min 函数的栈 | [30_min_in_stack.cc](gtest_proj/src/30_min_in_stack.cc)</br><blockquote>辅助栈的思路</blockquote> |
| 30_1 | 包含 min 函数的栈 | [30_1_min_in_stack.cc](gtest_proj/src/30_1_min_in_stack.cc)</br><blockquote>单调栈算法，很巧妙，连辅助栈都省了</blockquote> |
| 31 | 栈的压入、弹出序列 | [31_is_pop_order.cc](gtest_proj/src/31_is_pop_order.cc)</br><blockquote>使用一个栈来模拟压栈和出栈</blockquote> |
| 32 | 从上到下打印二叉树 | [32_print_from_top_to_bottom.cc](gtest_proj/src/32_print_from_top_to_bottom.cc)</br><blockquote>使用一个队列，先入队根节点再进入循环，分别入队左右节点</blockquote> |
| 32_1 | 分行从上到下打印二叉树 | [32_1_print_from_top_to_bottom_lines.cc](gtest_proj/src/32_1_print_from_top_to_bottom_lines.cc)</br><blockquote>使用一个队列，同时想到当前行个数和下一行个数的统计</blockquote> |
| 32_2 | 分行从下到上打印二叉树 | [32_2_print_from_bottom_to_top_lines.cc](gtest_proj/src/32_2_print_from_bottom_to_top_lines.cc)</br><blockquote>在 32_1 的算法基础上逆序结果即可</blockquote> |
| 32_3 | 之字形打印二叉树 | [32_3_zigzag_level_order.cc](gtest_proj/src/32_3_zigzag_level_order.cc)</br><blockquote>使用队列（用来层序遍历）和栈（反方向逆序结果），注意方向的切换条件</blockquote> |
| 32_4 | 之字形打印二叉树 | [32_4_zigzag_level_order_with_two_stacks.cc](gtest_proj/src/32_4_zigzag_level_order_with_two_stacks.cc)</br><blockquote>使用两个栈实现的更优算法</blockquote> |
| 33 | 二叉搜索树的后序遍历序列 | [33_verify_postorder.cc](gtest_proj/src/33_verify_postorder.cc)</br><blockquote>参考区间最右边元素，大于它的在右子树，小于它的在左子树</blockquote> |
| 34 | 二叉树中和为某一值的路径 | [34_path_sum.cc](gtest_proj/src/34_path_sum.cc)</br><blockquote>递归，符合条件的单条路径节点 vector 也作为参数传递</blockquote> |
| 35 | 复杂链表的复制 | [35_copy_random_list.cc](gtest_proj/src/35_copy_random_list.cc)</br><blockquote>先以原链表为基础，在每个节点后面在复制对应的一个节点</blockquote> |
| 36 | 二叉搜索树与双向链表 | [36_tree_to_doubly_list.cc](gtest_proj/src/36_tree_to_doubly_list.cc)</br><blockquote>中序遍历原二叉搜索树</blockquote> |
| 37 | 序列化二叉树 | [37_serialize_deserialize.cc](gtest_proj/src/37_serialize_deserialize.cc)</br><blockquote>可以使用先序遍历序列化和反序列化</blockquote> |
| 38 | 字符串的排列 | [38_permute.cc](gtest_proj/src/38_permute.cc)</br><blockquote>全排列算法，会交换字符串中的字符</blockquote> |
| 38_1 | 字符串的排列 | [38_1_permute.cc](gtest_proj/src/38_1_permute.cc)</br><blockquote>结合标记数组使用，原始字符串不会改变</blockquote> |
| 39 | 数组中出现次数超过一半的数字 | [39_majority_element.cc](gtest_proj/src/39_majority_element.cc)</br><blockquote>借助快速排序的思想，确认索引在 n/2 位置的元素</blockquote> |
| 39_1 | 多数元素 | [39_1_majority_element_faster.cc](gtest_proj/src/39_1_majority_element_faster.cc)</br><blockquote>最优算法，借助计数器思想</blockquote> |
| 40 | 最小的 k 个数 | [40_get_least_numbers.cc](gtest_proj/src/40_get_least_numbers.cc)</br><blockquote>先快速排序再取前 k 个数，不是最优</blockquote> |
| 40_1 | 数组中的第 k 个最大元素 | [40_1_find_kth_largest.cc](gtest_proj/src/40_1_find_kth_largest.cc)</br><blockquote>使用三采样优化的快速排序算法</blockquote> |
| 40_2 | 数组中的第 k 个最大元素 | [40_2_find_kth_largest.cc](gtest_proj/src/40_2_find_kth_largest.cc)</br><blockquote>使用最小堆算法</blockquote> |
| 41 | 数据流中的中位数 | [41_median_finder.cc](gtest_proj/src/41_median_finder.cc)</br><blockquote>左侧最大堆，右侧最小堆。不满足塞入左侧最大堆的都塞入右侧最小堆</blockquote> |
| 42 | 连续子数组的最大和 | [42_max_sub_array.cc](gtest_proj/src/42_max_sub_array.cc)</br><blockquote>典型的动态规划算法</blockquote> |
| 43 | 1~n 整数中 1 出现的次数 | [43_count_digit_one.cc](gtest_proj/src/43_count_digit_one.cc)</br><blockquote>自行车密码锁思想</blockquote> |
| 44 | 数字序列中某一位的数字 | [44_digit_at_index.cc](gtest_proj/src/44_digit_at_index.cc)</br><blockquote>先计算 n 位数总共有几个字符，然后在某个 n 位数中继续处理</blockquote> |
| 44_1 | 第 N 位数字 | [44_1_find_nth_digit.cc](gtest_proj/src/44_1_find_nth_digit.cc)</br><blockquote>这道题和剑指 offer 上的类似，只是形式更规整，数字从 0 开始</blockquote> |
| 45 | 把数组排成最小的数 | [45_print_min_number.cc](gtest_proj/src/45_print_min_number.cc)</br><blockquote>自定义排序算法，比较两个数字拼接之后的大小</blockquote> |
| 45_1 | 最大数 | [45_1_largest_number.cc](gtest_proj/src/45_1_largest_number.cc)</br><blockquote>与 45 题类似，调整一下自定义排序算法即可</blockquote> |
| 46 | 把数字翻译成字符串 | [46_get_translation_count.cc](gtest_proj/src/46_get_translation_count.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 46_1 | 解码方法 | [46_1_num_decodings.cc](gtest_proj/src/46_1_num_decodings.cc)</br><blockquote>leetcode 上这一题和《剑指 Offer》上不同，对字符 '0' 的解码约束更强</blockquote> |
| 47 | 礼物的最大价值 | [47_max_value_solution.cc](gtest_proj/src/47_max_value_solution.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 47_1 | 礼物价值最小 | [47_1_min_path_sum.cc](gtest_proj/src/47_1_min_path_sum.cc)</br><blockquote>dfs + 标记数组，效率不高</blockquote> |
| 47_2 | 最小路径和 | [47_2_min_path_sum.cc](gtest_proj/src/47_2_min_path_sum.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 48 | 最长不含重复字符的子字符串 | [48_length_of_longest_substring_dp.cc](gtest_proj/src/48_length_of_longest_substring_dp.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 48_1 | 最长不含重复字符的子字符串 | [48_1_length_of_longest_substring_sliding_window.cc](gtest_proj/src/48_1_length_of_longest_substring_sliding_window.cc)</br><blockquote>滑动窗口算法，判断是否存在使用哈希表 hash[256]</blockquote> |
| 49 | 丑数 | [49_ugly_number.cc](gtest_proj/src/49_ugly_number.cc)</br><blockquote>从检测丑数变成如何按顺序生成丑数</blockquote> |
| 50 | 第一个只出现一次的字符 | [50_first_uniq_char.cc](gtest_proj/src/50_first_uniq_char.cc)</br><blockquote>哈希表使用 hash[128]</blockquote> |
| 50_1 | 字符流中第一个只出现一次字符 | [50_1_first_not_repeating_char.cc](gtest_proj/src/50_1_first_not_repeating_char.cc)</br><blockquote>哈希表使用 hash[256]</blockquote> |
| 51 | 数组中的逆序对 | [51_reverse_pairs.cc](gtest_proj/src/51_reverse_pairs.cc)</br><blockquote>结合归并排序的思想处理</blockquote> |
| 51_1 | 翻转对 | [51_1_reverse_pairs_cond.cc](gtest_proj/src/51_1_reverse_pairs_cond.cc)</br><blockquote>判定为翻转对的条件与《剑指 Offer》上不同，但思路相同</blockquote> |
| 52 | 两个链表的第一个公共节点 | [52_get_intersection_node.cc](gtest_proj/src/52_get_intersection_node.cc)</br><blockquote>先求各自长度，长的先走几步</blockquote> |
| 53 | 排序数组中查找元素出现的起止 | [53_number_of_k.cc](gtest_proj/src/53_number_of_k.cc)</br><blockquote>已经排序，使用二分查找思想，相同时取 left most 和 right most</blockquote> |
| 53_1 | 0-n-1 中缺失的数字 | [53_1_get_missing_number.cc](gtest_proj/src/53_1_get_missing_number.cc)</br><blockquote>已经排序，使用二分查找思想，注意缺最左/右两个数的情况</blockquote> |
| 53_2 | 丢失的数字 | [53_2_missing_number.cc](gtest_proj/src/53_2_missing_number.cc)</br><blockquote>使用数学公式或使用异或处理</blockquote> |
| 53_3 | 数组中数值和下标相等的元素 | [53_3_get_number_same_as_index.cc](gtest_proj/src/53_3_get_number_same_as_index.cc)</br><blockquote>数组已经有序，两分思想</blockquote> |
| 54 | 二叉搜索树的第 k 大节点 | [54_kth_smallest.cc](gtest_proj/src/54_kth_smallest.cc)</br><blockquote>使用中序遍历</blockquote> |
| 55 | 二叉树的深度 | [55_max_depth.cc](gtest_proj/src/55_max_depth.cc)</br><blockquote>分别递归处理左右子树</blockquote> |
| 55_1 | 平衡二叉树 | [55_1_is_balanced.cc](gtest_proj/src/55_1_is_balanced.cc)</br><blockquote>分别递归算左右子树的深度</blockquote> |
| 56 | 只出现一次的数字 | [56_single_number.cc](gtest_proj/src/56_single_number.cc)</br><blockquote>先找到两个数的异或值，根据值中的某个比特 1 将原数组对半分，则该两个数分别在不同侧</blockquote> |
| 56_1 | 只出现一次的数字 | [56_1_find_number_appearing_once.cc](gtest_proj/src/56_1_find_number_appearing_once.cc)</br><blockquote>将数拆成对应比特位相加，3N+1 的便是只出现一次的数字比特位</blockquote> |
| 57 | 和为 s 的数字 | [57_two_sum.cc](gtest_proj/src/57_two_sum.cc)</br><blockquote>数组已经有序，使用二分查找思想</blockquote> |
| 57_1 | 和为 s 的连续整数序列 | [57_1_find_continuous_sequence.cc](gtest_proj/src/57_1_find_continuous_sequence.cc)</br><blockquote>数组虽然无序，但仍可以使用二分思想，small 和 bit 索引</blockquote> |
| 57_2 | 连续整数求和 | [57_2_consecutive_numbers_sum.cc](gtest_proj/src/57_2_consecutive_numbers_sum.cc)</br><blockquote>与《剑指 Offer》的区别是不限定至少两个元素，最优算法是数学方法，暂略</blockquote> |
| 58 | 反转字符串中的单词 | [58_reverse_words.cc](gtest_proj/src/58_reverse_words.cc)</br><blockquote>单词倒置和整体字符串倒置</blockquote> |
| 58_1 | 左旋转字符串 | [58_1_left_rotate_string.cc](gtest_proj/src/58_1_left_rotate_string.cc)</br><blockquote>杂技翻转算法</blockquote> |
| 58_2 | 字符串的左右移 | [58_2_string_shift.cc](gtest_proj/src/58_2_string_shift.cc)</br><blockquote>先整体处理左右移最终的结果是左移多少</blockquote> |
| 58_3 | 轮转数组 | [58_3_rotate.cc](gtest_proj/src/58_3_rotate.cc)</br><blockquote>将右移转换为左移后使用杂技翻转算法</blockquote> |
| 59 | 滑动窗口最大值 | [59_max_sliding_window.cc](gtest_proj/src/59_max_sliding_window.cc)</br><blockquote>单调队列思想</blockquote> |
| 59_1 | 队列的最大值 | [59_1_queue_with_max.cc](gtest_proj/src/59_1_queue_with_max.cc)</br><blockquote>需要自行维护一个索引信息（借助 deque），用来在弹出一个元素时判断 max top 是否需要弹出</blockquote> |
| 60 | 掷骰子等于目标和的方法数 | [60_num_rolls_to_target.cc](gtest_proj/src/60_num_rolls_to_target.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 61 | 扑克牌中的顺子 | [61_is_continuous.cc](gtest_proj/src/61_is_continuous.cc)</br><blockquote>确认大小王填充上数字中的间隔是否能填满</blockquote> |
| 62 | 圆圈中最后剩下的数字 | [62_last_remaining.cc](gtest_proj/src/62_last_remaining.cc)</br><blockquote>采用链表模拟报数的过程</blockquote> |
| 63 | 股票的最大利润 | [63_max_profit.cc](gtest_proj/src/63_max_profit.cc)</br><blockquote>考虑用动态规划算法</blockquote> |
| 64 | 求 1+2+...+n | [64_sum_1_to_n.cc](gtest_proj/src/64_sum_1_to_n.cc)</br><blockquote>数列求和思想创建 n * (n + 1) 个对象，结合构造函数计数器，结果 >> 1</blockquote> |
| 65 | 不用加减乘除做加法 | [65_add.cc](gtest_proj/src/65_add.cc)</br><blockquote>异或思想</blockquote> |
| 67 | 字符串转整型 | [67_my_atoi.cc](gtest_proj/src/67_my_atoi.cc)</br><blockquote>需考虑的点比较多，例如非法字符、正负溢出等</blockquote> |
