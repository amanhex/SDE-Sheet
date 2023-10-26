#include <bits/stdc++.h>
using namespace std;

class Medianfinder {
  private:
    vector<int> datastream;
  public:
    Medianfinder(){}

    void addnum(int num){
      datastream.push_back(num);
    }

    double findmedian() {
      sort(datastream.begin(), datastream.end());
      int mid = datastream.size() / 2;
      if (datastream.size() % 2 == 0)
        return (double)(datastream[mid] + datastream[mid - 1]) / 2;
      else
        return (double)(datastream[mid]);
    }
};

int main(){
  Medianfinder obj;
  obj.addnum(1);
  obj.addnum(2);
  cout << obj.findmedian() << " ";
  obj.addnum(3);
  cout << obj.findmedian() << endl;
}
