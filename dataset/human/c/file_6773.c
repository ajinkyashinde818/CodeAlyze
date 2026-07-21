#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef long long ll;

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll asc(const void* a, const void* b) { return *(ll*)a - *(ll*)b; }

ll dsc(const void* a, const void* b) { return *(ll*)b - *(ll*)a; }

ll n, k, a[200001], max = 0;

bool check(ll d) {
    ll count = 0;
    for (int i=0; i < n; i++) {
        count += (a[i]+d-1) / d-1;
    }
    return (count <= k)?1:0;
}

ll  binary(void) {
    ll r, l;
    r = 0, l = max;
    while (l - r > 1) {
        ll mid = (r + l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        max = (max > a[i]) ? max : a[i];
    }
    ll ans = binary();
    printf("%lld", ans);

    return 0;
}
