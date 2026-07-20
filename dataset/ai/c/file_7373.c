#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int *items = calloc(7, sizeof *items);
    if (items == NULL) return 1;
    items[0] = 85;
    printf("%d\n", items[0]);
    free(items);
    return 0;
}
