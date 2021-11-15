#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {   
    vector<int> nodes;
    ListNode* list = new ListNode();
    ListNode* ans = list;

    while (head) {
        nodes.push_back(head->val);
        head = head->next;
    }

    for (int i = 0; i < k % nodes.size(); i++) {
        int tmp = nodes[nodes.size() - 1];
        nodes.pop_back();
        nodes.insert(begin(nodes), tmp);
    }

    for (auto n : nodes) {
        ListNode* tmp = new ListNode(n);
        list->next = tmp;
        list = list->next;
    }
    return ans->next;
}

int main() {

}