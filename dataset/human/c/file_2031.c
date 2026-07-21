#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    long long ans;

    scanf("%d %d %d", &a, &b, &c);

    ans = 0;

    if (c > a) {
        ans += a;
        c -= a;
    } else {
        ans += c;
        c = 0;
    }

    if (c > b) {
        ans += b * 2;
        c -= b;
        b = 0;
        if (c > 0) {ans++;} //最後に毒入りを食べることもできる
    } else {
        ans += c * 2;
        b -= c;
    }

    ans += b; //解毒剤入りの美味しいクッキーのみも食べれる

    printf("%lld\n", ans);

    return 0;
}
