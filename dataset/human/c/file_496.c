#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MOD 1000000007
#define ll long long

int cmpfunc(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(int argc, char **argv){
    int n,i;
    scanf("%d",&n);
    ll a[n];
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    ll sum[n];
    sum[0]=a[0];
    for(i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    ll total=sum[n-1];
    //ll diff[n];
    //first ppl take sum[0] to sum[n-2]
    ll u=total-2*sum[0];
    if(u<0) u*=-1;
    ll min=u;
    for(i=1;i<=n-2;i++){
        ll ans=total-2*sum[i];
        if(ans<0) ans*=-1;
        if(ans<min) min=ans;
    }
    printf("%lld\n",min);
    return 0;
}
