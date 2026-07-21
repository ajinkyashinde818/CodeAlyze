#include <stdio.h>

int n, m;
char a[64][64];
char b[64][64];

int same(int y, int x)
{
    int i, j;

    for (i = 0; i < m; ++i){
        for (j = 0; j < m; ++j){
            if (a[y + i][x + j] != b[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int main(void)
{
    int i, j;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) scanf("%s", a[i]);
    for (i = 0; i < m; ++i) scanf("%s", b[i]);

    for (i = 0; i <= n - m; ++i){
        for (j = 0; j <= n - m; ++j){
            if (same(i, j)){
                puts("Yes");
                return 0;
            }
        }
    }

    puts("No");

    return 0;
}
