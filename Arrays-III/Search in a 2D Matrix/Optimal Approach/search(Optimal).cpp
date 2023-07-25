#include <bits/stdc++.h>
using namespace std;

bool searchOp(vector<vector<int>> matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (matrix[mid / m][mid % m] == target)
            return true;
        else if (matrix[mid / m][mid % m] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main(){
    int rows, cols, target;
    cin >> rows >> cols >> target;
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }
    
    cout << searchOp(matrix, target) << endl;
    return 0;
}
