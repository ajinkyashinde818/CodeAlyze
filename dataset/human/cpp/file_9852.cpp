#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5,maxm=2e2,mod=1e9+7;
int n,lim,cnt[maxn];
long long Ans=1;
char s[maxn];

int main(){
	scanf("%d",&n);
	scanf(" %s",s+1);
	for(int i=1;i<=n;i++){cnt[s[i]-'a']++;}
	for(int i=0;i<26;i++){
		Ans=(Ans*(cnt[i]+1))%mod;
	}
	Ans=(Ans+mod-1)%mod;
	printf("%lld",Ans);
	return 0;
}
