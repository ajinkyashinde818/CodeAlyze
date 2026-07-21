#include <stdio.h>
#include <stdint.h>

int main (void)
{
    char s[4];
    int i;
    uint8_t flag;

    scanf("%s", s);

    for (i = 0; i < 3; i++) {
        flag |= 1 << (s[i] - 'a');
    }

    if (flag == 0x07) puts("Yes"); else puts("No");
}
