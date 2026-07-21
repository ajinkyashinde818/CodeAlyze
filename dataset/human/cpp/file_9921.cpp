#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int cnt[26];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	int ans = 1;
	for(int i=0;i<26;i++)
		ans = 1LL * ans * (1+cnt[i]) % mod;
	ans--;
	if(ans<0)	ans+=mod;
	cout<<ans<<endl;
}
