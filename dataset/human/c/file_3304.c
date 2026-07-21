#include <stdio.h>
int main(void){
    int k, n;
    int a[200000+5];
    scanf("%d %d", &k, &n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    
    long long int ans=a[0]+k-a[n-1];    // またぐデータ
    long long max=a[0]+k-a[n-1];
    for(int i=1; i<n; i++){
        ans+=a[i]-a[i-1];
        if(a[i]-a[i-1]>max)max=a[i]-a[i-1];
    }
    
    printf("%lld\n", ans-max);
}
