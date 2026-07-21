#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;




int main(){
	int n;
	cin >> n;

	vector<ll> sum(n,0);
	rep(i, 0, n) {
		cin >> sum[i];
	}
	rep(i, 1, n) {
		sum[i] += sum[i - 1];
	}

	ll ans=inf;
	rep(i, 0, n-1) {
		ll sn, ar;
		sn = sum[i];
		ar = sum[n - 1] - sum[i];
		ans = min(ans, abs(sn - ar));
	}

	cout << ans << endl;


	
	return 0;
}
