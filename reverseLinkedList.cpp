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

//iterative solution
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    vector<ListNode*> nodes;
    ListNode *start = head;
    
    while (head) {
        nodes.push_back(head);
        head = head->next;
    }

    int left = 0;
    int right = nodes.size() - 1;

    while (left < right) {
        int temp = nodes[left]->val;
        nodes[left]->val = nodes[right]->val;
        nodes[right]->val = temp;
        left++;
        right--;
    }
    return start;
}