#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

int main (void)
{
    intmax_t H, W, K;
    char s[300][301];
    intmax_t strawberry[300];
    intmax_t ans[300][301] = {};
    intmax_t n = 1;

    scanf("%jd%jd%jd", &H, &W, &K);
    for (size_t h = 0; h < H; h++) {
        scanf("%s", &s[h][0]);
        strawberry[h] = 0;
        for (size_t w = 0; w < W; w++) {
            if (s[h][w] == '#')
                strawberry[h]++;
        }
    }

    for (size_t h = 0; h < H; h++) {
        if (strawberry[h] == 0) continue;
        intmax_t tmp = strawberry[h];
        for (size_t w = 0; w < W; w++) {
            ans[h][w] = n;
            if (s[h][w] == '#') {
                tmp--;
                if (tmp > 0)
                    n++;
            }
        }
        n++;
    }

    if (strawberry[0] == 0) {
        size_t tmp = 1;
        while (strawberry[tmp] == 0) tmp++;
        for (size_t h = tmp; h > 0; h--) {
            for (size_t w = 0; w < W; w++) {
                ans[h - 1][w] = ans[h][w];
            }
        }
    }

    for (size_t h = 1; h < H; h++) {
        if (strawberry[h] > 0) continue;
        for (size_t w = 0; w < W; w++) {
            ans[h][w] = ans[h - 1][w];
        }
    }

    for (size_t h = 0; h < H; h++) {
        for (size_t w = 0; w < W; w++) {
            printf("%jd ", ans[h][w]);
        }
        printf("\n");
    }

    return 0;
}
