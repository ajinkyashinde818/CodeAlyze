#include<stdio.h>
int main()
{
    int a,b,count=0,n;
    scanf("%d%d",&a,&b);
    for(int i=0;i<=a;i++){
        for(int j=0;j<=a;j++){
         n=b-(i+j);
         if(n>=0&&n<=a){
            count++;
         }
        }
        }

    printf("%d",count);
    return 0;

}
