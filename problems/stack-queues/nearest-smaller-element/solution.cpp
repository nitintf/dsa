#include<vector>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

/**
Notes
*/

class Solution {
public:
  vector<int> prevSmaller(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk;

    for (int i = 0; i < nums.size(); i++) {

      int cur = nums[i];

      while (!stk.empty() and stk.top() >= cur) {
        stk.pop();
      }

      if (!stk.empty()) {
        res[i] = stk.top();
      }

      stk.push(cur);
    }
    return res;
  }
};

int main() {}
