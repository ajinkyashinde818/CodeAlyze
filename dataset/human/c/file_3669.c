#include<stdio.h>

int main() {
    // int A, B, tmp, r;
    unsigned long long int A, B, tmp, r, x;

    scanf("%llu %llu", &A, &B);

    x = A * B;

    if (A < B) {
        tmp = A;
        A = B;
        B = tmp;
    }

    r = A % B;
    while (r != 0) {
        A = B;
        B = r;
        r = A % B;
    }

    printf("%llu", x/B);

    return 0;
}
