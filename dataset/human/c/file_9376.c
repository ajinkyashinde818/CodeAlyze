#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<complex>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<queue>

int main()
{
	int n, d, x, a;
	scanf("%d%d%d", &n, &d, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		x += (d - 1) / a + 1;
	}
	printf("%d\n", x);

	return 0;
}
