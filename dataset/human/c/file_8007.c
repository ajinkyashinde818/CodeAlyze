//  cd Desktop/Atcoder
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,n) for(i=0;i<(n);i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MYPOW_t ull

MYPOW_t Mypow(MYPOW_t x,MYPOW_t n){
    MYPOW_t ret=1;
    while (n>0) {
        if (n&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return ret;
}

int Max(int a, int b) { return a > b ? a : b; }

int main(){
    ull x,y,i,j,n,dn=0,X,Y,ans=0,I=1,DN=1,I_DN=1;
    scanf("%lld%lld",&x,&y);
    n=Max(x,y);
    rep(i,n+1){
        if (i!=0){
            I*=i;I%=MOD;
        }
        I_DN=I;
        X=i;Y=i*2;dn=0;DN=1;
        if ((x-X)%2==0){
            if ((x-X)/2==y-Y){
                dn=y-Y;
                rep(j,dn){
                    DN*=(j+1)%MOD;DN%=MOD;
                    I_DN*=(i+j+1)%MOD;I_DN%=MOD;
                }
                ans+=(I_DN*Mypow((I*DN)%MOD,MOD-2))%MOD;
                ans%=MOD;
            }
        }
    }
    printf("%lld",ans%MOD);
    return 0;
}
