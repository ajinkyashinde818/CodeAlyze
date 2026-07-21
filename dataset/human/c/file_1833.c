#include <stdio.h>

#define MAX_N 20
#define MAX_B 50
#define MAX_C 50

int main(void) {
    int n;
    int as[MAX_N];
    int bs[MAX_B];
    int cs[MAX_C];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        as[i] = x;
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        bs[i] = x;
    }

    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf("%d", &x);
        cs[i] = x;
    }

    // first dish
    int prev = as[0];
    int score = bs[prev - 1];

    for (int i = 1; i < n; i++) {
        int current = as[i];
        score += bs[current - 1];
        if (current == prev + 1) {
            score += cs[prev - 1];
        }
        prev = current;
    }

    printf("%d\n", score);

    return 0;
}
