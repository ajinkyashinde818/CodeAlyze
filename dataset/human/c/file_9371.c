#include<stdio.h>


int main(void)
{
    int n,d,x,i,j,s,c=0;
    int a[100];
    
    scanf("%d",&n);
    scanf("%d%d",&d,&x);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    for(i=0;i<n;i++){
        for(j=0;j<d;j++){
            if((a[i]*j+1)<=d) c++;
        }
    }   
    s=c+x;
    printf("%d\n",s);
    return 0;
}
