/**
 * @file 从上到下打印二叉树2.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * @version 0.1
 * @date 2023-06-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从上到下打印二叉树
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*>    que;

        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            res.push_back(vector<int>());
            while (size--) {
                TreeNode* node = que.front();
                res.back().push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
                que.pop();
            }
        }
        return res;
    }
};
