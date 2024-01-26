#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  void subsetHelper(vector<vector<int>>& result, vector<int>& temp, int index, vector<int>& nums) {
    result.push_back(temp);

    for (int i = index; i < nums.size(); i++) {
      // Skip duplicates
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }
      temp.push_back(nums[i]);
      subsetHelper(result, temp, i + 1, nums);
      temp.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
    sort(nums.begin(), nums.end());

    subsetHelper(result, temp, 0, nums);
    return result;
  }
};

int main() {}
