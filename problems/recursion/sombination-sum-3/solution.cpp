#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  void combinationSum3Helper(vector<vector<int>>& result, vector<int> temp,
    int k, int n, int index) {
    if (k < 0 || n < 0) return;
    if (k == 0 && n == 0) {
      result.push_back(temp);
      return;
    }

    for (int i = index; i < 10; i++) {
      temp.push_back(i);
      combinationSum3Helper(result, temp, k - 1, n - i, i + 1);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> temp;

    combinationSum3Helper(result, temp, k, n, 1);

    return result;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> result = solution.combinationSum3(3, 9);

  for (int i = 0; i < result.size(); i++) {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}
