/**
 * @file 从上到下打印二叉树3.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-06-27
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

// 之字形层序遍历二叉树
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
        bool isOrderLeft = true; // 之字形遍历顺序

        while (!que.empty()) {
            int size = que.size(); // 每层节点个数

            deque<int> deq;        // 双端队列存放之字形的每层遍历
            while (size--) {
                TreeNode* node = que.front();

                if (isOrderLeft) {
                    deq.push_back(node->val);
                }
                else {
                    deq.push_front(node->val);
                }

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }

                que.pop();
            }
            // push_back 与 emplace_back 性能差异
            res.emplace_back(vector<int>{deq.begin(), deq.end()});
            isOrderLeft = !isOrderLeft;
        }
        return res;
    }
};
