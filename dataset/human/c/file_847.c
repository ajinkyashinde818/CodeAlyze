#include <stdio.h>
#include <math.h>

bool isPrime (long long int x) {
    for (long long int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int get_t(int t) {
    int k = 0;
    for (int i = 1; ; i++) {
        k += i;
        if (k > t)
            return i - 1;
    }
}

int main() {
    long long int n = 0, tmp;
    scanf("%lld", &n);

    tmp = n;

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    if (isPrime(n)) {
        printf("1\n");
        return 0;
    }

    int ans = 0;

    for (long long int i = 2; i * i <= tmp; i++) {
        if (isPrime(i)) {
            int t = 0;
            while (n % i == 0) {
                t++;
                n /= i;
            }
            ans += get_t(t);
        }
    }

    if (isPrime(n) && n != 1) {
        ans++;
    }

    printf("%d\n", ans);
}
