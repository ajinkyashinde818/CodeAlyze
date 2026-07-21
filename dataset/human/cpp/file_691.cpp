#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

const ll MOD = 1e9 + 7;

int solve(int n,int a,int b){
	int ans=0;
	for(int i=0;i<=n;i++){
		int res = n - i*a;
		if(res < 0) break;
		if(res%b == 0) ans++;
	}
	return ans;
}

int main()
{
	int r,g,b,n; cin>>r>>g>>b>>n;
	int ans=0;
	for(int i=0;i<=n;i++){
		int res = n - i*r;
		if(res < 0) break;
		ans += solve(res,g,b);
	}

	cout<<ans;
}
