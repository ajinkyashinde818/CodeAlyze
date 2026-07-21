#include <stdio.h>

int main(void)
{
    int n=0,k=0,h=0,count=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h);
        if(h>=k) count+=1;
    }
    printf("%d",count);
    return 0;
}
