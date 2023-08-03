#include <bits/stdc++.h>
using namespace std;

int uniqueSubstringsBetter(string input){
    if (input.size() == 0 || input.size() == 1)
        return input.size();
    int maxLength = INT_MIN, left = 0, right = 0;
    unordered_set<char> set;
    while (right < input.size()){
        if (set.find(input[right]) != set.end()){
            while (left <= right && set.find(input[right]) != set.end()){
                set.erase(input[left]);
                left++;
            }
        }
        set.insert(input[right]);
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main(){
    string input;
    cin >> input;
    int ans = uniqueSubstringsBetter(input);
    cout << ans << endl;
    return 0;
}
