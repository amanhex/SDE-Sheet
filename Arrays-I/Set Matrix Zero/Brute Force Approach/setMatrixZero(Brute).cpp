#include <bits/stdc++.h>
using namespace std;

void setZero(int i, int j, int rows, int cols, vector<vector<int>>& matrix){
    // Convert the row to -1 except the ones which are already zero
    for (int a = 0; a < cols; a++){
        if (matrix[i][a] != 0)
            matrix[i][a] = -1;
    }

    // Convert the col to -1 except the ones which are already zero
    for (int b = 0; b < rows; b++){
        if (matrix[b][j] != 0)
            matrix[b][j] = -1;
    }
}


// Brute Force Method
vector<vector<int>> setMatrixZero(vector<vector<int>> matrix){
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == 0)
                setZero(i, j, rows, cols, matrix);
        }
    }

    // Changing the -1's to 0
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }

    return matrix;
}


int main(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> matrix;
    for (int i = 0; i < rows; i++){
        vector<int> temp;
        for (int j = 0; j < cols; j++){
            int element;
            cin >> element;
            temp.push_back(element);
        }
        matrix.push_back(temp);
    }

    cout << endl;

    vector<vector<int>> ans = setMatrixZero(matrix);


    // Displaying the original matrix
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    // Displaying the ans matrix
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
