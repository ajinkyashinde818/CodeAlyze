#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
        int N, K;
        char *S;
        char *p;
        char c;

        scanf("%d\n", &N);
        S = malloc(N);
        scanf("%s\n", S);
        scanf("%d\n", &K);

        c = S[K-1];

        p = S;
        for (int i = 0; i < N; i++) {
                if (*p != c)
                        *p = '*';
                p++;
        }

        printf("%s", S);
}
