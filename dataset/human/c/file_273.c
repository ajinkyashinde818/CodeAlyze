#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
long long minim(long long a, long long b) { return a < b ? a : b; }
long long maxim(long long a, long long b) { return a > b ? a : b; }
int main(){
    long long n,i,sign=0,ans=0,minus,a[100010]={},b[100010]={};
    scanf("%lld",&n);
    for(i=0; i<n; i++){
        scanf("%lld",&a[i]);
    }
    for(i=0; i<n; i++){
        if(a[i]<0)sign++;
    }
    if(sign%2==0){
        for(i=0; i<n; i++){
            ans+=maxim(a[i],-a[i]);
        }
        printf("%lld",ans);
        return 0;
    }
    for(i=0; i<n; i++){
        a[i]=maxim(a[i],-a[i]);
    }
    for(i=0; i<n; i++){
        ans+=a[i];
    }
    minus=a[0];
    for(i=0; i<n; i++){
        minus=minim(minus,a[i]);
    }
    ans-=2*minus;
    printf("%lld",ans);
    return 0;
}
