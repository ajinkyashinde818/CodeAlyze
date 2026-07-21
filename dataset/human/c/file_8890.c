#include <stdbool.h>
#include <stdio.h>
int main() {
    int h, w;
    bool isEnable = true;
    char f[51][51];
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", &f[i]);
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (f[y][x] == '#') {
                if (y + 1 != h && f[y + 1][x] == '.' && y != 0 &&
                    f[y - 1][x] == '.' && x + 1 != w && f[y][x + 1] == '.' &&
                    x != 0 && f[y][x - 1] == '.')
                    isEnable = false;
            }
        }
    }
    if (isEnable)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
