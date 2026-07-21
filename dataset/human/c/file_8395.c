#include <stdio.h>

int main(void) {
    int N, K;
    char S[11];
    char c;

    scanf("%d\n%s\n%d", &N, S, &K);

    c = S[K - 1];
    for (int i = 0; i < N; i++) {
        if (S[i] == c) {
            printf("%c", c);
        } else {
            printf("*");
        }
    }
    printf("\n");

    return 0;
}
