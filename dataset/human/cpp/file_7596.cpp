#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long ll;
const int INF = 1<<31; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> vec;
	for(int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		vec.push_back(x);
	}
	reverse(vec.begin(), vec.end());
	vector<ll> num(n + 1, 0);
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
			num[i] += vec[i];
		else
			num[i] += num[i - 1] + vec[i];
	}
	ll ans = 1LL<<60;
	ll x, y;
	for(int i = 0; i < n - 1; i++)
	{
		x = num[i];
		y = num[n - 1] - x;
		ans = min(abs(x - y), ans);
		//cout << x << " " << y << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
