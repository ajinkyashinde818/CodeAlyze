#include <stdio.h>

int main(void) {
	// your code goes here
	int n, d, x;
	scanf("%d", &n);
	int a;
	scanf("%d %d", &d, &x);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a);
		if(a==1)
		{
			x += d / a;
		}
		else
		{
			x += ((d - 1) / a) + 1;
		}
		//printf("%d\n", x);
	}
	printf("%d\n", x);
	return 0;
}
