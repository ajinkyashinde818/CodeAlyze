#include<stdio.h>
int main()
{
	int participants, total_days, remaining_chocolates, x, ans, i, m;
	scanf("%d %d %d", &participants, &total_days, &remaining_chocolates);
	ans=0;
	for(i=0; i<participants; i++)
	{
		scanf("%d", &x);
		for(m=0; m<total_days; m=m+x)
		{
			ans++;
		}
	}
	printf("%d\n", ans+remaining_chocolates);
	return 0;
}
