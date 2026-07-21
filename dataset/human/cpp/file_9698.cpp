#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
char s[N];
int cnt[26];
int main(){
    int n;scanf("%d",&n);
    scanf("%s",s+1);
    int ans=1;
    for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
    for(int i=0;i<26;i++) ans=1LL*ans*(cnt[i]+1)%mod;
    ans=(ans-1+mod)%mod;
    printf("%d",ans);
}
