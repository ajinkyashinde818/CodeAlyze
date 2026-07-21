#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const LL mod=1e9+7;
int read() {
	char ch=getchar();int x=0,f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int gcd_(int a,int b) {return b==0?a:gcd_(b,a%b);}
LL fpow(LL a,LL b) {
	LL res=1;
	while(b) {
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
int main() {
//	cout<<"Accepted!\n";
	int n,r;
	cin>>n>>r;
	if(n>=10) cout<<r;
	else cout<<r+100*(10-n);
	return 0;
}
