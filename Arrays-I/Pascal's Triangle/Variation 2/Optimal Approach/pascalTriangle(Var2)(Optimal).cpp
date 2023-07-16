// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Solution: observing the pattern to find some formulaa

#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangleVar2Op(int num){
    vector<int> ans;
    int res = 1;
    ans.push_back(res);
    for (int i = 1; i < num; i++){
        res = res * (num - i) / i;
        ans.push_back(res);
    }
    return ans;
}

int main(){
    int num;
    cin >> num;

    vector<int> ans = pascalTriangleVar2Op(num);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
