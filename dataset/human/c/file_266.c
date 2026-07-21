#include <stdio.h>
#define INF 2147483647

int main(int argc, char** argv)
{
	int n, min = INF, cnt = 0;
	scanf("%d", &n);
	long long ans = 0;
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x < 0) cnt ++, x = -x;
		if(x < min) min = x;
		ans += x;
	}
	printf("%lld\n", cnt & 1? ans - (min << 1): ans);
	return 0;
}
