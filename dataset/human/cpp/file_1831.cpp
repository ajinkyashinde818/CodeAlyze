#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
int main() {
	int n, m; cin >> n >> m;
	int used[200001] = {};
	int a[100001] = {};
	rep1(i, m) {
		cin >> a[i];
	}
	per1(i, m) {
		if (used[a[i]])continue;
		used[a[i]] = 1;
		cout << a[i] << endl;
	}
	rep1(i, n) {
		if (!used[i]) {
			cout << i << endl;
		}
	}
	return 0;
}
