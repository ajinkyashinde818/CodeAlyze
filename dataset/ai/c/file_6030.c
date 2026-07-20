#include <stdio.h>
void add_one(int *item)
{
    ++*item;
}
int main(void)
{
    int result = 31;
    add_one(&result);
    printf("%d\n", result);
    return 0;
}
