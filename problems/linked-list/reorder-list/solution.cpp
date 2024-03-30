#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

/**
Notes
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode* reverse(ListNode* head) {
    if (!head) return NULL;
    ListNode* temp = head;
    ListNode* prev = NULL;

    while (temp != NULL) {
      ListNode* next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }

    return prev;
  }

  void merge(ListNode* list1, ListNode* list2) {
    while (list2) {
      ListNode* nextNode = list1->next;
      list1->next = list2;
      list1 = list2;
      list2 = nextNode;
    }
  }

public:
  void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return;

      ListNode* slow = head;
      ListNode* fast = head;
      ListNode* prev = slow;

      while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }

      prev->next = NULL;
      ListNode* list1 = head;
      ListNode* list2 = reverse(slow);
      merge(list1, list2);
    }
  }
};

int main() {}
