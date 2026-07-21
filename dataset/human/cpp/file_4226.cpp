#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll ans = 1000;

int main() {
    ll t;
    cin >> t;
    ll k = 1, minval = 1, cnt = 1;
    if(t == 0){
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i <= 30; ++i) {
        if(minval > t) continue;
        ll x = t-minval;
        ll cntt = x/k;
        x %= k;
        while(x > 0){
            cntt += x%3;
            x /= 3;
        }
        k *= 3;
        ans = min(ans, cnt+cntt);
        if(k <= 3) minval += k, cnt++;
        else minval += k/3*4, cnt += 2;


    }
    cout << ans << "\n";
    return 0;
}
