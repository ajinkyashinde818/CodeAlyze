// https://atcoder.jp/contests/abc067/tasks/arc078_a
// 5min ~ 10min
#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int ai[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &ai[i]);
    }

    long long total = 0;
    long long sum = 0;
    long long sums[N] = {0};

    // sums[i] is 0 ~ i | i+1 ~ N-1
    for (int i=0; i<N; i++) {
        total += ai[i];

        sum += ai[i];
        sums[i] = sum;
    }

    long long min = 0x7FFFFFFFFFFFFFFFL;
    for (int i=0; i<N-1; i++) {
        long long left = sums[i];
        long long right = total - sums[i];
        
        long long diff = left - right;
        if (diff < 0) {
            diff *= -1;
        }

        if (diff < min) {
            min = diff;
        }
    }

    printf("%d\n", min);

    return 0;
}
