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
  ListNode* collisionPoint(ListNode* l1, ListNode* l2, int diff) {
    // N2 - N1
    while (diff) {
      diff--;
      l2 = l2->next;
    }

    // N1
    while (l1 != l2) {
      l1 = l1->next;
      l2 = l2->next;
    }

    return l1;
  }

public:
  ListNode* getIntersectionNodeBF(ListNode* headA, ListNode* headB) {
    int n = 0, m = 0;
    ListNode* temp = headA;

    // N1
    while (temp != NULL) {
      n++;
      temp = temp->next;
    }

    temp = headB;

    // N2
    while (temp != NULL) {
      m++;
      temp = temp->next;
    }

    cout << n - m << endl;

    if (n > m) {
      return collisionPoint(headB, headA, n - m);
    }
    else {
      return collisionPoint(headA, headB, m - n);
    }
  }

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;

    while (l1 != l2) {
      l1 = l1->next;
      l2 = l2->next;

      if (l1 == l2) {
        return l1;
      }

      if (l1 == NULL) l1 = headB;
      if (l2 == NULL) l2 = headA;
    }

    return l1;
  }
};

int main() {}
