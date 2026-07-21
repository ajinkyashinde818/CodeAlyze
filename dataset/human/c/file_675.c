#include <stdio.h>

int n, m;
char a[50][51], b[50][51];

int is(int i, int j)
{
    for (int k = 0; k < m; ++k) {
        for (int l = 0; l < m; ++l) {
            if(a[i+k][j+l] != b[k][l]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", b[i]);
    }

    for (int i = 0; i < n-m+1; ++i) {
        for (int j = 0; j < n-m+1; ++j) {
            if (is(i, j)) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
