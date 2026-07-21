#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll r,g,b,n,ans;
int main(){
	cin >> r >> g >> b >> n;
	for(ll i=0;i<=n;i+=r)
		for(ll j=0;i+j<=n;j+=g)
			if((n-i-j)%b==0)ans++;
	cout << ans;
    return 0;
}
