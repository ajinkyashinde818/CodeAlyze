#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
long long mod=1000000007;

int MIN(int A,int B){
    return A<B?A:B;
}

int MAX(int A,int B){
    return A>B?A:B;
}

int main(void){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long a[m+1];
    for (int i=0; i<m; i++){
        scanf("%lld",&a[i]);
    }
    a[m]=n+1;
    long long ans[n+1];
    for (int i=0; i<n; i++){
        ans[i]=0;
    }
    ans[0]=1;
    ans[1]=1;
    int count=0;
    if (a[0]==1){
        ans[1]=0;
        count++;
    }
    for (int i=2; i<=n; i++){
        if (i!=a[count]){
            ans[i]=(ans[i-2]+ans[i-1])%mod;
        } else {
            ans[i]=0;
            count++;
        }
    }
    printf("%lld\n",ans[n]%mod);
    return 0 ;
}
