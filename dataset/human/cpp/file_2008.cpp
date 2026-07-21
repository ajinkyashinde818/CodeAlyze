#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100000;
const LL INF = 1LL << 60;
int n, cnt;
LL a, Min, sum;
int main() {
	scanf("%d", &n);
	Min = INF;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a);
		Min = min(Min, abs(a));
		sum += abs(a);
		if(a < 0)cnt++;
	}
	if(cnt & 1)sum -= 2 * Min;
	printf("%lld\n", sum);
	return 0;
}
