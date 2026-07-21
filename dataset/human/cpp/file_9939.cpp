#include<iostream>
#include<algorithm>
using namespace std;
string s;
int n;
long mod=1e9+7,cnt[26];
main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
	long ans=1;
	for(int i=0;i<26;i++)ans=ans*(cnt[i]+1)%mod;
	cout<<(ans+mod-1)%mod<<endl;
}
