#include <stdio.h>
#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>



int main()
{

	int N;
	scanf("%d", &N);

	if (N % 10 == 9 ||
		N / 10 == 9) puts("Yes");
	else puts("No");

	return 0;
}
