#include <stdio.h>

int main()
{
    while (true) {
        int h, w;

        scanf("%d %d ", &h, &w);
        if (h == 0 && w == 0) break;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j)
                putchar((i + j) % 2 == 0 ? '#' : '.');
            puts("");
        }

        puts("");
    }
    return 0;
}
