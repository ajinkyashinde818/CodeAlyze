#include <stdio.h>

#define MOD 1000000007

int main()
{
    int n,bucket[26] = {0},i,j;
    char s[100001];

    scanf("%d %s",&n,s);
    for (i = 0; i < n; i++)
    {
        bucket[s[i] - 'a']++;
    }

    long long ans = 1;

    for (i = 0; i < 26; i++)
    {
        ans *= bucket[i] + 1;
        ans %= MOD;
    }
    
    printf("%lld",ans - 1);
}
