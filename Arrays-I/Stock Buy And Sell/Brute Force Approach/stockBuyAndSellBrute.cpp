// Brute Force Approach: Iterate the array twice (check the profit for each element) and return the maxProfit

#include <bits/stdc++.h>
using namespace std;

int stockBuyAndSellBrute(vector<int> arr){
    int maxProfit = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            int profit = arr[j] - arr[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = stockBuyAndSellBrute(arr);
    cout << ans << endl;
    return 0;
}
