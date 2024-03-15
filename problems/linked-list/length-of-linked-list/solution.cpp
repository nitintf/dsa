#include<vector>
#include<iostream>
#include<string>
#include<map>

using namespace std;

/**
Notes
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {

public:
  int lengthOfCycle(ListNode* head) {
    map<ListNode*, int> mp;
    ListNode* temp = head;
    int count = 0;

    while (temp) {
      if (mp.find(temp) != mp.end()) {
        int val = mp[temp];
        return count - val;
      }
      mp[temp] = count;
      count++;
      temp = temp->next;
    }

    return 0;
  }
};

int main() {}
