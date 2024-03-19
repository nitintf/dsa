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
public:
  ListNode* sortListBruteForce(ListNode* head) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    ListNode* temp = head;

    while (temp != NULL) {
      if (temp->val == 0) {
        cnt0++;
      }
      else if (temp->val == 1) {
        cnt1++;
      }
      else {
        cnt2++;
      }
      temp = temp->next;
    }

    temp = head;

    while (temp != NULL) {
      if (cnt0 > 0) {
        temp->val = 0;
        cnt0--;
      }
      else if (cnt1 > 0) {
        temp->val = 1;
        cnt1--;
      }
      else if (cnt2 > 0) {
        temp->val = 2;
        cnt2--;
      }

      temp = temp->next;
    }

    return head;
  }

  ListNode* sortList(ListNode* head) {

  }
};

int main() {}
