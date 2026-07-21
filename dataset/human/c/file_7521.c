#include <stdio.h>

int main(void)
{
    int x, i;
    char buf[256];
    i = 1;
    while (1)
    {
        fgets(buf, 256, stdin);
        buf[255] = '\0';
        sscanf(buf, "%d", &x);
        if (!x) break;
        printf("Case %d: %d\n", i++, x);
    }

    return 0;
}
