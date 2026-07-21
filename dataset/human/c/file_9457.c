#include <stdio.h>

int main() {
    int N, D, X, ans = 0, tmp = 0;
    scanf("%d", &N);
    scanf("%d %d", &D, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if (D % tmp == 0) {
            ans += D / tmp;
        } else {
            ans += D / tmp + 1;
        }
    }
    printf("%d\n", ans + X);
    return 0;
}
