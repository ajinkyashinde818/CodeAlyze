#include <stdio.h>

int main(void)
{
        int k, s;
        int x, y;
        int p = 0;

        scanf("%d %d", &k, &s);
        for (x = 0; x <= ((k < s) ? k : s); x++) {
                for (y = 0; y <= ((k < s - x) ? k : s - x); y++) {
                        p += (k >= s - x - y) ? 1: 0;
                }
        }
        printf("%d\n", p);
        return 0;
}
