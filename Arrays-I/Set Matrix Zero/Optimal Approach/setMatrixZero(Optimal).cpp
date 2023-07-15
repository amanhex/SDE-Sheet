#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZeroOptimal(vector<vector<int>> matrix){
    int rows = matrix.size(), cols = matrix[0].size();
    int col0 = 1;

    // for row --> matrix[...][0]
    // for col --> matrix[0][...]

    // Using the 1st row and 1st column to mark if the element should be converted to 0
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;
                if (j == 0)
                    col0 = 0;
                else
                    matrix[0][j] = 0;

            }
        }
    }

    // converting the inner matrix to desired
    for (int i = 1; i < rows; i++){
        for (int j = 1; j < cols; j++){
            if (matrix[0][j] == 0 ||  matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    // converting the 1st column and first row
    if (matrix[0][0] == 0){
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0){
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
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

    vector<vector<int>> ans = setMatrixZeroOptimal(matrix);


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
