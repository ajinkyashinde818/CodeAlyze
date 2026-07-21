#include <stdio.h>

void input(int loop, int *);

int main(void) {
    int N, last_num = -1, manzoku_sum = 0;
    scanf("%d", &N);
    int A[N], B[N], C[N - 1];
    input(N, A);
    input(N, B);
    input(N - 1, C);
    for (int i = 0; i < N; i++) {
        manzoku_sum += B[A[i] - 1];
        if (last_num + 1 == A[i]) {
            manzoku_sum += C[last_num - 1];
        }
        last_num = A[i];
    }
    printf("%d\n", manzoku_sum);
    return 0;
}

void input(int loop, int *array) {
    int tmp;
    for (int i = 0; i < loop; i++) {
        scanf("%d", &tmp);
        array[i] = tmp;
    }
}
