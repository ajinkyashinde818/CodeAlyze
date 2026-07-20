#include <stdio.h>
void add_one(int *item)
{
    ++*item;
}
int main(void)
{
    int number = 64;
    add_one(&number);
    printf("%d\n", number);
    return 0;
}
