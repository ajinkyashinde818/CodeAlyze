#define N 200005
#include <stdio.h>
int main() {
    int n = 0;
    int R[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }
    int maxv = -2000000000;
    int minv = R[0];
    for (int i = 1; i < n; i++) {
        if (R[i] - minv > maxv) {
            maxv = R[i] - minv;
        }
        if (R[i] < minv) {
            minv = R[i];
        }
    }
    printf("%d\n", maxv);
    return 0;
}
