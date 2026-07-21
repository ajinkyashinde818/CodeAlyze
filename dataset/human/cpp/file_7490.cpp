#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MAXN = 1001000;
const int MOD = 1000000007;
const long long INF = 20000000000L;

long long sum[MAXN];

int main()
{
	long long n, a;
	memset(sum, 0, sizeof(sum));

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}

	long long ans = INF;
	for (int i = 1; i < n; ++i)
		ans = min(ans, abs(sum[n] - sum[i] - sum[i]));
	cout << ans << endl;

	//system("pause");
	return 0;
}
