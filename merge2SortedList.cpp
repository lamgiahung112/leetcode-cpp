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

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *temp = new ListNode();
        ListNode *t = temp;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                t->next = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val) {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        while (l1) {
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        while(l2) {
            t->next = l2;
            l2 = l2->next;
            t = t->next;
        }
        return temp->next;
}

int main() {

}