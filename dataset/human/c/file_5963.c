#include<stdio.h>
int main(void) {
    int n, R[200000];
    int max, min;
    int i, j;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &R[i]);
    }

    max = R[1] - R[0];
    min = R[0];

    for(i = 1; i < n; i++) {
        if(max < R[i] - min) {
            max = R[i] - min;
            // printf("MAX: %d\n", max);
        }
        if(min > R[i]) {
            min = R[i];
            // printf("MIN: %d\n", min);
        }
    }

    printf("%d\n", max);

    return 0;
}
