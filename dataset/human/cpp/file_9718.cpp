#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,fre[26]={0};
	string str;
	long long ans=1;
	const int mod=1e9+7;
	cin>>n;
	cin>>str;
	for(int i=0;i<str.length();++i)
		fre[str[i]-'a']++;
	for(int i=0;i<26;++i)
		ans=(ans*(fre[i]+1))%mod;
	ans=(ans+mod-1)%mod;
	printf("%lld\n",ans);
	return 0;
}
