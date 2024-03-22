#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes

Brute force:
  - reverse the list
  - take a carry as 1
  - traverse through list and add using carry
  - reverse the list again
  - in last if we still have carry make it as head node of list

*/

class Node {
public:
  int data;
  Node* next;
  Node() {
    this->data = 0;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;

  }
  Node(int data, Node* next) {
    this->data = data;
    this->next = next;
  }
};

class Solution {
  int add(Node* node, int num) {
    int val = node->data;

    int sum = val + num;

    int last_digit = sum % 10;

    int first_digit = sum / 10;

    node->data = last_digit;
    return first_digit;
  }


  int addOneRecursive(Node* node) {
    if (node && node->next == NULL) {
      return add(node, 1);
    }

    int carry = addOneRecursive(node->next);
    return add(node, carry);
  }

public:
  Node* addOne(Node* head) {
    int carry = addOneRecursive(head);

    if (carry > 0) {
      Node* new_node = new Node(carry);
      new_node->next = head;
      head = new_node;
    }

    return head;
  }
};

int main() {}
