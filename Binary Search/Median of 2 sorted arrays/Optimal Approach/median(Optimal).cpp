#include <bits/stdc++.h>
using namespace std;

double medianOp(vector<int>& nums1, vector<int>& nums2){
  int n1 = nums1.size();
  int n2 = nums2.size();
  if (n1 > n2) return medianOp(nums2, nums1);

  int low = 0, high = n1;
  int left = (n1 + n2 + 1) / 2;
  int n = n1 + n2;
  while (low <= high){
    int mid1 = low + (high - low) / 2;
    int mid2 = left - mid1;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n1) r1 = nums1[mid1];
    if (mid2 < n2) r2 = nums2[mid2];
    if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
    if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
    if (l1 <= r2 && l2 <= r1){
      if (n % 2 == 1) return max(l1, l2);
      return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
    }
    else if (l1 > r2) high = mid1 - 1;
    else low = mid1 + 1;
  }
  return 0;
}

int main(){
  int size1, size2;
  cin >> size1 >> size2;
  vector<int> nums1(size1), nums2(size2);
  for (int i = 0; i < size1; i++)
    cin >> nums1[i];
  for (int i = 0; i < size2; i++)
    cin >> nums2[i];
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  double ans = medianOp(nums1, nums2);
  cout << ans << endl;
}
