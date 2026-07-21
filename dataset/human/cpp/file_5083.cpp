#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	
	int res = 0;
	if (n < 10)
	{
		res = r + 100 * (10 - n);
	}
	else
	{
		res = r;
	}

	printf("%d\n", res);
	return 0;
}
