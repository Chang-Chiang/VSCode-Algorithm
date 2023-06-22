// 先计算环形链表结点数，分配各分段链表的结点数
// 遍历分段，对应分段点 next 指针域置 nullptr
#include <iostream>
#include <vector>
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
    vector<ListNode*> trisectionCLink(ListNode* head) {

        if (head == nullptr) { return {}; }

        int cnt = 1;
        ListNode* tmp = head;
        while (tmp->next != head) {
            ++cnt;
            tmp = tmp->next;
        }

        // 至少有三个节点
        if (cnt < 3) { return vector<ListNode*>{head}; }

        int size1, size2, size3;
        if (cnt % 3 == 0) {
            size1 = cnt / 3;
            size2 = cnt / 3;
            size3 = cnt / 3;
        }
        else if(cnt % 3 == 1) {
            size1 = cnt / 3;
            size2 = cnt / 3;
            size3 = cnt / 3 + 1;
        }
        else {
            size1 = cnt / 3;
            size2 = cnt / 3 + 1;
            size3 = cnt / 3 + 1;
        }

        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* head3 = new ListNode(0);

        head1->next = head;
        ListNode* cur1 = head1;
        while (size1 > 0) {
            cur1 = cur1->next;
            --size1;
        }

        head2->next = cur1->next;
        ListNode* cur2 = head2;
        while (size2 > 0) {
            cur2 = cur2->next;
            --size2;
        }

        head3->next = cur2->next;
        ListNode* cur3 = head3;
        while (size3 > 0) {
            cur3 = cur3->next;
            --size3;
        }

        cur1->next = nullptr;  // 取出 head1 链表
        cur2->next = nullptr;  // 取出 head2 链表
        cur3->next = nullptr;  // 取出 head3 链表

        ListNode* l1 = head1->next;
        ListNode* l2 = head2->next;
        ListNode* l3 = head3->next;
        delete head1;
        delete head2;
        delete head3;
        return vector<ListNode*>{l1, l2, l3};
    }
};

int main() {
    Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode (4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode (6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node1;

    ListNode* head = node1;
    vector<ListNode*> res = s.trisectionCLink(head);

    ListNode* head1 = res[0];
    while (head1 != nullptr) {
        cout << head1->val << "->";
        head1 = head1->next;
    }
    cout << "nullptr" << endl;

    ListNode* head2 = res[1];
    while (head2 != nullptr) {
        cout << head2->val << "->";
        head2 = head2->next;
    }
    cout << "nullptr" << endl;

    ListNode* head3 = res[2];
    while (head3 != nullptr) {
        cout << head3->val << "->";
        head3 = head3->next;
    }
    cout << "nullptr" << endl;

    delete node1, node2, node3, node4, node5, node6;
    return 0;

}
