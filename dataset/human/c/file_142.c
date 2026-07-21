#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 998244353
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))
typedef long long lli;
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main()
{
    int R,G,B,n,r=0,g=0,b=0,ans=0;
    scanf("%d%d%d%d",&R,&G,&B,&n);
    for(r=0; r*R<=n; r++) {
        for(g=0; r*R+g*G<=n; g++) {
            if((n-r*R-g*G)%B == 0) {
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
