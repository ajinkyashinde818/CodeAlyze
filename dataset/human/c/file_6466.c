#include <stdio.h>

int main()
{
    int i;
    int n;
    int min, max, input;
    max = -1000000000;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        
        if(i == 0)
        {
            min = input;
        }
        else
        {
            if(max < input - min)
            {
                max = input - min;
            }
            if(min > input)
            {
                min = input;
            }
        }
    }

    printf("%d\n", max);

    return 0;
}
