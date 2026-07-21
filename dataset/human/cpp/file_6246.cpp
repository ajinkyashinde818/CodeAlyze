#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,v[N];
long long c,x[N],s[N],a[N],b[N],ans,MX,mx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i=1;i<=n;i++){
		cin >> x[i] >> v[i];
		s[i]=s[i-1]+v[i];
		a[i]=max(a[i-1],s[i]-x[i]*2);
		b[i]=max(b[i-1],s[i]-x[i]);
	}
	ans=b[n];
	for (int i=n;i;i--){
		MX=max(MX,s[n]-s[i-1]-(c-x[i])*2);
		mx=max(mx,s[n]-s[i-1]-(c-x[i]));
		ans=max(ans,max(a[i-1]+mx,b[i-1]+MX));
	}
	cout << ans << "\n";
}
