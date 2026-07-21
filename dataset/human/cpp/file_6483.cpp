#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int st;
bool a[200005];
int times;
long long ans;
const int mod=1e9+7; 
int main() {
	cin>>n>>s;
	if(s[0]=='W'||s[2*n-1]=='W') {
		cout<<0;
		return 0;
	}
	times=1;
	a[2*n]=0;
	for(int i=2*n-2;i>=0;i--) {
		if((s[i]=='W'&&times%2)||(s[i]=='B'&&times%2==0)) times++;
		else a[i+1]=1,times--;
		if(times<0) {
			cout<<0;
			return 0;
		}
	}
	if(times!=0) {
		cout<<0;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++) {
		ans*=i;
		ans%=mod;
	}
	times=0;
	for(int i=2*n;i>0;i--) 
		if(a[i]==1) {
			ans*=times;
			times--;
			ans%=mod;
		}
		else times++;
	cout<<ans;
	return 0;
}
