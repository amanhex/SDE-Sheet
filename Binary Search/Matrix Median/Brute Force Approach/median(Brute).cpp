#include <bits/stdc++.h>
using namespace std;

int medianBrute(vector<vector<int>>& matrix){
  vector<int> elements;
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++)
      elements.push_back(matrix[i][j]);
  }
  sort(elements.begin(), elements.end());
  return elements[elements.size() / 2];
}

int main(){
  int m, n;
  // m * n should be odd
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j];
  }

  int ans = medianBrute(matrix);
  cout << ans << endl;
  return 0;
}
