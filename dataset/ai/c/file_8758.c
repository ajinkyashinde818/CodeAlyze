#include <stdio.h>
int main(void)
{
    unsigned number = 68u;
    printf("%u %u\n", number & 1u, (number >> 1) & 1u);
    return 0;
}
