#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 9876543219876
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
ll MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pll p[100000], rev[100000];
ll max1[100000], max2[100000];
int main() {
	int n;
	ll c;
	scanf("%d%lld", &n, &c);
	fup(i, 0, n - 1, 1)scanf("%lld%lld", &p[i].X, &p[i].Y);
	fup(i, 0, n - 1, 1)rev[i] = mp(c - p[n - i - 1].X, p[n - i - 1].Y);
	ll temp = 0;
	fup(i, 0, n - 1, 1)
	{
		temp += p[i].Y;
		if (i == 0)max1[i] = max(0LL,temp - p[i].X);
		else max1[i] = max(max1[i-1], temp - p[i].X);
	}
	temp = 0;
	fup(i, 0, n - 1, 1)
	{
		temp += rev[i].Y;
		if (i == 0)max2[i] = max(0LL,temp - rev[i].X);
		else max2[i] = max(max2[i - 1], temp - rev[i].X);
	}
	ll ans = max(max1[n - 1], max2[n - 1]);
	temp = 0;
	fup(i, 0, n - 2, 1)
	{
		temp += p[i].Y;
		ans = max(ans, max2[n - i - 2] + temp - p[i].X * 2);
	}
	temp = 0;
	fup(i, 0, n - 2, 1)
	{
		temp += rev[i].Y;
		ans = max(ans, max1[n - i - 2] + temp - rev[i].X * 2);
	}
	printf("%lld", ans);
}
