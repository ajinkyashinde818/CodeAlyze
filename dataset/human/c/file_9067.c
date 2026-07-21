#include <stdio.h>

int main(void){
    int N, K, h[100005], x, i;
    scanf("%d%d", &N, &K);
    for (i=1; i<=N; i++) scanf("%d", &h[i]);
    x=0;
    for (i=1; i<=N; i++) {
        if (h[i]>=K) x++;
    }
    printf("%d", x);
    return 0;
}
