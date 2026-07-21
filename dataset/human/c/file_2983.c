#include<stdio.h>
typedef long long LL;
LL a[100005],d[100005];

int main()
{
    int i;
    LL N,t,S=0,S0,n;
    scanf("%lld", &n);
    S0=n*(n+1)/2;
    for(i=1;i<=n;i++){
        scanf("%lld", &a[i]);
        S+=a[i];
    }
    if(S%S0){
        printf("NO");
        return 0;
    }
    N=S/S0;
    for(i=1;i<=n;i++){
        d[i]=a[i%n+1]-a[i];
        t=N-d[i];
        if(t%n||t<0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
