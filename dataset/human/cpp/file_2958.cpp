#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int neg = 0, zero = 0;
    for(int i=0;i<n;++i){
        cin >> a[i];
        if(a[i] < 0) {
            ++neg;
        } else if(a[i] == 0) {
            ++zero;
        }
    }

    ll ans = 0LL;
    ll abs_min = 1LL << 30;
    for(int i=0;i<n;++i){
        ans += abs(a[i]);
        abs_min = min(abs_min, abs(a[i]));
    }
    if(neg % 2 == 1 && zero == 0) {
        ans -= 2*abs_min;
    }

    cout << ans << endl;


}
