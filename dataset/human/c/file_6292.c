#include<stdio.h>
#define D 200000
int main(void)
{
    int i,n,a,b;
    int r[D];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    for(i=0;i<n-1;i++){
        if(i == 0 || a>r[i]){
            a=r[i];
        }if(i == 0 || b<r[i+1]-a){
            b=r[i+1]-a;
        }
    }
    printf("%d\n",b);
    return 0;
}
