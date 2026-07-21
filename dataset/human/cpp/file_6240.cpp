#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
const int M = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
const int oo = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, int> ii;
#define pb push_back 
#define all(c) (c).begin(),(c).end()
int n;
ll c,dp[2][N];
ii v[N];

int main(){
	cin>>n>>c;
	for(int i=1; i<=n; ++i)
		scanf("%lld%d",&v[i].first, &v[i].second);
	ll pos=c,right=0;
	for(int i=n; i; --i){
		right+=v[i].second-(pos-v[i].first);
		pos=v[i].first;
		dp[0][i]=max(dp[0][i+1], right);
	}
	right=0;pos=0;
	for(int i=1; i<=n; ++i){
		right+=v[i].second-(v[i].first-pos);
		pos=v[i].first;
		dp[1][i]=max(dp[1][i-1], right);
	}
	ll ans=0;
	for(int i=1; i<=n; ++i){
		ans=max(ans, max(dp[0][i], dp[1][i]));
		ans=max(ans, dp[0][i]-(c-v[i].first)+dp[1][i-1]);
		ans=max(ans, dp[1][i]-v[i].first+dp[0][i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
