/*
    Print Test Cases
*/

#include <stdio.h>

int main(void)
{
    int index[10000] = {0};
    int i;

    for (i = 0; i < 10000; i++) {
        scanf("%d", &index[i]);
        if (index[i] == 0)
            break;

        printf("Case %d: %d\n", i+1, index[i]);
    }
    return (0);
}
