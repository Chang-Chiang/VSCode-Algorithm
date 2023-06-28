/**
 * @file 对称的二叉树.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/
 * https://leetcode-cn.com/problems/symmetric-tree/
 * @version 0.1
 * @date 2023-06-27
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

// 对称的二叉树
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
private:
    // check 左右子树是否对称
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left == nullptr || right == nullptr || left->val != right->val) {
            return false;
        }
        return check(left->left, right->right) && check(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return check(root->left, root->right);
    }
};
