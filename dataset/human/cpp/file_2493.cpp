#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
ll a[N];
ll n;
inline  ll r(){
	char ch;
	ll ans=0,f = 1;
	ch = getchar();
	while(ch>'9' || ch<'0'){if(ch=='-') f*=-1; ch = getchar(); 	}
	while(ch>='0' && ch<='9'){ans = ans*10	+ ch - '0';  ch = getchar();}
	return ans*f;
}
int main (){
	n = r();
	ll ans = 0;
	int fushu = 0;
	for(int i=1;i<=n;i++){
	
		a[i] = r();
		if(a[i]<0) fushu ++;
		ans = ans + abs(a[i]);
		a[i] = abs(a[i]);	
	}
	sort(a+1,a+n+1);
	if(fushu%2==1) ans = ans - 2*a[1];
	cout<<ans<<endl;
	
}
