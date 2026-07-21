#include <stdio.h>

int main(void)
{
    int num_datasets=0, input[10001];
    do
    {
        scanf("%d", &input[num_datasets]);

    } while (input[num_datasets++]);

    int i = 0;
    while (input[i] != 0)
    {
        printf("Case %d: %d\n", i+1, input[i]);
        i++;
    }

    return(0);
}
