#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    int n,k,s,i;
    scanf("%d%d%d",&n,&k,&s);
    for(i=0;i<k;i++)
        printf("%d ",s);
    for(;i<n;i++)
    {
        if(s==1)
            printf("2 ");
        else
            printf("%d ",s-1);
    }
}
