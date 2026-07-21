#include <stdio.h>

int main() {
    int N, a[99999];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", a + i);
    }
    int next = a[0] - 1, count = 1;
    for (; next != 1 && count <= N + 1; count++) {
        next = a[next] - 1;
    }
    if (next == 1) printf("%d\n", count);
    else printf("-1\n");

    return 0;
}
