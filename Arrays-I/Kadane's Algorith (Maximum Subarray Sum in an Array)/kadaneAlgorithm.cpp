// Kadane’s Algorithm : Maximum Subarray Sum in an Array

#include <bits/stdc++.h>
using namespace std;

int kadaneAlgorithm(vector<int> arr){
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}


// Returns the subarray with the maximum sum
vector<int> kadaneAlgorithm2(vector<int> arr){
    vector<int> res;
    vector<int> maxRes; // Track the subarray with the maximum sum
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        res.push_back(arr[i]); // Add the current element to the temporary subarray
        if (sum > maxSum){
            maxSum = sum;
            maxRes = res; // Update the subarray with the maximum sum
        }
        if (sum < 0){
            sum = 0;
            res.clear(); // Clear the temporary subarray
        }
    }
    return maxRes;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = kadaneAlgorithm(arr);
    cout << ans << endl;
    vector<int> res = kadaneAlgorithm2(arr);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
