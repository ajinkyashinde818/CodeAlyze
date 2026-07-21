#include<stdio.h>
int main(void)
{
    int n,h[100000],k,i,s=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(i=0;i<n;i++)
        if(h[i]>=k)
            s++;
    printf("%d\n",s);
    return 0;
}
