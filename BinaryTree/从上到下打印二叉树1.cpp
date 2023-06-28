/**
 * @file 从上到下打印二叉树1.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief 层序遍历，BFS 广度优先搜索
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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

// 层序遍历
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }

        vector<int>      res; // 存储层序遍历节点值
        queue<TreeNode*> que; // 存储层序遍历节点

        // 根节点入队
        que.push(root);

        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                // 当前遍历节点
                TreeNode* node = que.front();

                res.push_back(node->val);

                // 当前遍历节点的左节点入队
                if (node->left != nullptr) {
                    que.push(node->left);
                }

                // 当前遍历节点的右节点入队
                if (node->right != nullptr) {
                    que.push(node->right);
                }

                // 当前遍历节点出队
                que.pop();
            }
        }
        return res;
    }
};
