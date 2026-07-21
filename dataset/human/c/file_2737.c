#include<stdio.h>

int main() {
    int i, j, z, K, S;
    int count = 0;
    
    scanf("%d %d", &K, &S);

    for (i=0; i<=K; i++) {
        for (j=0; j<=K; j++) {
            z = S - i - j;
            if (z >= 0 && z <= K) count++;
        }
    }
    printf("%d", count);

    return 0;
}
