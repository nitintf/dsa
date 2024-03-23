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
  vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> res;
    if (head == NULL) return res;

    Node* left = head;
    Node* right = head;


    while (right->next != NULL) {
      right = right->next;
    }

    while (left->data < right->data) {
      if (left->data + right->data == k) {
        res.push_back({ left->data, right->data });
        right = right->prev;
        left = left->next;
      }
      else if (left->data + right->data > k) {
        right = right->prev;
      }
      else {
        left = left->next;
      }
    }

    return res;
  }
};

int main() {}
