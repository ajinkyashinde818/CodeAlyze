#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const int inf = (int)1.05e9;
const i64 mod = 1e9 + 7;

int main()
{
	int n;
	char s[200005];

	scanf("%d%s", &n, s);

	int opened = 0;
	i64 ans = 1;

	for(int pos = 0; pos < 2 * n; pos++) {

		int cur = ((s[pos] == 'B' ? 1 : 0) + opened);

		if(cur % 2 == 1) {
			opened += 1;
		} else {
			ans = ans * opened % mod;
			opened -= 1;
		}

		if(opened < 0) {
			ans = 0;
		}
	}

	if(opened != 0) {
		ans = 0;
	}

	for(int i = 1; i <= n; i++) {
		ans = ans * i % mod;
	}

	printf("%lld\n", ans);

	return 0;
}

/* waffle */
