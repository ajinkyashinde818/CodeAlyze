#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	int a, b, cnt = 0, flag = 0;
	
	while(t--)
	{
		scanf("%d %d", &a, &b);
		if(a == b) cnt++;
		else cnt = 0;
		//printf("%d\n ", cnt);
		if(cnt >= 3) flag = 1;
	}
	
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
