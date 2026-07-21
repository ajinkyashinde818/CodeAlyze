//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

char A[1 << 20];

int main()
{
	int n;
	scanf("%d%s", &n, A);

	VInt cnt(256, 0);
	int i;
	FOR(i, 0, n) ++cnt[A[i]];

	Int mod = 1e9 + 7;
	Int res = 1;
	FOR(i, 0, SIZE(cnt))
		res = res * (1 + cnt[i]) % mod;

	res = (res + mod - 1) % mod;
	printf("%lld\n", res);
	return 0;
};
