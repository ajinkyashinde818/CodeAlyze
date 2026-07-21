#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[])
{
	int x;
	scanf("%d",&x);
	printf("%s\n", (x < 1200) ? "ABC" : "ARC");
	return 0;
}
