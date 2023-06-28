#include <iostream>
#include <queue>
using namespace std;

// 两个队列实现栈
// 时间复杂度：入栈操作 O(N), 其他操作 O(1)
// 空间复杂度：O(N)
class MyStack {
private:
    queue<int> q1; // 栈的操作基于该队列
    queue<int> q2; // 获取栈顶元素时, 用于存储 q1 队尾前面出队元素

public:
    MyStack() {}

    void push(int x) { q1.push(x); }

    int pop() {

        // q1 队尾前面元素出队, 存于 q2
        int size = q1.size();
        while (size > 1) {
            q2.push(q1.front());
            q1.pop();
            --size;
        }

        // 栈顶元素: q1 队尾元素
        int res = q1.front();
        q1.pop();

        // q2 元素再存回 q1
        q1 = q2;

        // 清空 q2
        while (!q2.empty()) {
            q2.pop();
        }
        return res;
    }

    int top() { return q1.back(); }

    bool empty() { return q1.empty(); }
};

int main() {
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */

    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;

    return 0;
}
