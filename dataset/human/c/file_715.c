#include<stdio.h>
int main() {
    long long c[33], ans = 1,n,i;
    char s[111111];
    scanf("%lld%*c%s",&n, s);
    for (i = 0; i < 26; i++)
        c[i] = 0;
    for (i = 0; i < n; i++) 
        c[s[i]-'a']++;
    for (i = 0; i < 26; i++){
        ans = ans * (c[i] + 1);
        if (ans > 1000000007)
            ans =ans% 1000000007;
    }
    ans--;
    if (ans == -1)
        ans += 1000000007;
    printf("%lld\n", ans);
    return 0;
}
