#include<vector>
#include<iostream>
#include<string>

using namespace std;

/**
Notes
*/

class Node {
public:
  string data;
  Node* next;
  Node* prev;

public:
  Node(string _data) {
    data = _data;
    next = nullptr;
    prev = nullptr;
  }
};

class BrowserHistory {
  Node* current;

public:
  void browser(string& homepage) {
    current = new Node(homepage);
  }

  void visit(string& path) {
    Node* newPage = new Node(path);
    current->next = newPage;
    newPage->prev = current;
    current = newPage;
  }

  string back(int steps) {
    while (steps > 0) {
      if (current->prev) {
        current = current->prev;
        steps--;
      }
      else {
        break;
      }
    }

    return current->data;
  }

  string forward(int steps) {
    while (steps > 0) {
      if (current->next) {
        current = current->next;
        steps--;
      }
      else {
        break;
      }
    }

    return current->data;
  }
};

int main() {}
