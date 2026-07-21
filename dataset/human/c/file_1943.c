#include <stdio.h>

int main (void) {
    int n;
    int a[20];
    int b[50];
    int c[50];
    int sum = 0;

    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        scanf("%d", &a[k]);
    }
    for (int k = 0; k < n; k++) {
        scanf("%d", &b[k]);
    }
    for (int k = 0; k < n-1; k++) {
        scanf("%d", &c[k]);
    }

    for (int k = 0; k < n; k++) {
        sum += b[a[k]-1];
        if (a[k+1] == a[k]+1) {
            sum += c[a[k]-1];
        }
    }

    printf("%d\n", sum);




}
