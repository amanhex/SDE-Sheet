#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& maze, vector<string>& res, string& current, int n, int row, int col){
  if (row == n - 1 && col == n - 1){
    res.push_back(current);
    return;
  }

  // Check for the edge case if the 1st element of the maze is 0 or not
  if (maze[row][col] == 0)
    return;

  //Mark current cell as visited
  maze[row][col] = 0;

  // Check paths in a lexical order --> D L R U 

  // Checking if Down path is possible
  if (row + 1 < n){
    if (maze[row + 1][col] == 1){
      current.push_back('D');
      solve(maze, res, current, n, row + 1, col);
      current.pop_back();
    }
  }

  // Checking if Left path is possible
  if (col - 1 >= 0){
    if (maze[row][col - 1] == 1){
      current.push_back('L');
      solve(maze, res, current, n, row, col - 1);
      current.pop_back();
    }
  }

  //Checking if Right path is possible
  if (col + 1 < n){
    if (maze[row][col + 1] == 1){
      current.push_back('R');
      solve(maze, res, current, n, row, col + 1);
      current.pop_back();
    }
  }

  // Checking if Up path is possible
  if (row - 1 >= 0){
    if (maze[row - 1][col] == 1){
      current.push_back('U');
      solve(maze, res, current, n, row - 1, col);
      current.pop_back();
    }
  }

  maze[row][col] = 1;
  return;
}

vector<string> findPath(vector<vector<int>>& maze, int n){
  vector<string> res;
  string current = "";
  solve(maze, res, current, n, 0, 0);
  return res;
}

int main(){
  int n = 4;
  vector<vector<int>> maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
  };

  vector<string> res = findPath(maze, n);
  if (res.size() == 0)
    cout << -1;
  else{
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
