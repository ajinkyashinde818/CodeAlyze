#include<stdio.h>
int main(void)
{
    int i,n,k[1000],p[1000],a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&k[i],&p[i]);
    }
    for(i=0;i<n;i++){
        a=k[i]%p[i];
        if(a==0) a=p[i];
        printf("%d\n",a);
    }
    return 0;
}
