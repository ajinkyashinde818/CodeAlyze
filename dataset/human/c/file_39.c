#include <stdio.h>

int main(void) {
    int r, g, b ,n, i, j;
    int count = 0;

    scanf("%d%d%d%d", &r, &g, &b, &n);
    for (i=0; i<=n/r; i++){
        for (j=0; j<=(n-i*r)/g; j++){
            if ((n - i*r - j*g) % b == 0) count += 1;
        }
    }

    printf("%d\n", count);

    return 0;
}
