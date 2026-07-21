#include<stdio.h>
int main()
{
    int n,k,count=0;
    scanf("%d %d",&n,&k);
    int ara[n];
    for(int y=0;y<n;y++){
        scanf("%d",&ara[y]);
    }
    for(int y=0;y<n;y++){
        if(ara[y]>=k)
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;

}
