#include <stdio.h>

int main(int argc, char **argv)
{
    int k, s;
    scanf("%d %d", &k, &s);

    int c = 0;
    for (int x = 0; x <= k; ++x) {
        for (int y = 0; (y <= k && y <= s-x); ++y) {
            int z = s - x - y;
            if (0 <= z && z <= k) {
                c++;
            }
        }
    }
    printf("%d\n", c);
    return 0;
}
