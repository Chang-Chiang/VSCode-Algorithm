#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        // 为空或只有一个节点
        if (head == nullptr || head->next == nullptr) { return head; }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    // 链表相加
    ListNode* addList(ListNode* l1, ListNode* l2) {
        // 先反转两个链表
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* dummyHead = new ListNode(0);
        ListNode* prev = dummyHead;
        int k = 0;  // 记录进位

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 != nullptr && cur2 != nullptr) {

            // 各位和
            int nodeSum = cur1->val + cur2->val + k;

            // result 链表的节点
            ListNode* cur = new ListNode(nodeSum % 10);
            k = nodeSum / 10;

            prev->next = cur;
            prev = cur;

            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while (cur1 != nullptr) {
            int nodeSum = cur1->val + k;
            ListNode* cur = new ListNode(nodeSum % 10);
            k = nodeSum / 10;
            prev->next = cur;
            prev = cur;
            cur1 = cur1->next;
        }
        while (cur2 != nullptr) {
            int nodeSum = cur2->val + k;
            ListNode* cur = new ListNode(nodeSum % 10);
            k = nodeSum / 10;
            prev->next = cur;
            prev = cur;
            cur2 = cur2->next;
        }

        if (k) {
            ListNode* cur = new ListNode(k);
            prev->next = cur;
        }

        return reverseList(dummyHead->next);
    }
};

int main() {
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    ListNode node5(3);
    ListNode node6(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    node5.next = &node6;

    ListNode* res = s.addList(&node1, &node5);

    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
