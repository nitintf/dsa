#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
  void findNextPath(vector<vector<int>>& m, int n, int i, int j, string& path, vector<string>& res) {
    if (i == n - 1 && j == n - 1) {
      res.push_back(path);
      return;
    }

    m[i][j] = 0;

    if (i < n - 1 && m[i + 1][j] == 1) {
      path.push_back('D');
      findNextPath(m, n, i + 1, j, path, res);
      path.pop_back();
    }

    if (j < n - 1 && m[i][j + 1] == 1) {
      path.push_back('R');
      findNextPath(m, n, i, j + 1, path, res);
      path.pop_back();
    }

    if (i > 0 && m[i - 1][j] == 1) {
      path.push_back('U');
      findNextPath(m, n, i - 1, j, path, res);
      path.pop_back();
    }

    if (j > 0 && m[i][j - 1] == 1) {
      path.push_back('L');
      findNextPath(m, n, i, j - 1, path, res);
      path.pop_back();
    }

    m[i][j] = 1;
  }

public:
  vector<string> findPath(vector<vector<int>>& m, int n) {
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) {
      return {};
    }

    vector<string> res;
    string path;
    findNextPath(m, n, 0, 0, path, res);
    return res;
  }
};

int main() {
  vector<vector<int>> m = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
  };

  Solution s;
  vector<string> res = s.findPath(m, 4);
  for (auto& path : res) {
    cout << path << endl;
  }

  return 0;
}
