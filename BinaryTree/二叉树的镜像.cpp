/**
 * @file 二叉树的镜像.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
 * https://leetcode-cn.com/problems/invert-binary-tree/
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

//二叉树的镜像
// 时间复杂度 O(N) 遍历二叉树中的每一个节点
// 空间复杂度 O(N) 递归栈的深度. 平均 O(logN)；在最坏情况下，树形成链状，空间复杂度为 O(N)
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};

int main() {
    // 输入：root = [4,2,7,1,3,6,9]
    // 输出：[4,7,2,9,6,3,1]
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(9);

    Solution s;
}
