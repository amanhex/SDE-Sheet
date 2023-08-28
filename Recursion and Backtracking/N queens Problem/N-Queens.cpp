#include <bits/stdc++.h>
using namespace std;

bool fill(vector<string>& board, int row, int col, int n){
  int dupRow = row, dupCol = col;
  // Checking for left up diagonal
  while (dupRow >= 0 && dupCol >=0){
    if (board[dupRow][dupCol] == 'Q') return false;
    dupRow--, dupCol--;
  }

  // Checking for left row
  dupRow = row, dupCol = col;
  while (dupCol >= 0){
    if (board[dupRow][dupCol] == 'Q') return false;
    dupCol--;
  }

  // Checking for left down diagonal
  dupRow = row, dupCol = col;
  while (dupRow < n && dupCol >= 0){
    if (board[dupRow][dupCol] == 'Q') return false;
    dupRow++, dupCol--;
  }
  return true;
}

void solve(vector<vector<string>>& ans, vector<string>& board, int n, int col){
  if (col == n){
    ans.push_back(board);
    return;
  }
  for (int row = 0; row < n; row++){
    if (fill(board, row, col, n)){
      board[row][col] = 'Q';
      solve(ans, board, n, col + 1);
      board[row][col] = '.';
    }
  }
  return;
}

vector<vector<string>> nQueen(int n){
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  solve(ans, board, n, 0);
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<vector<string>> res = nQueen(n);

  for (auto i : res){
    for (auto j : i)
      cout << j << endl;
  }
  return 0;
}
