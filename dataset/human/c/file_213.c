#include <stdio.h>
#include <stdint.h>
#include <math.h>
#define MIN(x, y) ((x)<(y)?(x):(y))
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,n) FOR(i,0,n)

int main() {
    int n;
    scanf("%d", &n);
    
    int minus = 0, zero = 0;
    int64_t tot = 0, mini = (1LL << 62);
    rep(i, n) {
        int64_t a;
        scanf("%ld", &a); 
        minus += a < 0;
        tot += abs(a);
        zero |= a == 0;
        mini = MIN(mini, abs(a));
    }
    
    if (minus % 2 == 0 || zero)
        printf("%ld", tot);
    else
        printf("%ld", tot - 2 * mini);
}
