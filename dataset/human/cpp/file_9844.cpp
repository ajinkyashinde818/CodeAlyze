#include<bits/stdc++.h>
using namespace std;
char s[1000000];
long long f[1000];
int n;
long long ans;
const long long mod=1e9+7;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int l=0;
	for (int i=1;i<=n;i++) f[s[i]-'a']++;
	ans=1;
	for (int i=0;i<=26;i++) ans=(ans*(f[i]+1)%mod);
	cout << (ans+mod-1)%mod << endl;
}
