#include <stdio.h>
int main(void){
    int n,m,x,i,j,k,check=0;
    long long ans=100000000;
    scanf("%d%d%d",&n,&m,&x);
    int c[n],a[n][m],cnt[m];
    for(i=0;i<n;i++){
        scanf("%d",&c[i]);
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<(1<<n);i++){
        for(j=0;j<m;j++) cnt[j]=0;
        long long cost = 0;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                cost += c[j];
                for(k=0;k<m;k++) cnt[k]+=a[j][k];
            }
        }
        int f=1;
        for(j=0;j<m;j++){
            if(cnt[j]<x){
                f=0;
                break;
            }
        }
        if(f==1 && ans>cost){
            ans = cost;
            check = 1;
        }
    }
    if(check==0) printf("-1");
    else printf("%lld",ans);
}
