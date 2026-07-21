#include<stdio.h>

int main(void){
    int n,m,a,i,fibo[100000],b=1000000007;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+1;i++){
        fibo[i]=1;
    }
    for(i=0;i<m;i++){
        scanf("%d",&a);
        fibo[a]=0;
    }
    for(i=2;i<n+1;i++){
        if(fibo[i]!=0){
            fibo[i]=fibo[i-1]+fibo[i-2];
            if(fibo[i]>b){
                fibo[i]%=b;
            }
        }
    }
    printf("%d",fibo[n]);
    return 0;
}
