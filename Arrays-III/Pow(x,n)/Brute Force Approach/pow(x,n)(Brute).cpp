#include <bits/stdc++.h>
using namespace std;

double myPowBrute(double x, int n){
    if (x == 1 || n == 0)
        return 1;
    double ans = 1;
    long long newN = n;
    if (n < 0){
        newN = -(long long)n;
        x = 1 / x;
    }
    for (int i = 0; i < newN; i++)
        ans *= x;
    return ans;
}

int main(){
    double x;
    int n;
    cin >> x >> n;

    double ans = myPowBrute(x, n);
    cout << ans << endl;
    return 0;
}
