#include <stdio.h>
#define MEM 100000

int main(void) {
    int N, M, broken[MEM], b = 0;
    long stairs[MEM];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) scanf("%d", broken+i);

    if (0 != (broken[b]-1)) {
        stairs[0] = 1;
    } else {
        stairs[0] = 0;
        b++;
    }
    if (1 != (broken[b]-1)) {
        stairs[1] = 1 + stairs[0];
    } else {
        stairs[1] = 0;
        b++;
    }

    for (int i = 2; i < N; i++) {
        if (i != broken[b]-1) {
            stairs[i] = stairs[i-1] + stairs[i-2];
            if(stairs[i] >= 1000000007) stairs[i] %= 1000000007;
        } else {
            stairs[i] = 0;
            b++;
        }
    }

    printf("%d\n", stairs[N-1]);
    return 0;
}
