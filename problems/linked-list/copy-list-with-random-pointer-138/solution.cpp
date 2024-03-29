#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

/**
Notes
*/

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  // Brute Force (using hash map) >>
  //  TC: O(2N)
  //  SC: O(N) + O(N)
  Node* copyRandomListBF(Node* head) {
    Node* temp = head;

    unordered_map<Node*, Node*> nodeMap;

    while (temp != NULL) { // O(N)
      Node* newNode = new Node(temp->val);
      nodeMap[temp] = newNode;

      temp = temp->next;
    }

    temp = head;

    while (temp != NULL) { // O(N)
      Node* copyNode = nodeMap[temp];

      copyNode->next = nodeMap[temp->next];
      copyNode->random = nodeMap[temp->random];
      temp = temp->next;
    }

    return nodeMap[head];
  }

  Node* copyRandomList(Node* head) {
    Node* temp = head;

    // first, create a list with copy of each node next to its orignal node
    while (temp != NULL) {
      Node* next = temp->next;
      Node* newNode = new Node(temp->val);
      temp->next = newNode;
      newNode->next = next;

      temp = next;
    }

    temp = head;

    // using the orignal node point the random of copy node to its original node random next
    while (temp != NULL) {
      Node* copiedNode = temp->next;

      if (temp->random) {
        copiedNode->random = temp->random->next;
      }
      else {
        copiedNode->random = nullptr;
      }

      if (temp->next) {
        temp = temp->next->next;
      }
      else {
        temp = NULL;
      }
    }

    // Create a new list
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    temp = head;

    while (temp != NULL) {
      res->next = temp->next;
      temp->next = temp->next->next;

      res = res->next;
      temp = temp->next;
    }

    return dummyNode->next;
  }


  // Recurssion

  Node* helper(unordered_map<Node*, Node*>& mp, Node* head) {
    if (!head)   return 0;
    Node* newhead = new Node(head->val);
    mp[head] = newhead;
    newhead->next = helper(mp, head->next);

    if (head->random) {
      newhead->random = mp[head->random];
    }
    return newhead;
  }

  Node* copyRandomListRecursion(Node* head) {
    unordered_map< Node*, Node*> mp;
    return helper(mp, head);
  }


};

int main() {}
