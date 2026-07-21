#include <stdio.h>

int main()
{
    int a[100];
    int count;

    scanf("%d", &a[0]);
    scanf("%d", &a[1]);
    scanf("%d", &a[2]);

    for(int i=0; i < a[0]; i++)
    {
        scanf("%d", &a[i+3]);
    }

    count = 0;

    for(int i=0; i < a[0]; i++)    //人数分行う
    {
        for(int j=0; a[1] >= (j*(a[i+3]) + 1); ++j) //D日間 
        {
                count = count + 1;
        }
    }

    printf("%d\n", (a[2] + count));

    return 0;
}
