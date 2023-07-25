#include <bits/stdc++.h>
using namespace std;

bool searchBrute(vector<vector<int>> matrix, int target){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            if (matrix[i][j] == target)
                return true;
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
    
    cout << searchBrute(matrix, target) << endl;
    return 0;
}
