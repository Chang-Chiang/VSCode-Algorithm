#include <iostream>
#include <stack>
using namespace std;

// 两个栈实现队列
// 时间复杂度：O(1)
// 空间复杂度：O(N)
class CQueue {
private:
    stack<int> st_in;
    stack<int> st_out;

public:
    CQueue() {}

    void appendTail(int value) { st_in.push(value); }

    int deleteHead() {

        // 用于出队的栈非空，可直接出队
        if (!st_out.empty()) {
            int res = st_out.top();
            st_out.pop();
            return res;
        }

        // 用于出队的栈空、用于入队的栈空
        // 即队列无元素，无法出队
        if (st_in.empty()) {
            return -1;
        }

        // 用于出队的栈空，则需将用于进队的栈元素转移到用于出队的栈
        while (!st_in.empty()) {
            int& value = st_in.top();
            st_out.push(value);
            st_in.pop();
        }

        int head = st_out.top();
        st_out.pop();
        return head;
    }
};

int main() {
    /**
     * Your CQueue object will be instantiated and called as such:
     * CQueue* obj = new CQueue();
     * obj->appendTail(value);
     * int param_2 = obj->deleteHead();
     */

    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    // que.appendTail(3);

    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;
    cout << obj->deleteHead() << endl;

    delete obj;

    return 0;
}
