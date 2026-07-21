#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n, k, s;
    int A = 1000000000;
    scanf("%d %d %d", &n, &k, &s);
    for (int i = 0; i < n; i++) {
        if (i < k)
            printf("%d ", s);
        else if (s != A)
            printf("%d ", s + 1);
        else printf("%d ", A - 1);
    }
    return 0;
}
