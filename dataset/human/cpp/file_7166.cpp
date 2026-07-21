#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
	int N;
	cin >> N;
	int a[N];
	ll sum = 0;
	ll ans;
	for(int i = 0; i < N; i++) cin >> a[i],sum += a[i];
	if(N == 2)
	{
		cout << abs(a[0] - a[1]) << endl;
		return(0);
	}
	ll x,y;
	x = a[0];
	y = sum - a[0];
	ans = abs(x - y);
	for(int i = 1; i < N - 1; i++)
	{
		x += a[i];
		y -= a[i];
		ans = min(ans,abs(x - y));
	}
	cout << ans << endl;

}
