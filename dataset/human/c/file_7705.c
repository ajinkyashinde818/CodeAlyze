#include <stdio.h>

int main(int argc, char *argv[])
{
    int values[10000] = {};
    int count = 0;
    for (int x; scanf("%d", &x) == 1 && x;)
    {
        values[count++] = x;
    }
    for (int i = 0; i < count; ++i)
    {
        printf("Case %d: %d\n", i + 1, values[i]);
    }
    return 0;
}
