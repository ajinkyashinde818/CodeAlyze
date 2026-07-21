#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int32_t n, *a, *b;

void swap (int32_t *x, int32_t *y) {
    int32_t t = *x;
    *x = *y;
    *y = t;
}

int32_t main(){
    scanf("%d", &n);
    a = (int32_t*)malloc(n * sizeof(int32_t));
    b = (int32_t*)malloc(n * sizeof(int32_t));

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[n - i - 1]);

    bool bad = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (a[i] != b[j] && a[j] != b[i]) {
                    swap(&b[i], &b[j]);
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                bad = true;
                break;
            }
        }
    }

    if (bad) {
        puts("No");
        exit(0);
    }

    puts("Yes");
    for (int i = 0; i < n; i++) printf("%d ", b[i]);
    puts("");
    free(a); free(b);
    return 0;
}
