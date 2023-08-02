#include <bits/stdc++.h>
using namespace std;

// T.C: O(m + n)
bool searchBetter2(vector<vector<int>> matrix, int target){
    int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = m - 1;
    while (left < n && right >= 0){
        if (matrix[left][right] == target)
            return true;
        else if (matrix[left][right] > target)
            right--;
        else
            left++;
    }
    return false;
}

// T.C: O(n * log(m))
bool searchBetter1(vector<vector<int>> matrix, int target){
    for (int i = 0; i< matrix.size(); i++){
        int low = 0, high = matrix[0].size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] == target)
                return true;
            else if (matrix[i][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
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
    
    cout << searchBetter1(matrix, target) << endl;
    cout << searchBetter2(matrix, target) << endl;
    return 0;
}
