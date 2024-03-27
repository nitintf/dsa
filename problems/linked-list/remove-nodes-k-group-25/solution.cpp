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
    ListNode* findKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prevLastNode = NULL;

        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);
            // handle when kthNode is null

            if (kthNode == NULL) {
                if (prevLastNode) {
                    prevLastNode->next = temp;
                    break;
                }
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if (temp == head) {
                head = kthNode;
            } else {
                prevLastNode->next = kthNode;
            }

            prevLastNode = temp;
            temp = nextNode;
        }

        return head;
    }
};

int main() {}
