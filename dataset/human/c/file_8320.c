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
	int n,k;
	char s[17];
	scanf("%d",&n);
	scanf(" %s",s);
	scanf(" %d",&k);
	for (int i = 0; i < n; ++i)
	{
		if(s[i] == s[k - 1])	printf("%c",s[k - 1]);
		else printf("*");
	}
	puts("");
	return 0;
}
