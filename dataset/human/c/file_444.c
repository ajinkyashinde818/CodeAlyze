#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
int acs(const void *a, const void *b){return *(int*)a - *(int*)b;} /* 1,2,3,4.. */
int des(const void *a, const void *b){return *(int*)b - *(int*)a;} /* 8,7,6,5.. */

#define MAXN (200000)
#define MOD (1000000007)

char s[MAXN+1];

uint64_t dp[2][MAXN+1];

int main(void)
{
    int n;
    scanf("%d",&n);
    scanf("%s", s);
    n*=2;

    bool isR;
    isR = false;
    int l = 1;
    uint64_t c;
    c = 1;
    if(s[0]=='W')
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(s[i-1]==s[i])
        {
            isR = !isR;
        }
        if(!isR)
        {
            l++;
        }else
        {
            if(l<=0)
            {
                printf("0\n");
                return 0;               
            }
            c *= l;
            c %= MOD;
            l--;
        }
    }

    if(l!=0)
    {
        printf("0\n");
        return 0;               
    }   

    uint64_t ans;
    ans = 1;
    for(int i=2;i<=(n/2);i++) 
    {
        ans *= i;
        ans %= MOD;
    }
    ans *= c;
    ans %= MOD;

    printf("%ld\n",ans);

    return 0;
}
