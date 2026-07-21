#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long max(unsigned long x, unsigned long y) {
    if(x > y) return x;
    return y;
}
unsigned long min(unsigned long x, unsigned long y) {
    if(x < y) return x;
    return y;
}


unsigned long pau(unsigned long a, unsigned long b) {
    int i;
    unsigned long ans = 1;
    for(i=0; i<b; i++) {
        ans *= a;
    }
    return ans;
}

void hoge(unsigned long a, unsigned long b) {
    unsigned long *A = (unsigned long*)malloc((a+1) * sizeof(unsigned long));
    unsigned long *B = (unsigned long*)malloc((a+1) * sizeof(unsigned long));
    unsigned long *C = (unsigned long*)malloc((a+1) * sizeof(unsigned long));
    unsigned long i;
    for(i=0; i<a+1; i++) {
        A[i] = 0;
        B[i] = 0;
    }
    unsigned long x = a;
    unsigned long y = b;
    i = 2;
    while(x != 1 && x >= i) {
        if(x % i == 0) {
            A[i]++;
            x = x / i;
        }
        else {
            i++;
        }
    }
    i = 2;
    while(y != 1 && y >= i) {
        if(y % i == 0) {
            B[i]++;
            y = y / i;
        }
        else {
            i++;
        }
    }
    unsigned long ans = 1;
    for(i=2; i<=a; i++) {
        C[i] = max(A[i], B[i]);
        // printf("%lu = %lu\n", i, C[i]);
        if(C[i] != 0) {
            ans *= pau(i, C[i]);
        }
    }
    printf("%lu\n", ans);
    free(A);
    free(B);
    free(C);
}

int main() {
    unsigned long A, B;
    scanf("%lu %lu", &A, &B);
    // printf("%lu\n", lcm(A, B));
    hoge(max(A, B), min(A, B));
    return 0;
}
