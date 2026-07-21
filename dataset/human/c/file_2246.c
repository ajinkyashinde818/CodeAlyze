#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a): (b))
#define max(a, b) ((a) > (b) ? (a): (b))

int n;
int down[1024][1024];
int right[1024][1024];

int side(int y, int x)
{
    int d;
    int r;
    int s = min(down[y][x], right[y][x]);
    int i;

    for (i = 1; i < s; i++){
        int t = min(down[y][x + i], right[y + i][x]);
        s = min(s, t);
    }

    return s;
}

int main(void)
{
    while (scanf("%d", &n), n){
        char map[1024][1024];
        int maxi = 0;
        int i, j, k;

        for (i = 0; i < n; i++){
            scanf("%s", map[i]);
        }

        for (i = 0; i < n; i++){
            int d = 0;
            int r = 0;

            for (j = n - 1; j >= 0; j--){
                d = map[j][i] == '.' ? d + 1 : 0;
                down[j][i] = d;
                r = map[i][j] == '.' ? r + 1 : 0;
                right[i][j] = r;
            }
        }

        for (i = 0; i < n - maxi; i++){
            for (j = 0; j < n - maxi; j++){
                int s = side(i, j);
                maxi = max(maxi, s);
            }
        }

        printf("%d\n", maxi);
    }

    return 0;
}
