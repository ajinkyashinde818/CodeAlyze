#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <limits.h>
using namespace std;
using ll = long long;

int main(){
    ll ans=0;
    ll m=LONG_MAX;
    ll N,cnt=0;
    cin >> N;
    for(ll i=0;i<N;i++){
        ll a;
        cin >> a;
        if (a<0) cnt++;
        ans+=abs(a);
        m = min(m,abs(a));
    }

    if (cnt%2==1) ans-=2*m;
    cout << ans;

    return 0;
}
