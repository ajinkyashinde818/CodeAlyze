/* Example program. */
#include <stdio.h>
int main(void)
{
    int count = 22;
    printf("%d %c\n", count, 'A' + count % 26);
    return 0;
}
