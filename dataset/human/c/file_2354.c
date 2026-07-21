#include <stdio.h>

int main() {
    int n, k, s, i, cnt = 0;
    scanf("%d %d %d", &n, &k, &s);
    for (i = 0; i < n; i++) {
        if (cnt == k) {
            if (s == 1000000000){ printf("%d ", s - 1); }
            else { printf("%d ", s + 1); }
        }else{printf("%d ", s); cnt++;}
    }
    printf("\n");
}
