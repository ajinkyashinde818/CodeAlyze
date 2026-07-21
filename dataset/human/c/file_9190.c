#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main()
{
	int N,K,h[100000],i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) scanf("%d", &h[i]);

	int Ans = 0;
	for (i = 0; i < N; i ++) {
		if (h[i] >= K) Ans++;
	}

	
    printf("%d", Ans);
}
