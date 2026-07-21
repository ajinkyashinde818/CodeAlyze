#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
#define INF 2000000000
#define ull unsigned long long

int Min(int a, int b) { return a < b ? a : b; }

int main(){
    int i,j,n,m,x,c[13]={},a[13][13]={},bit,money=0,ans=INF;
    scanf("%d%d%d",&n,&m,&x);
    for (i=0; i<n; i++) {
        scanf("%d",&c[i]);
        for (j=0; j<m; j++) scanf("%d",&a[i][j]);
    }
    for (bit=0; bit<(1<<n); bit++) {
        int sum[13]={};
        money=0;
        for (i=0; i<n; i++) {
            if (bit & (1<<i)) {
                for (j=0; j<m; j++) sum[j]+=a[i][j];
                money+=c[i];
            }
        }
        for (i=0; i<m; i++) if (sum[i]<x) break;
        if (i==m) ans=Min(ans, money);
    }
    if (ans==INF) printf("%d",-1);
    else printf("%d",ans);
    return 0;
}
