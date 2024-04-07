#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Node
{
public:
  int data;
  Node* next;
  Node()
  {
    this->data = 0;
    next = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node* next)
  {
    this->data = data;
    this->next = next;
  }
};

class Stack
{
  Node* head = nullptr;
  int count;

public:
  Stack()
  {
    count = 0;
  }

  int getSize()
  {
    return count;
  }

  bool isEmpty()
  {
    if (head != nullptr) {
      return false;
    }

    return true;
  }

  void push(int data)
  {
    count++;
    Node* newNode = new Node(data);
    if (head != nullptr) {
      newNode->next = head;
      head = newNode;
    }
    else {
      head = newNode;
    }

  }

  void pop()
  {
    if (head == nullptr) {
      return;
    }

    Node* newHead = head->next;
    Node* temp = head;
    delete(temp);
    head = newHead;
    count--;
  }

  int getTop()
  {
    if (head == NULL) {
      return -1;
    }

    return head->data;
  }
};

int main() {}
