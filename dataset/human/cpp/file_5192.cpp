#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	if (n >= 10) printf("%d\n", r);
	else printf("%d\n", r + (10 - n) * 100);
	return 0;
}
