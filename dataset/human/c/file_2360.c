#include <stdio.h>

int main(void)
{
    char s[3];
    scanf("%s", s);

    char flag = 0;
    for (int i = 0; i < 3; i++)
    {
        flag |= 1 << (s[i] - 0x61);
    }
    if ((flag & 0x07) == 0x07)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}
