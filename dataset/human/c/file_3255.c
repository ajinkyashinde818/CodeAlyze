#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int
main(int argc, char *argv[])
{
    unsigned int K, N;

    scanf("%u %u", &K, &N);

    unsigned int *hs = malloc(sizeof(unsigned int) * N);
    if (hs == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < N; i++) {
        unsigned int a;
        scanf("%u", &a);
        hs[i] = a;
    }

    unsigned int max = hs[0] + K - hs[N - 1];
    int start = 0;
    fprintf(stderr, "max = %u start = %d\n", max, start);
    for (int i = 0; i < N - 1; i++) {
        unsigned int delta = hs[i + 1] - hs[i];
        if (delta > max) {
            max = delta;
            start = i + 1;
            fprintf(stderr, "max = %u start = %d\n", max, start);
        }
    }

    unsigned int distance;
    if (start > 0) {
        distance = (K - hs[start]) + hs[start - 1];
    }
    else {
        distance = hs[N - 1] - hs[0];
    }

    printf("%u \n", distance);

    return EXIT_SUCCESS;
}
