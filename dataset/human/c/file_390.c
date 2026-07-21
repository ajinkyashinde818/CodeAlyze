#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 200010
#define MAX 1000000000000000000
#define MOD 1000000007

#include <stdio.h>

int main (void) {
    int n, r;

    scanf("%d %d", &n, &r);

    if (n >= 10) {
        printf("%d", r);
    } else {
        printf("%d", r + (100 * (10 - n)));
    }

    return 0;
}
