/*
	submission # - User: herp_sy
	https://atcoder.jp/contests/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[])
{
	int r,g,b,n;
	int rest,ans = 0;
	scanf("%d%d%d%d",&r,&g,&b,&n);
	for (int i = 0; i <= 3000; ++i){
		for (int j = 0; j <= 3000; ++j){
			rest = i * r + j * g;
			if(n >= rest && (n - rest) % b == 0) ++ans;
		}
	}
  printf("%d\n",ans);
  return 0;
}
