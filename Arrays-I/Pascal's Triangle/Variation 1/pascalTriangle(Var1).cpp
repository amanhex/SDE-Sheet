// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// Solution: nCr to find the element

#include <bits/stdc++.h>
using namespace std;

int pascalTriangleVar1(int row, int col){
    long long res = 1;
    for (int i = 0; i < col; i++){
        res *= (row - i);
        res /= (i + 1);
    }
    return res;
}

int main(){
    int row, col;
    cin >> row >> col;
    int ans = pascalTriangleVar1(row - 1, col - 1);
    cout << ans << endl;
    return 0;
}
