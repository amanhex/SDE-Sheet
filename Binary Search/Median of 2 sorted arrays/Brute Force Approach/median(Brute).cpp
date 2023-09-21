#include <bits/stdc++.h>
using namespace std;

double medianBrute(vector<int>& nums1, vector<int>& nums2){
  vector<int> merge;
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()){
    if (nums1[i] < nums2[j])
      merge.push_back(nums1[i++]);
    else
      merge.push_back(nums2[j++]);
  }

  while (i < nums1.size())
    merge.push_back(nums1[i++]);
  
  while (j < nums2.size())
    merge.push_back(nums2[j++]);
  
  int n = merge.size();
  if (n % 2 == 1)
    return (double)merge[n / 2];
  else{
    double ans = (double)(merge[n / 2] + merge[n / 2 -1]) / 2;
    return ans;
  }
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

  double ans = medianBrute(nums1, nums2);
  cout << ans << endl;
}
