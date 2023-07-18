// Optimal Approach: Calculate the minPrice at each iteration and check the profit

#include <bits/stdc++.h>
using namespace std;

int stockBuyAndSellOptimal(vector<int>& arr){
    int maxProfit = 0, minPrice = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] < minPrice)
            minPrice = arr[i];
        if (arr[i] - minPrice > maxProfit)
            maxProfit = arr[i] - minPrice;
    }
    return maxProfit;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = stockBuyAndSellOptimal(arr);
    cout << ans << endl;
    return 0;
}
