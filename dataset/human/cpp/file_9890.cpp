#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int MOD = (int) 1e9 + 7;

int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}

const int N = (int) 1e5 + 100;
const int ALP = 26;
char str[N];
int cnt[ALP];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        cnt[str[i] - 'a']++;

    int ans = 1;
    for (int i = 0; i < ALP; i++)
        ans = mul(ans, (cnt[i] + 1));

    ssub(ans, 1);
    printf("%d\n", ans);


	return 0;
}
