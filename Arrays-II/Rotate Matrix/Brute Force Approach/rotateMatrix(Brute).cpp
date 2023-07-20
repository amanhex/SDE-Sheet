// Taking Extra Space to Rotate the matrix

#include <bits/stdc++.h>
using namespace std;

void rotateBrute(vector<vector<int>>& matrix){
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[n - j - 1][index];
        }
        index++;
    }
    matrix = temp;
}

int main(){
    int size;
    cin >> size;
    vector<vector<int>> matrix(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];
    }

    rotateBrute(matrix);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
