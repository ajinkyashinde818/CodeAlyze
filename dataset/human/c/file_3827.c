#include <stdio.h>

int main() {
    long x;

    long A, B;
    scanf("%ld %ld", &A, &B);

    long i = 1, j = 1;
    while (1) {
        while (B * j <= A * i) {
            if (A * i == B * j) {
                x = A * i;
                goto OUT;
            }
            j++;
        }
        i++;
    }
    OUT:

    printf("%ld\n", x);
    return 0;
}
