#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/


class Node {
public:
  int data;
  Node* next;
  Node* prev;
  Node() {
    this->data = 0;
    this->next = NULL;
    this->prev = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;

  }
  Node(int data, Node* next, Node* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
};

class Solution {
public:
  Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;

    while (temp != NULL) {
      if (temp->data == k) {
        if (temp == head) {
          head = temp->next;
        }

        Node* prev = temp->prev;
        Node* next = temp->next;

        if (prev != NULL) {
          prev->next = next;
        }

        if (next != NULL) {
          next->prev = prev;
        }

        free(temp);

        temp = next;
      }
      else {
        temp = temp->next;
      }
    }

    return head;
  }
};

int main() {}
