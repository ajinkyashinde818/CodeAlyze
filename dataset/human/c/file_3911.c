#include <stdio.h>

int main() {
        int A, B, K;
        int i;
        int lim, ans;

        scanf("%d %d %d", &A, &B, &K);

        if (A < B) {
                A ^= B;
                B ^= A;
                A ^= B;
        }

        if (A / 2 < B) lim = B;
        else lim = A / 2;

        for (i = lim; i > 0; i--) {
                if (A % i == 0 && B % i == 0) K--;
                if (K == 0) {
                        ans = i;
                        break;
                }
        }

        printf("%d\n", ans);

        return 0;
}
