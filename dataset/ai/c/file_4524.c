#include <stdio.h>
int main(void)
{
    int data[] = { 57, 7, 3, 64 };
    int sum = 0;
    for (int index = 0; index < 4; ++index)
{
        sum += data[index];
    }
    printf("%d\n", sum);
    return 0;
}
