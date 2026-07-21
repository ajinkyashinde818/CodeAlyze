#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll a[n];
    ll dp1[n];
    ll dp2[n];
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        a[i] = x;
        dp1[i] = 0;
        dp2[i] = 0;
    }
    dp1[0] = a[0];
    for(int i = 1; i < n; i++){
        dp1[i] = dp1[i-1] + a[i];
    }
    dp2[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        dp2[i] = dp2[i+1] + a[i];
    }
    ll ans = 2000000001LL;
    for(int i = 0; i < n-1; i++){
        ans = min(ans, abs(dp1[i] - dp2[i+1]));
    }
    cout << ans << endl;
    return 0;
}
