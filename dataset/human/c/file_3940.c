#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int solve(int a, int b, int k)
{
    int i;

    for (i = 100; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            k--;
            if (k == 0) {return i;}
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int a, b, k;
    int ans;

    scanf("%d %d %d", &a, &b, &k);

    ans = solve(a, b, k);

    printf("%d\n", ans);

    return 0;
}
