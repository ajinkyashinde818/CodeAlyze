#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll sum, a[300000], res = 11000000000, s;
int main(void){
    // Your code here!
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        s += a[i];
        res = min(res, abs(sum - s * 2));
    }
    cout << res << endl;
}
