/**
 * @file 二叉树的深度.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * @version 0.1
 * @date 2023-06-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 时间复杂度 O(N)
// 空间复杂度 O(Height)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    // [3,9,20,null,null,15,7]
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    Solution s;
    cout << s.maxDepth(node1) << endl;
    return 0;
}
