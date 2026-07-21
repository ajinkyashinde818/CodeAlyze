#include<iostream>
using namespace std;
const int mod=1e9+7;
int n,tong[30],ans=1;
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++) tong[s[i-1]-'a']++;
	for(int i=1;i<=26;i++) ans=1ll*ans*(tong[i-1]+1)%mod;
	cout<<(ans+mod-1)%mod<<endl;
}
