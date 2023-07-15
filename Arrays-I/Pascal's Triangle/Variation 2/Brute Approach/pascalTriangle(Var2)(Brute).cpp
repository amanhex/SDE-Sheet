// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Solution: Use the same approach as Var1 and find the whole row of Pascal's Triangle using nCr (num row == num cols --> for Pascal Triangle)

#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangleVar2Brute(int num){
    vector<int> ans;
    int res = 1;
    for (int i = 0; i <= num; i++){
        for (int j = 0; j < i; j++){
            res *= (num - j);
            res /= (j + 1);
        }
        ans.push_back(res);
        res = 1;
    }
    return ans;
}

int main(){
    int num;
    cin >> num;

    vector<int> ans = pascalTriangleVar2Brute(num - 1);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
