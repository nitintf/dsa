#include<iostream>

using namespace std;

template <typename T>
class Node {
public:
  T data;
  Node<T>* next;
public:
  Node(T _data, Node<T>* _next) {
    data = _data;
    next = _next;
  }

public:
  Node(T _data) {
    data = _data;
    next = nullptr;
  }
};

template <typename L>
class LinkedList {
public:
  Node<L>* head;
public:
  void add(L data) {
    Node<L>* newNode = new Node<L>(data);

    if (!head) {
      head = newNode;
      return;
    }

    Node<L>* temp = head;

    while (temp->next) {
      temp = temp->next;
    }

    temp->next = newNode;
  }

  void print() {
    if (!head) {
      cout << "Nothing to print." << endl;
    }

    Node<L>* temp = head;

    while (temp) {
      if (temp->next) {
        cout << temp->data << " -> ";
      }
      else {
        cout << temp->data << ";" << endl;
      }
      temp = temp->next;
    }
  }

  int size() {
    int _size = 0;
    if (!head) {
      return 0;
    }

    Node<L>* temp = head;

    while (temp) {
      _size++;
      temp = temp->next;
    }

    return _size;
  }

  bool search(L data) {
    if (!head) {
      return false;
    }

    Node<L>* temp = head;

    while (temp) {
      if (temp->data == data) {
        return true;
      }
      temp = temp->next;
    }

    return false;
  }
};

int main() {
  LinkedList<int> ll = LinkedList<int>();

  ll.add(1);
  ll.add(2);
  ll.add(3);
  ll.add(4);

  ll.print();

  cout << ll.search(3) << endl;
  cout << ll.search(6) << endl;

  // cout << ll.size() << endl;

  return 0;
}
