#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define num_max(p,q)((p)>(q)?(p):(q))
#define num_min(p,q)((p)<(q)?(p):(q))
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;//昇順
	 //降順ならreturn *(int*)b - *(int*)a;
}
int main()
{
	int N, K,i,ans=0;
	
	scanf("%d%d", &N, &K);
	int(*h) = (int(*))malloc(N * sizeof(int));
	for (i = 0;i < N;i++)
	{
		scanf("%d", &h[i]);
		if (h[i] >= K)ans++;
	}
	printf("%d\n", ans);
	free(h);
	return 0;
}
