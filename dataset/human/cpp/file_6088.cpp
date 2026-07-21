#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+50;
const int oo = 1e9;
const int mod = 1e9+7;

pair<ll,ll> a[N];
ll cost[N],cost2[N];
int main(){
	ll n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	ll sum=0;
	for(int i=n-1;i>=0;i--){
		sum += a[i].second;
		cost[i] = max(sum - (c-a[i].first),cost[i+1]);
	}
	sum =0;
	for(int i=0;i<n;i++){
		sum += a[i].second;
		if(i)
			cost2[i] = cost2[i-1];
		cost2[i] = max(sum - a[i].first,cost2[i]);
	}
	ll ans = 0;
	sum = 0;
	for(int i=0;i<n;i++){
		sum += a[i].second;
		ans = max(ans, sum-a[i].first);
		ans = max(ans,sum - a[i].first + cost[i+1] - a[i].first);
	}
	sum = 0;
	for(int i=n-1;i>=0;i--){
		sum += a[i].second;
		ans = max(ans,sum - (c-a[i].first));
		ans = max(ans,sum - (c-a[i].first) + cost2[i-1] - (c-a[i].first));
	}
	cout << ans << endl;
}
