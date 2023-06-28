/**
 * @file 树的子结构.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
 * @version 0.1
 * @date 2023-06-28
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

// 树的子结构, A 节点数 N, B 结点数 M
// 时间复杂度 O(NM)
// 空间复杂度 O(M)
class Solution {
private:
    // 判断 B 是不是 A 的子树
    bool isSubTree(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr || A->val != B->val) {
            return false;
        }
        return isSubTree(A->left, B->left) && isSubTree(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        return isSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
