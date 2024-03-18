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
  ListNode* findMiddle(ListNode* head) {
    ListNode* fast = head->next;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;

  }

  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      }
      else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;

    return dummy.next;
  }


public:
  ListNode* sortListBruteForce(ListNode* head) {
    vector<int> arr;

    ListNode* temp = head;

    while (temp != NULL) {
      arr.push_back(temp->val);
      temp = temp->next;
    }

    int n = arr.size();

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;

    while (temp != NULL) {
      temp->val = arr[i];
      i++;
      temp = temp->next;
    }

    return head;
  }

  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode* middle = findMiddle(head);
    ListNode* leftHead = head;
    ListNode* rightHead = middle->next;
    middle->next = NULL;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge(leftHead, rightHead);
  }

};

int main() {}
