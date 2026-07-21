#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

const ll MAX_N = 2 * 1e5;
ll N;
ll a[MAX_N];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	ll sum[N];
	memset(sum, 0, sizeof(sum));
	ll X = 0;
	rep(i, 0, N) {
		cin >> a[i];
		if(i == 0) sum[0] = a[0];
		else sum[i] += a[i] + sum[i - 1];
		X += a[i];
	}

	ll min_v = 1e18;
	rep(i, 0, N - 1) {
		ll x = sum[i];
		min_v = min(min_v, abs(2 * x - X));
	}
	cout << min_v << endl;
}
