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
  Node* child;
  Node() : data(0), next(nullptr), child(nullptr) {};
  Node(int x) : data(x), next(nullptr), child(nullptr) {}
  Node(int x, Node* next, Node* child) : data(x), next(next), child(child) {}
};

class Solution {
  Node* convert(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) return NULL;

    Node* head = new Node(arr[0]);

    Node* temp = head;

    for (int i = 1; i < n; i++) {
      Node* newNode = new Node(arr[i]);
      temp->child = newNode;
      temp = temp->child;
    }

    return head;
  }

  Node* merge(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (head1 != NULL && head2 != NULL) {
      if (head1->data > head2->data) {
        temp->child = head2;
        temp = head2;
        head2 = head2->child;
      }
      else {
        temp->child = head1;
        temp = head1;
        head1 = head1->child;
      }

      temp->next = NULL;
    }

    while (head1 != NULL) {
      temp->child = head1;
      temp = head1;
      head1 = head1->child;
    }

    while (head2 != NULL) {
      temp->child = head2;
      temp = head2;
      head2 = head2->child;
    }

    return dummy->child;
  }

public:
  // Node* flattenLinkedList(Node* head)
  // {
  //   // Write your code here
  //   Node* temp = head;

  //   while (!temp) {
  //     Node* nextHead = temp->next;
  //     Node* nextChild = temp->child;

  //     temp->next = nextChild;

  //     while (!nextChild->next) {
  //       nextChild = nextChild->next;
  //     }

  //     nextChild->next = nextHead;
  //     temp = nextHead;
  //   }
  //   return head;
  // }

  // BF >> 
  //  TC:O(NxM) + (NxM)log(NxM) + (NxM)
  //  SC: O(NxM) + O(NxM)
  Node* flattenLinkedListBF(Node* head) {
    vector<int> arr;
    Node* temp = head;

    while (temp != NULL) {
      Node* temp2 = temp;

      while (temp2 != NULL) {
        arr.push_back(temp2->data);
        temp2 = temp2->child;
      }

      temp = temp->next;
    }

    int n = arr.size();

    sort(arr.begin(), arr.end());

    head = convert(arr);

    return head;
  }

  // Optimized using mergeing >>
  //  TC: O(2NM)
  //  SC: O(N) recursive memory
  Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    Node* nextHead = flattenLinkedList(head->next);

    return merge(head, nextHead);
  }
};



int main() {}
