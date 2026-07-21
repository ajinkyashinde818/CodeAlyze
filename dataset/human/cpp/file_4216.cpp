#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll solve(ll t) {
    ll lt = 0;
    ll s = 1;
    ll step = 0;
    while(true) {
        ll nt = lt + 4 * s;
        if(nt>t) break;
        lt = nt;
        s *= 3;
        step += 2;
    }
    // s is max_speed
    // lt is min_t with max_speed=s
    ll r = t - lt;
    while(r>0) {
        ll p = r / s;
        step += p;
        r -= p * s;
        s /= 3;
    }
    return step;
}

int main() {
    ll t;
    cin >> t;
    cout << solve(t) << endl;
}
