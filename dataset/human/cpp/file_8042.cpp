// acdart
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <numeric>
#include <utility>
#include <queue>
#include <memory>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cstdlib>
#include <list>
#include <limits.h>
#include <utility>
#include <functional>
#include <iterator>
#include <deque>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define F first
#define S second
#define MOD9 1000000009ll
#define MOD7 1000000007ll
#define MOD
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define SZ(x) ((int)(x).size())
#define MAXN 10010
#define MAXM
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/
// #define ONLINE_JUDGE
#define inf 0x3f3f3f3f
#define mod
#define maxm
#define maxn
ll s[200010];
int main()
{/*
	#ifdef ONLINE_JUDGE
    	freopen("aplusb.in", "r", stdin);
    	freopen("aplusb.out", "w", stdout);
	#endif*/
	// ios::sync_with_stdio(false);
	int n, x;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		s[i] = s[i - 1] + x;
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i < n; i++) {
		ans = min(ans, abs(s[n] - s[i] - s[i]));
	}
	printf("%lld\n", ans);
}
