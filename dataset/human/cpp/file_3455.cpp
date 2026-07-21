#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n;
    vector<ll> a;
    bool has_zero = false;
    int neg_parity = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll v;
        scanf("%lld", &v);
        if (v == 0LL) {
            has_zero = true;
            a.push_back(0LL);
        } else if (v < 0LL) {
            neg_parity ^= 1;
            a.push_back(-v);
        } else {
            a.push_back(v);
        }
    }

    ll total = 0LL;
    for (auto aa : a)
        total += aa;

    if (has_zero) {
        printf("%lld\n", total);
    } else if (neg_parity == 1) {
        sort(a.begin(), a.end());
        printf("%lld\n", total - 2 * a[0]);
    } else {
        printf("%lld\n", total);
    }

    return 0;
}
