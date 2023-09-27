#include <bits/stdc++.h>
using namespace std;

int countstudent(vector<int>& books, int pages){
  int students = 1;
  long long sum = 0;
  for (int i = 0; i < books.size(); i++){
    if (sum + books[i] <= pages)
      sum += books[i];
    else{
      sum = books[i];
      students++;
    }
  }
  return students;
}

int pagesop(vector<int>& books, int n){
  if (n > books.size()) return -1;

  int low = *max_element(books.begin(), books.end());
  int high = accumulate(books.begin(), books.end(), 0);

  while (low <= high){
    int mid = low + (high - low) / 2;
    int numstudents = countstudent(books, mid);
    if (numstudents <= n) high = mid - 1;
    else low = mid + 1;
  }

  return low;
}

int main(){
  int size, n;
  cin >> size >> n;
  vector<int> books(size);
  for (int i = 0; i < size; i++)
    cin >> books[i];
  
  int ans = pagesop(books, n);
  cout << ans << endl;
  return 0;
}
