/* Example program. */
#include <stdio.h>
int main(void)
{
    int data[] = { 2, 4, 6, 8, 50 }, found = -1;
    for (int index = 0; index < 5; ++index)
{
        if (data[index] == 50)
{ found = index; break; }
    }
    printf("%d\n", found);
    return 0;
}
