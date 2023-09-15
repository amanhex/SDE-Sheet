#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int x, int m){
  int low = 0, high = m - 1;
  int ans = m;
  while (low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] > x){
      ans = mid;
      high = mid - 1;
    }
    else 
      low = mid + 1;
  }
  return ans;
}

int countSmallerEqual(vector<vector<int>>& matrix, int n, int m, int mid){
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += upperBound(matrix[i], mid, m);
  return cnt;
}

int medianOp(vector<vector<int>>& matrix){
  int low = INT_MAX, high = INT_MIN;
  int n = matrix.size(), m = matrix[0].size();
  for (int i = 0; i < n; i++){
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }

  while (low <= high){
    int mid = low + (high - low) / 2;
    int smallerEqual = countSmallerEqual(matrix, n, m, mid);
    if (smallerEqual <= m * n / 2) low = mid + 1;
    else high = mid - 1;
  }
  return low;
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

  int ans = medianOp(matrix);
  cout << ans << endl;
  return 0;
}
