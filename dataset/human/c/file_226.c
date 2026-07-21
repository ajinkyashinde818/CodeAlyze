#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define PI 3.14159265358979323846264338327950L
int main(){
    int n,i;
    scanf("%d",&n);
    ll int a[n],sum=0,min=1000000010,minus=0,zero=0;
    rep(i,n){
        scanf("%lld",&a[i]);
        if(abs(a[i])<min) min=abs(a[i]);
        if(a[i]<0) minus++;
        if(a[i]==0) zero=1;
        sum+=abs(a[i]);
    }
    if(zero==1||minus%2==0){
        printf("%lld",sum);
    }else{
        printf("%lld",sum-2*min);
    }
    return 0;
}
