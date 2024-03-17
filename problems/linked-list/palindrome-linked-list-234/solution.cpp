#include<vector>
#include<iostream>
#include<string>
#include<stack>

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

  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
  }

public:
  // TC - O(2N)
  // SC - O(N)
  bool isPalindromeBruteForce(ListNode* head) {
    if (head == NULL) {
      return false;
    }

    stack<int> st;

    ListNode* temp = head;

    while (temp != NULL) {
      st.push(temp->val);
      temp = temp->next;
    }

    temp = head;

    while (temp != NULL) {
      int stVal = st.top();
      if (stVal != temp->val) {
        return false;
      }
      st.pop();
      temp = temp->next;
    }

    return true;
  }

  bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return true;
    }

    ListNode* midd = middleNode(head);
    ListNode* newHead = reverse(midd->next);

    ListNode* first = head;
    ListNode* second = newHead;
    while (second != NULL) {
      if (first->val != second->val) {
        return false;
      }
      first = first->next;
      second = second->next;
    }

    return true;
  }
};

int main() {}
