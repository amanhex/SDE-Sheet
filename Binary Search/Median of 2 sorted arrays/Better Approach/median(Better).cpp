#include <bits/stdc++.h>
using namespace std;

double medianBetter(vector<int>& nums1, vector<int>& nums2){
  int n1 = nums1.size(), n2 = nums2.size();
  int i = 0, j = 0;
  int n = n1 + n2;
  int ind2 = n / 2, ind1 = ind2 - 1;
  int cnt = 0;
  int ind1el = -1 , ind2el = -1;
  while (i < nums1.size() && j < nums2.size()){
    if (nums1[i] < nums2[j]){
      if (cnt == ind1) ind1el = nums1[i];
      if (cnt == ind2) ind2el = nums1[i];
      i++, cnt++;
    }
    else{
      if (cnt == ind1) ind1el = nums2[j];
      if (cnt == ind2) ind2el = nums2[j];
      j++, cnt++;
    }
  }

  while (i < n1){
    if (cnt == ind1) ind1el = nums1[i];
    if (cnt == ind2) ind2el = nums1[i];
    i++, cnt++;
  }

  while (j < n2){
    if (cnt == ind1) ind1el = nums2[j];
    if (cnt == ind2) ind2el = nums2[j];
    j++, cnt++;
  }

  if (n % 2 == 0){
    double ans = (double)(ind1el + ind2el) / 2.0;
    return ans;
  }
  else
    return ind2el;
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

  double ans = medianBetter(nums1, nums2);
  cout << ans << endl;
}
