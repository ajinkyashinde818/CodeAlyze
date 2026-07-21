#include<bits/stdc++.h>
using namespace std;
char s[100007];
int vis[37];
const long long mod =1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<26;i++)
        vis[i]++;
    for(int i=0;i<n;i++)
        vis[s[i]-'a']++;
    long long ans=1;
    for(int i=0;i<26;i++){
        ans*=vis[i];
        ans%=mod;
    }
    ans=(ans+mod-1)%mod;
    printf("%lld",ans);
    return 0;
}
