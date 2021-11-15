#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode*> nodes;

    while (head) {
        nodes.push_back(head);
        head = head->next;
    }

    left--;
    right--;

    while (left < right) {
        ListNode* tmp = nodes[left];
        nodes[left] = nodes[right];
        nodes[right] = tmp;
        left++;
        right--;
    }

    for (int i = 1; i < nodes.size(); i++) {
        nodes[i-1]->next = nodes[i];
        nodes[i]->next = nullptr;
    }
    return nodes[0];
}

int main() {
    ListNode* n1 = new ListNode(3, new ListNode(5));
    reverseBetween(n1, 1, 2);
}