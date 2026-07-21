#include<stdio.h>
int main(void)
{
    int a,b,c,k,i,n;
    scanf("%d%d%d",&a,&b,&k);
    n=0;
    if(a>b)
        c=a;
    else 
        c=b;
        
    for(i=c;i>=1 ;i--){
       if (a%i == 0 && b%i == 0)
        n++;
        if(n == k){
            printf("%d",i);
            return 0;             
       }
    }
}
