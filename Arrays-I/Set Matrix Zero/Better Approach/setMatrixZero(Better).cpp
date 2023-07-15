#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZeroBetter(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    // Creating rows and cols arrays to store which row and column need to be converted into 0
    int rows[n] = {0}, cols[m] = {0};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    // Converting rows and columns to zero based on rows and cols array
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            // These 2 loops traverse through the whole row while converting the row into zero if element was 0
            if (rows[i] || cols[j])
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

    vector<vector<int>> ans = setMatrixZeroBetter(matrix);


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
