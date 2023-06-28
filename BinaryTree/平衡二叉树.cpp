/**
 * @file 平衡二叉树.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/
 * https://leetcode-cn.com/problems/balanced-binary-tree/
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

// 判断是否是平衡二叉树
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
private:
    // 计算以 root 为节点的平衡二叉树的高度
    // 若为平衡二叉树，则返回其高度
    // 不为平衡二叉树，返回 -1
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // 不为平衡二叉树，返回 -1
        if (height(root->left) == -1 || height(root->right) == -1 ||
            abs(height(root->left) - height(root->right)) > 1) {
            return -1;
        }

        return max(height(root->left), height(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root) { return height(root) >= 0; }
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
    cout << s.isBalanced(node1) << endl;
    return 0;
}
