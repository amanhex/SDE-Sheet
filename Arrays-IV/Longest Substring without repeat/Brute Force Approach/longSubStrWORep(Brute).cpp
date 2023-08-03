#include <bits/stdc++.h>
using namespace std;

int uniqueSubstringsBrute(string input){
    if (input.size() == 0 || input.size() == 1)
        return input.size();
    int maxLength = INT_MIN;
    for (int i = 0; i < input.size(); i++){
        unordered_set<char> set;
        for (int j = i; j < input.size(); j++){
            if (set.find(input[j]) != set.end()){
                maxLength = max(maxLength, j - i);
                break;
            }
            set.insert(input[j]);
            maxLength = max(maxLength, j - i + 1);
        }
    }
    return maxLength;
}

int main(){
    string input;
    cin >> input;
    int ans = uniqueSubstringsBrute(input);
    cout << ans << endl;
    return 0;
}
