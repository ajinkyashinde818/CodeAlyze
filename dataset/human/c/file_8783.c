#include<stdio.h>
int main() {
    int h, w, i, j,flag,flag2;
    char s[60][60],sc[60];
    scanf("%d%d", &h, &w);
    for (i = 1; i <= h; i++) {
        scanf("%*c");
        scanf("%s", sc);
        for (j = 1; j <= w; j++)
            s[i][j] = sc[j-1];
    }
    flag2 = 1;
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            flag = 0;
            if (s[i][j] == '#') {
                if (i != 1 && s[i - 1][j] == '#')
                    flag = 1;
                if (i != h && s[i + 1][j] == '#')
                    flag = 1;
                if (j != 1 && s[i][j - 1] == '#')
                    flag = 1;
                if (j != w && s[i][j + 1] == '#')
                    flag = 1;
            }
            else
                flag = 1;
            if (flag == 0)
                flag2 = 0;
        }
    }
    if (flag2 == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
