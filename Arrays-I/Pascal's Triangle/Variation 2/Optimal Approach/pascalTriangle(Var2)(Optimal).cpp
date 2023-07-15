// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Solution:

#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangleVar2Op(int num){
    vector<int> ans;

    return ans;
}

int main(){
    int num;
    cin >> num;

    vector<int> ans = pascalTriangleVar2Op(num - 1);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
