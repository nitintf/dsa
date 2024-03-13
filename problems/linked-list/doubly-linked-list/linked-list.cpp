#include<iostream>

using namespace std;

template <typename T>
class Node {
public:
  T data;
  Node<T>* next;
  Node<T>* prev;

public:
  Node(T _data) {
    data = _data;
    next = nullptr;
    prev = nullptr;
  }
};

template <typename L>
class DoublyLinkedList {
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
    newNode->prev = temp;
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

  void removeHead() {
    if (!head) {
      return;
    }

    if (head->next == nullptr) {
      head = nullptr;
      return;
    }

    Node<L>* prev = head;

    head = head->next;
    head->prev = nullptr;

    prev->next = nullptr;
    delete prev;
  }

  void removeTail() {
    if (!head) {
      return;
    }

    if (head->next == nullptr) {
      head = nullptr;
      return;
    }

    Node<L>* tail = head;

    while (tail->next != nullptr) {
      tail = tail->next;
    }

    Node<L>* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;

    delete tail;
  }

  void remove(L data) {
    if (!head) {
      return;
    }

    Node<L>* temp = head;

    while (temp) {
      if (temp->data == data)break;
      temp = temp->next;
    }

    Node<L>* prevNode = temp->prev;
    Node<L>* nextNode = temp->next;

    if (!prevNode && !nextNode) {
      delete temp;
    }
    else if (!prevNode) {
      removeHead();
    }
    else if (!nextNode) {
      removeTail();
    }
    else {
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
    }
  }

  void reverse() {
    if (!head || head->next == nullptr) {
      return;
    }

    Node<L>* prev = NULL;
    Node<L>* curr = head;

    while (curr != NULL) {
      prev = curr->prev;
      curr->prev = curr->next;
      curr->next = prev;
      curr = curr->prev;
    }

    head = prev->prev;
  }
};

int main() {
  DoublyLinkedList<int> dl = DoublyLinkedList<int>();

  dl.add(1);
  dl.add(2);
  dl.add(3);
  dl.add(4);
  dl.add(7);
  dl.add(20);
  dl.add(45);

  dl.print();

  dl.removeHead();
  dl.removeTail();

  dl.remove(4);

  dl.print();

  dl.reverse();

  dl.print();

  return 0;
}
