#include <stdio.h>
#define MAXN 200000
#define MAXM 200000

int main()
{
    int N, M;
    int island_from_1[MAXN] = {0};
    int island_to_N[MAXN] = {0};
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1) island_from_1[b-1] = 1;
        if (b == N) island_to_N[a-1] = 1;
    }
    for (int i = 0; i < N; i++)
        if (island_from_1[i] && island_to_N[i]) {
            puts("POSSIBLE");
            return 0;
        }
    puts("IMPOSSIBLE");
    return 0;
}
