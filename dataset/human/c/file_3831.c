#include<stdio.h>
int main() {
    long a, b, r;
    scanf("%ld %ld", &a, &b);
    long g = a * b;

   
    if (a < b) {
        long tmp = a;
        a = b;
        b = tmp;
    }

    
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    printf("%ld\n", g / b);
    return 0;
}
