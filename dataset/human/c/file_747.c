#include<stdio.h>

#define MOD 1000000007

long mod_multi(long a,long b){
    long long int ret;
    ret = a*b;
    if(ret>MOD)ret %= MOD;
    return ret;
}

int main(void){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    long ans = 1;
    int cc[26] = {};
    for(int i = 0;i < n;i++)cc[str[i]-'a']++;
    for(int i = 0;i < 26;i++)ans = mod_multi(ans,cc[i]+1);
    printf("%ld",ans-1);
    return 0;
}
