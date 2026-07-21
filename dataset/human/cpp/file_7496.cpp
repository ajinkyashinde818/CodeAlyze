#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <array>
using ll =long long;
using namespace std;
int main() {
    // const int n_max=2*pow(10,5);
    int n;
    ll x=0,X=0,ans=100000000000000000LL;
    cin >> n;
    vector<ll>a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        X+=a[i];
    }
    for (int i=0;i<n;i++) {
        x+=a[i];
        
        if (i+1<n)ans=min(ans,abs(X-2*x));
    }
    cout << ans << endl;
    return 0;

}
