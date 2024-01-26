#include<vector>
#include<iostream>
#include<string>

using namespace std;

// [1, 2, 3]

void subsetsHelper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
  result.push_back(current);
  for (int i = index; i < nums.size(); i++) {
    current.push_back(nums[i]);
    subsetsHelper(nums, i + 1, current, result);
    current.pop_back();
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> current;
  subsetsHelper(nums, 0, current, result);
  return result;
}

int main() {
  vector<int> nums = { 1, 2, 3, 2 };
  vector<vector<int>> result = subsets(nums);
  for (int i = 0; i < result.size(); i++) {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}
