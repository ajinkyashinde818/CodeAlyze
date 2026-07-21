#include <stdio.h>

int main() {
    int i;
    int N, K, h[1000000];
    int ans = 0;

    scanf("%d %d", &N, &K);
    for(i = 0; i < N; i++) {
        scanf("%d", &h[i]);
        if (h[i] >= K) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
