#include <stdio.h>
typedef long long ll;

ll LCM(ll a, ll b)
{
    ll x = a * b, r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return (x / b);
}

int main(void)
{
    ll a, b;

    scanf("%lld%lld", &a, &b);

    printf("%lld\n", LCM(a, b));

    return 0;
}
