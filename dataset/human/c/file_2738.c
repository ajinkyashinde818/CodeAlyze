#include <stdio.h>

int main(void)
{
    int k,s,a=0,i,j;
    scanf("%d%d",&k,&s);
    for(i=0;i<=k;i++){
        for(j=0;j<=k;j++){
            if(i+j>s)break;
            if(k>=s-i-j)a++;
        }
    }
    printf("%d",a);
    return 0;
}
