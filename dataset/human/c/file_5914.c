#include <stdio.h>

int main() {
    int n, min, max;
    scanf("%d", &n);
    int R[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &R[i]);
    }
    max = R[1] - R[0];
    min = R[0];
    for (int j=1; j<n; j++) {
        if ((R[j] - min) > max) {max = R[j] - min;}
        if (R[j] < min) {min = R[j];}
    }
    printf("%d\n", max);
    return 0;
}
