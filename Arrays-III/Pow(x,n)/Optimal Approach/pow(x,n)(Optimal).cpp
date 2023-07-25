#include <bits/stdc++.h>
using namespace std;

double myPowOp(double x, int n){
    if (x == 1 || n == 0)
        return 1;
    double ans = 1;
    long long newN = n;
    if (n < 0){
        newN = -(long long)n;
        x = 1 / x;
    }
    while (newN){
        if (newN % 2){
            ans *= x;
            newN--;
        }
        else{
            x *= x;
            newN /= 2;
        }
    }
    return ans;
}

int main(){
    double x;
    int n;
    cin >> x >> n;

    double ans = myPowOp(x, n);
    cout << ans << endl;
    return 0;
}
