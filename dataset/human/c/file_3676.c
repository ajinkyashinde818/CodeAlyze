#include <stdio.h>

long long a, b;

long long gcd(long long a, long long b) {
    return (b ? gcd(b, a % b) : a);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    scanf("%d%d", &a, &b);
    printf("%lld\n", lcm(a, b));
}
