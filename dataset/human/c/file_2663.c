/*

f(n,k) = answer if there is no restriction
f(n,k) = choose(n+k-1,n)
g(i) = answer with the restriction on i

obviously, use the g(2k+2-i) = g(i) optimization once k+2 is reached

if k was large enough, these formulae are (probably) true
g(2) = g(3) = f(n,k-1)+f(n-1,k-1)
g(4) = g(5) = f(n,k-2)+2*f(n-1,k-2)+f(n-2,k-2)

i have no idea why

*/

#include <stdio.h>

const int MOD=998244353;

long long pascal[4010][4010];

long long f(int n,int k)
{
    if (n+k-1<0) return 0;
    if (n<0) return 0;
    return pascal[n+k-1][n];
}

int n,k;

long long ans[4010];

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    pascal[0][0]=1;
    for (int i=1; i<4005; i++) {
        pascal[i][0]=1;
        for (int j=1; j<4005; j++) {
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%MOD;
        }
    }
    scanf("%d%d",&k,&n);
    for (int i=1; i<=k; i++) {
        for (int j=0; j<=i; j++) {
            ans[i]=(ans[i]+f(n-j,k-i)*pascal[i][j])%MOD;
        }
    }
    for (int i=2; i<=2*k; i++) {
        int j=i;
        if (j>2*k+2-j) j=2*k+2-j;       // g(2k+2-i) = g(i) optimization
        printf("%lld\n",ans[j/2]);
    }
}
