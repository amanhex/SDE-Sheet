// Optimal Solution: Using Merge Sort Algorithm

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high){
        if (nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}

int countPairs(vector<int>& nums, int low, int mid, int high){
    int right = mid + 1, count = 0;
    while (low <= mid && right <= high){
        if ((long long)nums[low] > 2 * (long long)nums[right]){
            count += mid - low + 1;
            right++;
        }
        else
            low++;
    }
    return count;
}

int mergeSort(vector<int>& nums, int low, int high){
    if (low >= high)
        return 0;
    int count = 0;
    int mid = low + (high - low) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return count;
}

int reversePairsOp(vector<int>& nums){
    return mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = reversePairsOp(nums);
    cout << ans << endl;
    return 0;
}
