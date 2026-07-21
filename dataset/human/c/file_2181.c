#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char S[(int)1e5 + 2] = {};
    intmax_t Q;
    struct query {
        intmax_t T;
        intmax_t F;
        char C;
    } query[(int)2e5];

    char head[(int)2e5 + 2] = {}, foot[(int)2e5 + 2] = {};
    char *sp, *hp = head + 1, *fp = foot + 1;
    intmax_t reverse = 0;

    scanf("%s", &S[1]);
    scanf("%jd", &Q);
    for (size_t i = 0; i < Q; i++) {
        scanf("%jd", &query[i].T);
        if (query[i].T == 2) {
            scanf("%jd %c", &query[i].F, &query[i].C);
        }
    }

    for (size_t i = 0; i < Q; i++) {
        if (query[i].T == 1) {
            reverse++;
        } else {
            if (query[i].F == 1) {
                if (reverse % 2 == 0) {
                    *hp++ = query[i].C;
                } else {
                    *fp++ = query[i].C;
                }
            } else {
                if (reverse % 2 == 0) {
                    *fp++ = query[i].C;
                } else {
                    *hp++ = query[i].C;
                }
            }
        }
    }

    sp = S + strlen(&S[1]) + 1;
    if (reverse % 2 == 0) {
        while (*--hp) {
            putchar(*hp);
        }
        printf("%s", &S[1]);
        printf("%s", &foot[1]);
    } else {
        while (*--fp) {
            putchar(*fp);
        }
        while (*--sp) {
            putchar(*sp);
        }
        printf("%s", &head[1]);
    }
    printf("\n");

    return 0;
}
