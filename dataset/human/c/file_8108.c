#include <stdio.h>

int main()
{
	int a, b, c, d;
	int ab_sq, cd_sq, ans_sq;
	
	scanf( "%d %d %d %d", &a, &b, &c, &d );
	
	ab_sq = a * b;
	cd_sq = c * d;
	
	if ( ab_sq < cd_sq )
	{
		ans_sq = cd_sq;
	}
	else
	{
		ans_sq = ab_sq;
	}
	printf( "%d\n", ans_sq );
	
	return 0;
}
