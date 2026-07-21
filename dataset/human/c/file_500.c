#include <stdio.h>

int main()
{   long long a[200001],n,i,sum=0,snuke=0,min=1145141919810;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<n-1;i++){
        snuke+=a[i];
        sum-=a[i];
        if(llabs(snuke-sum)<min){
            min=llabs(snuke-sum);
        }
    }
    printf("%lld",min);
    return 0;
}
