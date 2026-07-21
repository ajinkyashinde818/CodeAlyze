#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <functional>

using namespace std;

typedef pair<int, int> P;
#define FOR(i, a, b) for(int (i)=a;(i)<(b);++(i))
#define rep(i, n)  FOR(i,0,n)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define all(c) (c).begin(),(c).end()
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define Print(p) cout<<(p)<<endl
#define _1 first
#define _2 second
#define pb push_back
#define mod 1000000007
#define INF 1050000000000000

const int maxn = 2e5 + 10;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n; cin >> n;
	vl a(maxn);
	ll tmp;
	cin >> a[0];
	FOR(i, 1, n) { cin >> tmp; a[i] = tmp + a[i - 1]; }

	ll ans = INF;
	rep(i, n-1) if (ans > abs(a[n - 1] - 2*a[i])) ans = abs(a[n - 1] - 2*a[i]);

	Print(ans);
	return 0;
}
