// In-place Rotation
#include <bits/stdc++.h>
using namespace std;

void rotateOptimal(vector<vector<int>>& matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(){
    int size;
    cin >> size;
    vector<vector<int>> matrix(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cin >> matrix[i][j];
    }

    rotateOptimal(matrix);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
