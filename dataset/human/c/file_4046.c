#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int a, b, k;
    int i, m;

    scanf("%d%d%d", &a, &b, &k);

    m = max(a, b);
    for (i = m; i >= 1; i--) {
        if (a%i == 0 && b%i == 0) {k--;}
        if (k <= 0) {break;}
    }
    printf("%d", i);

    return 0;
}
