#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  void combinationSumHelperWithMemoization(vector<vector<int>>& result, vector<int>& c, int target, int index, vector<int>& current, unordered_map<string, bool>& memo) {
    if (index == c.size()) {
      if (target == 0) {
        result.push_back(current);
      }
      return;
    }


    string key = to_string(index) + ":" + to_string(target);

    if (memo.find(key) != memo.end()) {
      if (!memo[key]) {
        return;
      }
    }

    if (c[index] <= target) {
      current.push_back(c[index]);
      combinationSumHelperWithMemoization(result, c, target - c[index], index, current, memo);
      current.pop_back();
    }

    combinationSumHelperWithMemoization(result, c, target, index + 1, current, memo);

    memo[key] = result.size() > 0;
  }

  vector<vector<int>> combinationSumWithMemoization(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    unordered_map<string, bool> memo;

    combinationSumHelperWithMemoization(result, candidates, target, 0, current, memo);

    return  result;
  }

  void combinationSumHelper(vector<vector<int>>& result, vector<int>& c, int target, int index, vector<int>& current) {
    if (index == c.size()) {
      if (target == 0) {
        result.push_back(current);
      }
      return;
    }

    if (c[index] <= target) {
      current.push_back(c[index]);
      combinationSumHelper(result, c, target - c[index], index, current);
      current.pop_back();
    }

    combinationSumHelper(result, c, target, index + 1, current);
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;

    combinationSumHelper(result, candidates, target, 0, current);

    return  result;
  }
};

int main() {
  Solution s;
  vector<int> c = { 2, 3, 6, 7 };
  int target = 7;
  vector<vector<int>> memoizedResult = s.combinationSumWithMemoization(c, target);

  for (int i = 0; i < memoizedResult.size(); i++) {
    cout << "[";
    for (int j = 0; j < memoizedResult[i].size(); j++) {
      cout << memoizedResult[i][j] << ", ";
    }
    cout << "]" << endl;
  }

  vector<vector<int>> result = s.combinationSum(c, target);

  for (int i = 0; i < result.size(); i++) {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << "]" << endl;
  }

}
