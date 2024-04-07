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
  Node() : data(0), next(nullptr) {}
  Node(int x) : data(x), next(nullptr) {}
  Node(int x, Node* next) : data(x), next(next) {}
};

struct Queue {
  Node* front;
  Node* rear;
  void push(int);
  int pop();

  Queue() {
    front = rear = NULL;
  }
};


void Queue::push(int x) {

  Node* newNode = new Node(x);

  if (front == nullptr && rear == nullptr) {
    front = newNode;
    rear = newNode;
  }

  Node* prevRear = rear;
  prevRear->next = newNode;
  rear = newNode;
}

int Queue::pop() {
  if (front == nullptr) {
    return -1;
  }
  int data = front->data;

  Node* temp = front;
  if (front == rear) {
    front = nullptr;
    rear = nullptr;
  }
  else {
    Node* newHead = front->next;
    front = newHead;
  }

  delete(temp);
  return data;
}

int main() {}
