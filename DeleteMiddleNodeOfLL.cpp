#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) return nullptr;
    vector<ListNode*> v;

    while (head) {
        v.push_back(head);
        head = head->next;
    }

    int del = v.size()/2;
    v[del-1]->next = v[del]->next;
    return v[0];
}