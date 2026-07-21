#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>
#define rep(i, a, b) for (int(i) = (a); i < (b); i++)
using namespace std;

using ll = long long;

typedef pair<int, int> P;

const int INF = 100000000;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;

ll pow_mod(ll x, ll y, ll mod)
{
	ll ans=1;
	for(;y>0;y>>=1){
		if(y&1)(ans*=x)%=mod;
		(x*=x)%=mod;
	}
	return ans;
}

int r, g, b, n,ans;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	//問題文中の添え字が0-indexか1-indexか確認!
	cin >> r >> g >> b >> n;
	rep(i,0,(n/r)+1){
		rep(j,0,((n-i*r)/g)+1){
			if((n-i*r-j*g)%b==0)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
