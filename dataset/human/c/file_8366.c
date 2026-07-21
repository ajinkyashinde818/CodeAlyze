#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[16], tmp;
    int n, k, i;

    scanf("%d %s %d", &n, s, &k);

    tmp = s[k - 1];
    for (i = 0; i < n; i++)
    {
        if (s[i] != tmp)
        {
            s[i] = '*';
        }
    }

    printf("%s", s);
    return 0;
}
