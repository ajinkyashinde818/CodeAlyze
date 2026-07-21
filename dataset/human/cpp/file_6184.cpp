#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(int)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
ll n, m;
string s;
ll in[100050][2];
ll sum[100050];

ll mx1[100050];
ll mx2[100050];
int main() {
	ll N, C, i, j;
	cin >> N >> C;
	for (i = 1; i <= N; i++) cin >> in[i][0] >> in[i][1];
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i][1];

	ll ans = 0;
	ans = max(ans, sum[N] - C);

	for (i = 1; i <= N; i++) mx1[i] = max(mx1[i - 1], sum[i] - 2 * in[i][0]);
	for (i = N; i >= 1; i--) mx2[i] = max(mx2[i + 1], (sum[N] - sum[i - 1]) - (C - in[i][0]));
	for (i = 0; i <= N; i++) ans = max(ans, mx1[i] + mx2[i + 1]);

	for (i = 1; i <= N; i++) mx1[i] = max(mx1[i - 1], sum[i] - in[i][0]);
	for (i = N; i >= 1; i--) mx2[i] = max(mx2[i + 1], (sum[N] - sum[i - 1]) - 2 * (C - in[i][0]));
	for (i = 0; i <= N; i++) ans = max(ans, mx1[i] + mx2[i + 1]);
	cout << ans << endl;
	return 0;
}
