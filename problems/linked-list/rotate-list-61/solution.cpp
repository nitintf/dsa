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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

        ListNode* temp = head;
        int count = 1;

        while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }

        if (k % count == 0) return head;

        k = k % count;

        temp->next = head;
        
        while(count-k)
        {
            temp=temp->next;
            count--;
        }

         ListNode* newHead = temp->next;
        temp->next=NULL;
        return newHead;
    }
}

int main() {}
