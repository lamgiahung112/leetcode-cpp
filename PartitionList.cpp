#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode();
    ListNode* high = new ListNode();
    ListNode* smallhead = small, highhead = high;

    while (head) {
        if (head->val >= x) {
            high->next = head;
            high = high->next;
        } else {
            small->next = head;
            small = small->next;
        }
        head = head->next;
    }

    high->next = nullptr;
    small->next = highhead.next;
    return smallhead->next;
}