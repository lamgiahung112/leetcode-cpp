#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// not given the head node but rather the actual node to be deleted
void deleteNode(ListNode *node) {
    while (true) {
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;

        if (!node->next->next) {
            node->next = nullptr;
            break;
        }
        node = node->next;
    }
}