#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100000];
long long dp1[100000],dp2[100000],sum[100000];

void solve(){
    dp1[1] = max(a[0]+a[1],-a[0]-a[1]);
    dp2[1] = max(a[0]-a[1],-a[0]+a[1]);
    for(int i=2; i<n; i++){
        dp1[i] = max(dp1[i-1]+a[i],dp2[i-1]-a[i]);
        dp2[i] = max(dp1[i-1]-a[i],dp2[i-1]+a[i]);
    }
    cout << dp1[n-1] << endl;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    solve();
    return 0;
}
