#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int asc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n == m) printf("Yes");
    else printf("No");
}
