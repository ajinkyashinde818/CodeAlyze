#include<stdio.h>
#include<limits.h>


int main(void){
    long long int n, m, a[100005]={}, b[100005]={}, l=0, s=1;
    scanf("%lld %lld", &n, &m);
    a[0]=-1;
    for(int i=1; i<=m; i++){
        scanf("%lld", &a[i]);
    }
    a[m+1]=n+1;
    for(int i=0; i<=m; i++){
        a[i]=a[i+1]-a[i]-1;
    }
    for(int i=0; i<=m; i++){
        if(a[i]>l){
            l=a[i];
        }
    }
    b[0]=0;
    b[1]=1;
    for(int i=2; i<=l; i++){
        b[i]=(b[i-1]+b[i-2])%1000000007;
    }
    for(int i=0; i<=m; i++){
        s=(s*(b[a[i]]%1000000007))%1000000007;
    }
    printf("%lld", s);
    return 0;
}
