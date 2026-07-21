#include<stdio.h>

int main()
{
    int sum=0;
    int i,j,n,count=0;
    int prime[105000]={0};

    for(i = 2;i <= 105000;i++) prime[i]=1;

    for(i = 2;i <= 105000;i++){
        if(prime[i]){
            for(j=i+i;j<=105000;j+=i) prime[j]=0;
            prime[i]=++count;
        }
    }

    while(scanf("%d",&n),n){

        sum=0;

        for(i=0;prime[i]<n;i++){
            if(prime[i]!=0){
                sum+=i;
            }
        }
        sum+=i;

        printf("%lld\n",sum);

    }
    return 0;
}
