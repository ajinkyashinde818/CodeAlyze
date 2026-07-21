#include <stdio.h>

int main() {
    int A, B, K;
    int i, c;
    scanf("%d%d%d", &A, &B, &K);
    for (i=(A < B ? A : B) ; i > 0 ;i--) {
        if (A % i == 0 && B % i == 0) {
            c++;
        }
        if (c == K) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
