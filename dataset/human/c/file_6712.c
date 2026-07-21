#include <stdio.h>

int friend[512][512];

int main(void)
{
    int n, m;
    int invite[512];
    int a, b;
    int cnt;
    int i, j;

    while (1){
        scanf("%d", &n);
        scanf("%d", &m);
        if (n == 0 && m == 0){
            break;
        }

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                friend[i][j] = 0;
            }
        }
        for (i = 2; i <= n; i++){
            invite[i] = 0;
        }

        for (i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            friend[a][b] = friend[b][a] = 1;
        }

        for (i = 2; i <= n; i++){
            if (friend[1][i] != 1){
                continue;
            }
            invite[i] = 1;
            for (j = 2; j <= n; j++){
                if (friend[i][j] == 1){
                    invite[j] = 1;
                }
            }
        }

        cnt = 0;
        for (i = 2; i <= n; i++){
            if (invite[i] == 1){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return (0);
}
