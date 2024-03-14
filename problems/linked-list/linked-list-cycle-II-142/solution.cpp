#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  ListNode* hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
      return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return fast;
      }
    }

    return NULL;
  }

public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* fast = hasCycle(head);

    if (!fast) {
      return NULL;
    }

    ListNode* slow = head;

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};

int main() {}
