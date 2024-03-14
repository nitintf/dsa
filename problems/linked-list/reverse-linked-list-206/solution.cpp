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
  ListNode* reverseListIterative(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp) {
      ListNode* front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }

    return prev;
  }

  ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* newHead = reverseListRecursive(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
  }

};

int main() {}
