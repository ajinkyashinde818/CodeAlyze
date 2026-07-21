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
	int n,i;
	int ans = 0;
	int old_ai=-1;
	int a[21], b[21], c[21];
	scanf("%d", &n);
	for (i = 1;i <= n;i++)scanf("%d", &a[i]);
	for (i = 1;i <= n;i++)scanf("%d", &b[i]);
	for (i = 1;i <= n-1;i++)scanf("%d", &c[i]);
	for (i = 1;i <= n;i++)
	{
		
		ans += b[a[i]];
		if (old_ai + 1 == a[i])ans += c[old_ai];
		old_ai = a[i];
		
	}
	printf("%d\n", ans);
	return 0;
}
