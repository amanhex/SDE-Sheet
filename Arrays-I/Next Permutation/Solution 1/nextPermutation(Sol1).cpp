// Solution 1: Create all permutations and find which is the next permutation of the given array (Brute Force)

// Don't use this approach, it will give TLE because T.C: O(n! * n) + O(n)
// We can further optimise the space complexity of this approach by using swapping method

#include <bits/stdc++.h>
using namespace std;

// <--------------------------------------------------------------------------------------------------------------------------------->

void swapp(vector<int>& arr, int i, int index){
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
    return;
}

void permuteBetter(vector<int> arr, vector<vector<int>>& res, int index){
    if (index == arr.size()){
        res.push_back(arr);
        return;
    }
    for (int i = index; i < arr.size(); i++){
        swapp(arr, i, index);
        permuteBetter(arr, res, index + 1);
        swapp(arr, i, index);
    }
}


void nextPermutationSol1Better(vector<int>& arr){
    vector<vector<int>> res;
    int index = 0;
    permuteBetter(arr, res, index);

    // Linear Search for next Permutation
    vector<int> nextPerm;
    sort(res.begin(), res.end());

    bool foundCurrent = false;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == arr)
            foundCurrent = true;
        else if (foundCurrent) {
            nextPerm = res[i];
            break;
        }
    }

    if (nextPerm.empty()) {
        arr = res[0];
    } else {
        arr = nextPerm;
    }
    return;
}

// <-------------------------------------------------------------------------------------------------------------------------------->

void permute(vector<int> arr, vector<int>& ds, vector<vector<int>>& res, vector<int>& freq){
    if (ds.size() == arr.size()){
        res.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++){
        if (!freq[i]){
            ds.push_back(arr[i]);
            freq[i] = 1;
            permute(arr, ds, res, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

void nextPermutationSol1(vector<int>& arr){
    vector<vector<int>> res;
    vector<int> ds;
    vector<int> freq(arr.size(), 0);
    permute(arr, ds, res, freq);

    // linear search for next permutation
    vector<int> nextPerm;
    sort(res.begin(), res.end());

    bool foundCurrent = false;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == arr)
            foundCurrent = true;
        else if (foundCurrent) {
            nextPerm = res[i];
            break;
        }
    }

    if (nextPerm.empty()) {
        arr = res[0];
    } else {
        arr = nextPerm;
    }
    return;
}

// <--------------------------------------------------------------------------------------------------------------------------------->

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    nextPermutationSol1Better(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
