// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// Solution: Use the variation 2 solution trick to calculate each row

#include <bits/stdc++.h>
using namespace std;

// Solution using Variation 2 trick
vector<int> generateRow(int row){
    vector<int> triangleRow;
    int res = 1;
    triangleRow.push_back(res);
    for (int col = 1; col <= row; col++){
        res = res * (row - col + 1) / col;
        triangleRow.push_back(res);
    }
    return triangleRow;
}

vector<vector<int>> pascalTriangleVar3(int row){
    vector<vector<int>> ans;
    for (int i = 0; i < row; i++)
        ans.push_back(generateRow(i));
    return ans;
}

//Another method
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        vector<int> rows(i + 1, 1);
        for (int j = 1; j < i; j++)
            rows[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        ans.push_back(rows);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans = pascalTriangleVar3(n);

    // Displaying the ans vector
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
