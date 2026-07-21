#include <stdio.h>

int main(void) {

    int K;
    int N;
    int n[200000];
    int distance = 0;
    int result;
    int i;
    // input 
    scanf("%d %d", &K, &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
    // 途中
    for (i = 1; i < N; i++) {
        if (n[i] - n[i - 1] > distance) {
            distance = n[i] - n[i - 1];
        }
    }

    // 最後の家と最初の家の間
    if (n[0] + (K - n[N - 1]) > distance) {
        distance = n[0] + (K - n[N - 1]);
    }

    result = K - distance;

    printf("%d\n", result);

    return 0;
}
