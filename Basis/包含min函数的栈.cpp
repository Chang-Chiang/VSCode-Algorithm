/**
 * @file 包含 min 函数的栈.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief
 * https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/
 * https://leetcode.cn/problems/min-stack/
 * @version 0.1
 * @date 2023-06-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <stack>
using namespace std;

// 包含 min 函数的栈
// 时间复杂度 O(1)
// 空间复杂度 O(N)
class MinStack {
private:
    stack<int> dataStack;
    stack<int> minValStack;

public:
    /** initialize your data structure here. */
    MinStack() { minValStack.push(INT32_MAX); }

    void push(int x) {
        dataStack.push(x);
        // 关键点，每次入栈，存储当前栈最小值的栈同时入栈当前栈的最小值
        minValStack.push(::min(minValStack.top(), x));
    }

    void pop() {
        dataStack.pop();
        minValStack.pop();
    }

    int top() { return dataStack.top(); }

    int min() { return minValStack.top(); }
};

// 包含 min 函数的栈
// 时间复杂度 O(1)
// 空间复杂度 O(1)
class MinStack {
private:
    // 栈节点定义
    struct StackNode {
        int        val_;    // 栈节点存储的值
        int        minVal_; // 栈当前的最小值
        StackNode* next_;   // 栈的下一元素，链表将栈链起来，从栈顶到栈底
    };

    StackNode* stackTopNode; // 栈顶节点

public:
    MinStack() : stackTopNode(nullptr) {}

    void push(int val) {
        StackNode* node = new StackNode;
        node->minVal_ = val;
        node->val_ = val;
        node->next_ = nullptr;

        if (stackTopNode == nullptr) {
            stackTopNode = node;
        }

        else {
            node->minVal_ = min(node->val_, stackTopNode->minVal_);
            node->next_ = stackTopNode;
            stackTopNode = node;
        }
    }

    void pop() { stackTopNode = stackTopNode->next_; }

    int top() { return stackTopNode->val_; }

    int getMin() { return stackTopNode->minVal_; }
};

int main() {
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(x);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->min();
     */

    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    // cout << minStack->min() << endl;
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    // cout << minStack->min() << endl;
    cout << minStack->getMin() << endl;

    return 0;
}
