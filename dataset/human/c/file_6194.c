#include <stdio.h>
#include <math.h>

//  ????°?????????????
#ifndef min
#define min(a, b)            (((a) < (b)) ? (a) : (b))
#endif
//  ?????§????????????
#ifndef max
#define max(a, b)            (((a) > (b)) ? (a) : (b))
#endif

#define DEF_ELM_MAX 200000

	int R[DEF_ELM_MAX];

int MAXDIFF(int *Array, int num)
{
	int maxv = Array[1] - Array[0];
	int minv = Array[0];
	int i;

	for ( i = 1 ; i < num ; i++ ) {
		maxv = max(maxv, (Array[i]-minv));
		minv = min(minv, Array[i]);
	}
	return maxv;
}

int main(void)
{
	int N;
	int i;

	int ans;

	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &R[i]);
	}

	ans = MAXDIFF(R, N);

	printf("%d\n", ans);
	return 0;
}
