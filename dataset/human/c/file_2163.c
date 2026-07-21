#include <stdio.h>

int main(void) {
    long long N, x, p, i, j;
    scanf("%lld", &N);
    if (N%2==1) {
        printf("0");
        return 0;
    }
    x=0; j=1;
    while (1) {
        p=2;
        for (i=1; i<=j; i++) p*=5;
        if (N/p!=0) x+=N/p;
        else break;
        j++;
    }
    printf("%lld", x);
    return 0;
}
