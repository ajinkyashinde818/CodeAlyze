#include <stdio.h>

int main(void)
{
    int a[51][51], b[51][51];
    int n,m;
    char c;

    scanf("%d%d\n",&n,&m);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c = getchar();
            if (c == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
        c = getchar();
    }
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            c = getchar();
            if (c == '#')
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
        c = getchar();
    }

    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j <= n-m; j++) {
            if (a[i][j] == b[0][0]) {
                int flag = 1;
                for (int y = 0; y < m; y++) {
                    for (int x = 0; x < m; x++) {
                        if (a[i+y][j+x] != b[y][x]) {
                            flag = 0;
                        }
                        if (flag == 0) break;
                    }
                    if (flag == 0) break;
                }
                if (flag == 1) {
                    puts("Yes");
                    return 0;
                }
            }
        }
    }

    puts("No");

    return 0;
}
