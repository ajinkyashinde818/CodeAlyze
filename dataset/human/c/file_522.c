#include<stdio.h>
int main()
{
    long long int i,j,k,sum1=0,sum2=0,min,n,t;
    scanf("%lld",&n);
    long long int array[n];
    for(i=0;i<n;i++){
        scanf("%lld",&array[i]);
        if(i!=0){
            sum2=sum2+array[i];
        }
        else
            sum1=sum1+array[i];
    }
    if(sum1<sum2)
        min=sum2-sum1;
    else
        min=sum1-sum2;
    for(i=1;i<n-1;i++){
        sum1=sum1+array[i];
        sum2=sum2-array[i];
        if(sum2>sum1){
            if((sum2-sum1)<min)
                min=sum2-sum1;
        }
        else{
            if((sum1-sum2)<min)
                min=sum1-sum2;
        }
    }
    printf("%lld\n",min);
    return 0;
}
