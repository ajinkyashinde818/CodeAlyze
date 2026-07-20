#include <stdio.h>
int main(void)
{
    int data[] = { 79, 25, 3, 104 };
    int sum = 0;
    for (int index = 0; index < 4; ++index)
{
        sum += data[index];
    }
    printf("%d\n", sum);
    return 0;
}
