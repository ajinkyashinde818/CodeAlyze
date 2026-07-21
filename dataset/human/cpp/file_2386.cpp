using namespace std;
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(ll i=0;i<n;i++)
#define Rip(i,n) for(int i=1;i<n;i++)
#define ll long long
#define ld long double
#define pi 3.1415926535897932384626433832795028841971693993
#define ee 2.718281828459045
#define mod 1000000007
#define MOD mod
#define sec setprecision
using namespace std;
ll gcd(ll a, ll b) {
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
int ketasuu(ll h) {
	if (h < 0)return(-(ketasuu(-h)));
	else if (h < 10)return(1);
	else return(1 + ketasuu(h / 10));
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
vector<ll> soinnsuubunnkai(ll n) {
	vector<ll>a;
	while (n % 2 == 0) {
		a.push_back(2);
		n /= 2;
	}
	ll f = 3;
	while (f * f <= n) {
		if (n % f == 0) {
			a.push_back(f);
			n /= f;
		}
		else f += 2;
	}
	if (n != 1)
		a.push_back(n);
	return(a);
}
// 二項係数計算
long long com(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
ll pow(ll a, ll b) {
	a = a % mod;
	if (b == 0)return(1);
	else if (b % 2 == 0)return(pow((a * a)%mod, b / 2));
	else return(a * (pow(a, b - 1)));
}
void solve() {
	
}
int main() {
	int n;
	cin >> n;
	int mainasu = 0;
	vector<int>a(n);
	int mi = 1000000000;
	ll sum = 0;
	rip(i, n) {
		cin >> a[i];
		mi = (min(mi, abs(a[i])));
		if (a[i] < 0)mainasu++, sum -= a[i];
		else sum += a[i];
	}
	if (mainasu % 2 == 1)cout << sum -(mi*2) << endl;
	else cout << sum << endl;
}
