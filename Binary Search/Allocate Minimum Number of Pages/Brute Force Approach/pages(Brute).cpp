#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& books, int pages){
  int n = books.size();
  int students = 1;
  long long sum = 0;
  for (int i = 0; i < n; i++){
    if (sum + books[i] <= pages)
      sum += books[i];
    else{
      students++;
      sum = books[i];
    }
  }
  return students;
}

int pagesBrute(vector<int>& books, int n){
  if (n > books.size()) return -1;

  int low = *max_element(books.begin(), books.end());
  int high = accumulate(books.begin(), books.end(), 0);

  for (int i = low; i <= high; i++){
    if (countStudents(books, i) == n)
      return i;
  }
  
  return low;
}

int main(){
  int size, n;
  cin >> size >> n;
  vector<int> books(size);
  for (int i = 0; i < size; i++)
    cin >> books[i];

  int ans = pagesBrute(books, n);
  cout << ans << endl;
  return 0;
}
