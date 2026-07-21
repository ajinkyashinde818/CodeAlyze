#include <stdio.h>

int main()
{
	int a,b,k,ret;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&k);

	for (ret=100;ret>=1;ret--) {
		if (a%ret!=0) continue;
		if (b%ret!=0) continue;

		k--;
		if (k==0) break;
	}

	


	printf("%d\n",ret);
	return 0;
}
