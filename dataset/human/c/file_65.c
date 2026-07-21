#include<stdio.h>
int main()
{
	int r, g, b, n;
	scanf("%d %d %d %d", &r, &g, &b, &n);
	int ans = 0;
	int i, j;
	for (i = 0; i <= 3000; i++)
		for (j = 0; j <= 3000; j++)
			if(n-i*r-j*g>=0)
				if((n-i*r-j*g)%b==0)
				ans++;
	printf("%d\n", ans);
	return 0;
}
