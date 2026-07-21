#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long ll;

int asc(const void *arg1,const void *arg2) {return *((int *)arg2)-*((int *)arg1);}

int main(){
    int n,a[300001];
    ll sum=0;
    scanf("%lld",&n);
    for(ll i=0;i<3*n;i++) scanf("%lld",&a[i]);
    qsort(a,3*n,sizeof(int),asc);
    for(ll i=0;i<n;i++) sum+=a[2*i+1];
    printf("%lld",sum);

    return 0;
}
