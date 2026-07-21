#include <stdio.h>

int main()
{
    int R, G, B, N;

    scanf("%d %d %d %d", &R, &G, &B, &N);

    int sum = 0;
    int tmp_N = 0;

    int ans_count = 0;
    for (int i = 0; i <= N; i++) {
        if (R * i > N)
        {
            continue;
        }
        for (int j = 0; j <= N; j++) {
            tmp_N = N;
            sum = R * i + j * G;
            tmp_N -= sum;

            if (tmp_N < 0) {
                continue;
            }

            if (tmp_N % B == 0)
            {
                // printf("%d%d\n", i, j);
                ans_count++;
            }
        }
    }

    printf("%d", ans_count);
    return 0;
}
