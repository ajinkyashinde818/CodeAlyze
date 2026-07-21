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
	char s[105000];
	int len;

	scanf("%d%s", &len, s);

	i64 ans = 1;

	for(char c = 'a'; c <= 'z'; ++c) {

		i64 count = 0;
		for(int i = 0; i < len; ++i) {
			if(s[i] == c) {
				count += 1;
			}
		}

		ans = ans * (count + 1) % mod;
	}

	printf("%lld\n", ans - 1);

	return 0;
}

/* waffle */
