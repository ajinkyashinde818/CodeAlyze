#include <stdio.h>

int main()
{
    int N;
    long long A;

    long long sum;
    long long min;
    int i;
    int zero_count;
    int minus_count;

    scanf("%d", &N);

    zero_count = 0;
    minus_count = 0;
    sum = 0;
    min = 1000000000; /* 10^9 */
    for(i = 0; i < N; i++) {
        scanf("%lld", &A);
        if(A == 0) {
            zero_count += 1;
        } else if(A < 0) {
            minus_count += 1;
            A *= -1;
            sum += A;
            if(A < min) {
                min = A;
            }
        } else {
            sum += A;
            if(A < min) {
                min = A;
            }
        }
    }

    // 負の数が奇数 -> 一番絶対値が小さい数字を負の数にした場合の合計
    // 負の数が偶数 もしくは、 0が1個でもあれば -> 全て正の数にできる
    if(zero_count >= 1 || (minus_count%2) == 0) {
        printf("%lld\n", sum);
    } else {
        printf("%lld\n", sum - (min*2));
    }

    return 0;
}
