#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n, m;
    int a[100000];
    long long way[100001];
    int i;
    int p;
    long long ans;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    a[m] = INT_MAX;

    for (i = 0; i < n; i++) {
        way[i] = 0;
    }

    p = 0;
    way[0] = 1;
    if (a[0] != 1) {way[1] = 1;} else {p++;}
    for (i = 2; i <= n; i++) {
        if (a[p] == i) {
            p++;
            continue;
        }
        way[i] = way[i - 1] + way[i - 2];
        way[i] %= 1000000007;
    }

    ans = way[n];

    printf("%d\n", ans);

    return 0;
}
