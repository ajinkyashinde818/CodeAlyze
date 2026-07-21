#include <stdio.h>
int main() {
    int A, B, K, cnt = 0;
    if (scanf("%d %d %d", &A, &B, &K) == -1) return -1;
    for (int i = ((A > B) ? B : A); i >= 1; i--) {
        if (A % i == 0 && B % i == 0) cnt++;
        if (cnt == K) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
