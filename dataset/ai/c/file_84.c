/* Example program. */
#include <stdio.h>
int main(void)
{
    int value = 4;
    printf("%d %c\n", value, 'A' + value % 26);
    return 0;
}
