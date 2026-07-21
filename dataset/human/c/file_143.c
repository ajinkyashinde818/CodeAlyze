#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int r=0, g=0, b=0, n=0;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    int count = 0;
    for (int i=0; i<=n/r; i++) {
        int buf = n-r*i;
        for (int j=0; j<=buf/g; j++) {
            int buf2 = buf - g*j;
            if (buf2%b == 0) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
