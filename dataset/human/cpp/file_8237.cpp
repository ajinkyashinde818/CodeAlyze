#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> cum(N);
    for(int i=0; i<N; i++){
        int a; cin >> a;
        if(i==0) cum[i] = a;
        else cum[i] = cum[i-1] + a;
    }
    
    ll ans = 1LL<<60;
    for(int i=0; i<N-1; i++){
        ll value = abs(cum[i] - (cum[N-1]-cum[i]));
        ans = min(ans, value);
    }
    
    cout << ans << endl;
    return 0;
}
