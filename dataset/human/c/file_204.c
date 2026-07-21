#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    long long int x,y,ans=0,min = 100000000,count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i] < 0){
            a[i] *= -1;
            count++;
        }
        ans += a[i];
        if(min > a[i]) {
            min = a[i];
        }
    }
    if(count%2==1){
        printf("%lld",ans-min-min);
    }else{
        printf("%lld",ans);
    }
}
