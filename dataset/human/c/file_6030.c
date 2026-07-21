#include <stdio.h>
 
int main()
{
    int max, min, n, i, num[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&num[i]);
 
    min=num[0];
    max=-100000000000;
 
    for (i = 1; i < n; ++i)
        {
            if (max<num[i]-min)max=num[i]-min;
            if (min>num[i])min=num[i];
             
        }  
    printf("%d\n",max);
    return 0;
}
