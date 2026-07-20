#include <stdio.h>
void add_one(int *item)
{
    ++*item;
}
int main(void)
{
    int value = 5;
    add_one(&value);
    printf("%d\n", value);
    return 0;
}
