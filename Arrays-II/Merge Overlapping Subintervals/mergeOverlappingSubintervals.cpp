#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 0; i < intervals.size(); i++){
        if (intervals[i][0] <= ans.back()[1])
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}

int main(){
    int size;
    cin >> size;
    vector<vector<int>> intervals(size, vector<int>(2));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 2; j++)
            cin >> intervals[i][j];
    }

    vector<vector<int>> ans = merge(intervals);

    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < 2; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
