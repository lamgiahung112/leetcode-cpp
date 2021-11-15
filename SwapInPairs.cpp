#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* ans = head;

    while (head && head->next) {
        int tmp = head->val;
        head->val = head->next->val;
        head->next->val = tmp;

        head = head->next->next;
    }
    return ans;
}