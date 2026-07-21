#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
using Data = pair<ll, vector<int>>;
const ll MOD = 1e9 + 7;
const ll inf = 1LL << 50;
struct edge { ll from; ll to; ll cost; };

ll dp[101010][2];

int main() {
	int n;
	cin >> n;

	vector<ll>a(n);
	rep(i, 0, n)cin >> a[i];

	dp[0][0] = a[0];
	dp[0][1] = -a[0];

	rep(i, 1, n) {
		dp[i][0] = max(dp[i-1][0]+a[i],dp[i-1][1]-a[i]);
		dp[i][1] = max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]);
	}
	cout << dp[n - 1][0] << endl;
	return 0;
}
