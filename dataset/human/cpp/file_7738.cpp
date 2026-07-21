#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(void){
    int n;
    ll X = 0,x = 0,ans = 100000000000000000LL;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        X += a[i];
    }
    for(int i = 0;i < n;i++){
        x += a[i];
        if(i < n-1)
        ans = min(ans,abs(X-2*x));
    }
    cout << ans << endl;
    return 0;
}
