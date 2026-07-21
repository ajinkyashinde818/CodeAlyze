#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    long long int n, ans=0, keta;
    scanf("%lld", &n);
    if (n%2==1) {
        ans=0;
    } else {
        long long int five=2;
        while (1) {
            five*=5;
            if (n < five) {
                break;
            }
            ans += (n - n%five)/five;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
