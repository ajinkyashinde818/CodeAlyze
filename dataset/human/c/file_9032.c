#include <stdio.h>

int n, m;
int a[100010];
int count;

int main(void)
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", &a[i]);
		
		if(a[i] >= m)
			count++;
	}
	
	printf("%d", count);
	return 0;
}
