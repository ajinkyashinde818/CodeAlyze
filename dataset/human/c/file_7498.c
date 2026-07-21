#include<stdio.h>
#define min(a,b) ((a) < (b) ? a : b)
#define max(a,b) ((a) > (b) ? a : b)
main()
{

    int i,a[100000],count;
    count=0;
    for(i=0;i<=100000;i++)
    {
        scanf("%d",&a[i]);
        count++;
        if(a[i]==0)
            break;
    }
    for(i=0;i<count-1;i++)
    {
        printf("Case %d: %d\n",i+1,a[i]);
    }


    return 0;




}
