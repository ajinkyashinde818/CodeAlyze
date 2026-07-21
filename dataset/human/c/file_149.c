#include <stdio.h>
typedef long long ll;

ll R, G, B;
ll n;

ll ans;

int main()
{
    scanf("%lld %lld %lld", &R, &G, &B);
    scanf("%lld", &n);

    for (ll r = 0; r <= 3000; r++) {
        for (ll g = 0; g <= 3000; g++) {
            ll b = n - (r * R + g * G);

            if (b % B == 0 && b >= 0) {
                ans++;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
