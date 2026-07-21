#include <stdio.h>
#include <stdlib.h>
int a[1<<19];
int cmp(const int* a, const int* b) {
    return *b - *a;
}
int main(void) {
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &a[3 * i], &a[3 * i + 1], &a[3 * i + 2]);
    qsort(a, 3 * n, sizeof(int), cmp);
    for(int i = 1; i < 2 * n; i += 2)
        sum += a[i];
    printf("%lld", sum);
}
