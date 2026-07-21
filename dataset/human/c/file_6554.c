#include <stdio.h>
int main()
{
    int n, i;
    int R[1000000];
    int max, min, maxv;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &R[i]);
    maxv = -999999999;
    min = R[0];

    for (i = 1; i < n; i++)
    {

       if(maxv < R[i]-min)
       {
           maxv = R[i]-min;
       }
    
        if(min > R[i])
        {
            min = R[i];
        }

    }
        printf("%d\n", maxv);
    return 0;
}
