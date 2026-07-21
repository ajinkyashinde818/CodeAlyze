#include <stdio.h>

int main(void)
{
	long long int sho;
	long long int ans;
	long long int x;
	scanf("%lld", &x);
	
	if ((1 <= x) && (x <= 6))
		ans = 1;
	
	else if ((7 <= x) && (x <= 11))
		ans = 2;
	
	else
	{
		sho = x / 11;
		ans = 2 * sho;
		if (x % 11 != 0)
			ans++;
		if (7 <= (x % 11))
			ans++;
	}
	
	printf("%lld", ans);
	
	
	return 0;
}
