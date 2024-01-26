#include<vector>
#include<iostream>
#include<string>
#include<set>

using namespace std;

class Solution {
public:
  void combinationSumHelper(vector<vector<int>>& result, vector<int>& c, int target, int index, vector<int>& current) {
    if (target == 0) {
      result.push_back(current);
      return;
    }

    for (int i = index; i < c.size(); i++) {
      if (i > index && c[i] == c[i - 1]) continue;
      if (c[i] > target) break;

      current.push_back(c[i]);
      combinationSumHelper(result, c, target - c[i], i + 1, current);
      current.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;

    sort(candidates.begin(), candidates.end());

    combinationSumHelper(result, candidates, target, 0, current);

    return  result;
  }
};

int main() {
  Solution s;
  vector<int> c = { 2,5,2,1,2 };
  int target = 5;
  vector<vector<int>> result = s.combinationSum2(c, target);

  for (auto& v : result) {
    for (auto& i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
