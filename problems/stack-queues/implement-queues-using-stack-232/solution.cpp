#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class MyQueue {
public:
    stack<int> s1;
    // stack<int> s2;
    MyQueue() {}


    // using two stack
    // void push(int x) {
    //     while(!s1.empty()) {
    //         s2.push(s1.top());
    //         s1.pop();
    //     }

    //     s2.push(x);

    //     while(!s2.empty()) {
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            return;
        }

        int top = s1.top();
        s1.pop();
        push(x);
        s1.push(top);
    }

    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};
int main() {}
