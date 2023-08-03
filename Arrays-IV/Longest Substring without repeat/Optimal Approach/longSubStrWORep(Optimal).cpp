#include <bits/stdc++.h>
using namespace std;

int uniqueSubstringsOp(string input){
    if (input.size() == 0 || input.size() == 1)
        return input.size();
    int maxLength = INT_MIN, left = 0, right = 0;
    unordered_map<char, int> map;
    while (right < input.size()){
        if (map.count(input[right]))
            left = max(map[input[right]] + 1, left);
        map[input[right]] = right;
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main(){
    string input;
    cin >> input;
    int ans = uniqueSubstringsOp(input);
    cout << ans << endl;
    return 0;
}
