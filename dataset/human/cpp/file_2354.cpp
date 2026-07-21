#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MaxN = 100000;

int N;

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		int neg = 0;
		LL sum = 0LL;
		int M = 1 << 30;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			if(x < 0) neg++;
			sum += abs(x);
			M = min(M, abs(x));
		}
		//printf("sum = %d neg = %d M = %d\n", sum, neg, M);
		if(neg & 1) sum = sum - 2 * M;
		printf("%lld\n", sum);
	}
	return 0;
}
