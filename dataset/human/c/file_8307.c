#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 1000000007
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))
typedef long long lli;
int cmp(const void *a, const void *b) {
    if((*(lli*)b - *(lli*)a) > 0) {
        return 1;
    } else if((*(lli*)b - *(lli*)a) < 0) {
        return -1;
    }
    return 0;
}

int main()
{
    int n, i, k;
    char s[10];
    scanf("%d%s%d",&n,s,&k);
    for(i=0; i<n; i++) {
        if(s[i]!=s[k-1]) {
            s[i] = '*';
        }
    }
    printf("%s",s);
    return 0;
}
