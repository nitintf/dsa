#include<vector>
#include<iostream>
#include<string>

using namespace std;

void subsetSumHelper(vector<int>& nums, vector<int>& result, int index, int currentSum) {
  result.push_back(currentSum);

  for (int i = index; i < nums.size(); ++i) {
    subsetSumHelper(nums, result, i + 1, currentSum + nums[i]);
  }
}

vector<int> subsetSum(vector<int>& nums) {
  vector<int> result;
  subsetSumHelper(nums, result, 0, 0);
  sort(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> nums = { 1, 2, 3 };
  vector<int> result = subsetSum(nums);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}
