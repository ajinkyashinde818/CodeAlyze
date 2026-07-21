#include<stdio.h>

int main(){
    int n;
    long long a[1000000], X=0LL, x=0LL;
    long long res, ans=1000000000000000000LL;
    int i, j;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%lld", &a[i]);
        X+=a[i];
    }

    for(i=0; i<n; i++){
        x+=a[i];
        res=X-2*x;

        if(res<0){
            res*=-1;
        }
        if(res<ans && i+1<n){
            ans=res;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
