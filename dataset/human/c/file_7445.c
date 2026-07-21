#include<stdio.h>

main()
{
    int input[10000] = {};
    int i = 1;

    while(1)
    {
        scanf("%d", &input[i]);
        if(input[i] == 0) break;
        i++;
    }

    i = 1;
    while(1)
    {
        if(input[i] == 0) break;
        printf("Case %d: %d\n", i, input[i]);
        i++;
    }
}
