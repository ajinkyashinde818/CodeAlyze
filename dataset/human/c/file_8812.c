#include <stdio.h>

int main (void)
{
    int h, w, i, j;
    char s[52][52];

    for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
            s[i][j] = 0;
        }
    }

    scanf("%d %d", &h, &w);
    for (i = 1; i <= h; ++i) {
        scanf("%s", &s[i][1]);
    }

    for (i = 1; i <= h; ++i) {
        for (j = 1; j <= w; ++j) {
            if (s[i][j] != '#') continue;
            if (s[i - 1][j] == '#') continue;
            else if (s[i][j - 1] == '#') continue;
            else if (s[i + 1][j] == '#') continue;
            else if (s[i][j + 1] == '#') continue;
            else {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
}
