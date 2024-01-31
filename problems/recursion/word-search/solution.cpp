#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {

public:
  bool exist(vector<vector<char>>& board, string word) {
    bool found = false;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] != word[0]) {
          continue;
        }
        if (existHelper(board, word, i, j, 1)) {
          return true;
        }
      }
    }
    return false;
  }

  bool existHelper(vector<vector<char>>& board, string word, int i, int j, int k) {
    if (k == word.size()) {
      return true;
    }

    char current = word[k];
    char tmp = board[i][j];
    board[i][j] = '!';
    bool found = false;
    if (i > 0 && board[i - 1][j] == current) {
      found = existHelper(board, word, i - 1, j, k + 1);
    }
    if (!found && i < board.size() - 1 && board[i + 1][j] == current) {
      found = existHelper(board, word, i + 1, j, k + 1);
    }
    if (!found && j > 0 && board[i][j - 1] == current) {
      found = existHelper(board, word, i, j - 1, k + 1);
    }
    if (!found && j < board[0].size() - 1 && board[i][j + 1] == current) {
      found = existHelper(board, word, i, j + 1, k + 1);
    }

    board[i][j] = tmp;
    return found;
  }
};

int main() {
  Solution s;
  vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  cout << s.exist(board, "ABCCED") << endl;
  cout << s.exist(board, "SEE") << endl;
  cout << s.exist(board, "ABCB") << endl;
  return 0;
}
