#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int acs(const void *a, const void *b){return *(int*)a - *(int*)b;} /* 1,2,3,4.. */
int des(const void *a, const void *b){return *(int*)b - *(int*)a;} /* 8,7,6,5.. */
#define min(a,b) (a < b ? a: b)
#define max(a,b) (a > b ? a: b)

#define MAXN (20)
#define MOD (998244353)

int a[MAXN];
int b[MAXN];
int c[MAXN];

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&(a[i]));
    for(int i=0;i<n;i++) scanf("%d",&(b[i]));
    for(int i=0;i<n-1;i++) scanf("%d",&(c[i]));

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += b[a[i]-1];
        if(i>=1 && a[i]==(a[i-1]+1))
        {
            ans += c[a[i-1]-1];
        }
    }

    printf("%d\n",ans);
    return 0;
}
