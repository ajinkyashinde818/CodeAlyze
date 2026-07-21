#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define abs(p) ((p)>=(0)?(p):(-(p)))
int main(void){
    char S[3];
    scanf("%s", S);
    if(S[0]==S[1] || S[1]==S[2] || S[0]==S[2]){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}
