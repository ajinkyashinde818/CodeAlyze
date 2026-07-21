#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,l,r,d) for(ll i=(l);i<(r);i+=(d))
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define abs(p) ((p)>=(0)?(p):(-(p)))
char s[60][60];
int main(void){
    ll H, W;
    scanf("%lld %lld", &H, &W);
    rep(i, 1, H+1, 1) scanf("%s", s[i]+1);
    rep(i, 1, H+1, 1){
        rep(j, 1, W+1, 1){
            if(s[i][j]=='#'){
                if(s[i-1][j]!='#' && s[i+1][j]!='#' && s[i][j-1]!='#' && s[i][j+1]!='#'){
                    printf("No\n");
                    return 0;
                }
            }
        }
    }
    printf("Yes\n");
    return 0;
}
