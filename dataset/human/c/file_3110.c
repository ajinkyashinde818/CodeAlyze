#include<stdio.h>
#define ll long long 
int main(){
    ll k,n,i;
    scanf("%lld%lld",&k,&n);
    ll a[n];
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    ll b[n+1];
    b[n]=k-a[n-1]+a[0];
    for(i=1;i<n;i++) b[i]=a[i]-a[i-1];
    ll p=1;
    ll m=b[1];
    for(i=1;i<n+1;i++)
        if(m<b[i]){
            m=b[i];
            p=i;
        }
    ll ans=0;
    ans=k-b[p];
    printf("%lld\n",ans);
    return 0;
}
