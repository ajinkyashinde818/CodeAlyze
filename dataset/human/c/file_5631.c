#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long long k, score, x;
    int top;

    scanf("%lld",&x);
    score = 0LL;
    k = 0LL;

    k = x/11LL * 2LL;
    // 最初に2~5を上に向ければ初手で6点とれる
    top = 5;
    if (x % 11LL > 6) k += 2LL;
    else if (x % 11LL > 0) k += 1LL;
    
    printf("%lld\n", k);
    return 0;
}
