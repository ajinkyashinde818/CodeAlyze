#include<stdio.h>
#include<math.h>
int main(void) {
	long long x;
	scanf("%lld", &x);

	if (x % 11 == 0)printf("%lld\n", ((x / 11) * 2));
	else if (x % 11 < 7)printf("%lld\n",(x/11)*2+1);
	else
		printf("%lld\n", ((x / 11) * 2 + 2));

	return 0;
}
