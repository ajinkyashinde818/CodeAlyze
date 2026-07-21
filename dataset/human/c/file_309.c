#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a)<(b)?(a):(b))
int main(void){
    long long i,n,ans=0,minus=0,min=1e9,a;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        if(a<0) minus++;
        ans+=abs(a);
        min=min(min,abs(a));
    }
    if(minus%2) ans-=2*min;
    printf("%lld",ans);
}
