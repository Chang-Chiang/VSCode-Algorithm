/**
 * @file 栈的压入弹出序列.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 * https://leetcode-cn.com/problems/validate-stack-sequences/
 * @version 0.1
 * @date 2023-06-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 栈的压入弹出序列
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // 存储入栈元素

        for (int i = 0, j = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]); // 模拟入栈

            // 出栈元素满足入栈顺序则将入栈元素弹出
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution    s;
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}
