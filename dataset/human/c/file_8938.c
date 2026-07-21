#include <stdio.h>

int main(void) {
    int h, w;
    scanf("%d %d", &h, &w);

    char s[h][w];
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }

    int offset[4][2] = {
        {0, -1},
        {-1, 0},
        {1, 0},
        {0, 1},
    };

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                int flag = 0;
                for (int k = 0; k < 4; k++){
                    int x = i + offset[k][0];
                    int y = j + offset[k][1];

                    if (x < 0 || x >= h) {
                        continue;
                    }
                    if (y < 0 || y >= w) {
                        continue;
                    }

                    if (s[x][y] == '#') {
                        flag = 1;
                    }
                }
                if (flag < 1) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
