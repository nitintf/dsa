#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

/**
Notes
*/

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    stack<int> st;

    unordered_map<int, int> mp;

    for (int i = m - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= nums2[i]) {
        st.pop();
      }

      if (!st.empty()) {
        mp[nums2[i]] = st.top();
      }
      else {
        mp[nums2[i]] = -1;
      }
      st.push(nums2[i]);
    }

    for (int i = 0; i < n; i++) {
      int num = nums1[i];

      nums1[i] = mp[num];
    }

    return nums1;
  }
};

int main() {}
