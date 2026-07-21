#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
// #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
	#define errp(...)
	#define dbg(x) 
#endif

const int N = 100010;
ll n, a[N], sm, mn, neg;

int main () { 
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sm = neg = 0;
	mn = (ll)1e18;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) { a[i] *= -1; neg++; }
		sm += a[i];
		mn = min(mn, a[i]);
	}
	if (neg & 1) sm -= 2 * mn;
	printf("%lld\n", sm);
}
