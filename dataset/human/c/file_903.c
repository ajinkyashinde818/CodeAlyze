#include <stdio.h>

long long int checks[1000000];

int main() {
    long long int N, res = 0;
    scanf("%lld", &N);

    int pos = 0;
    long long int x = 1, sum = 0;
    while (pos < 1000000) {
        sum += x;
        x++;
        checks[pos++] = sum;
    }

    for (long long int i = 2; i * i <= N; i++) {
        if (N % i != 0) continue;

        long long int acc = 0;
        while(N % i == 0) {
            acc++;
            N /= i;
        }

        for (pos = 0; pos < 1000000; pos++) {
            if (acc < checks[pos]) {
                res += pos;
                break;
            }
        }
    }

    if (N != 1) res++;

    printf("%lld\n", res);
}
