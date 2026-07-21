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
	int n,a[100007];
	int now = 0,cnt = 0,chk[100007] = { 0 };	// 0: NoProblem, 1:self-Loop
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)	scanf("%d",&a[i]);	// Loading
	do{
		++cnt;
		chk[now] = 1;
		now = a[now] - 1;
		if(chk[now]){
			puts("-1");
			return 0;
		}
	}while(now != 1);
	printf("%d\n", cnt);
	return 0;
}
