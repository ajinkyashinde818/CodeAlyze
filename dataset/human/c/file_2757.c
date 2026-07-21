#include <stdio.h>

int main() {
    int K, S;
    scanf("%d %d", &K, &S);

    if(S<K) {
        K = S;
    }

    int x=K, y, z;
    if(S>2*K) {
        y = K;
    } else {
        y = S - x;
    }

    z = S - x - y;

    int i, j, k, count=0;
    for(i=x; i>=0; i--) {
        k = z;
        for(j=y; j>=0; j--) {
            if((i<=K)&&(j<=K)&&(k<=K)) {
                count += 1;
            }
            k += 1;
        }
        y += 1;
    }

    printf("%d\n", count);


    return 0;

}
