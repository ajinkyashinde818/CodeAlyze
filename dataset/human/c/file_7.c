#include <stdio.h>

int main()
{
	int r,g,b,n,sum = 0;
	scanf("%d %d %d %d",&r,&g,&b,&n);
	for(int i = 0;i <= n / r;i++){
		for(int j = 0;j <= n / g;j++){
			if((n - i * r - g * j) % b == 0 && n - i * r - g * j >= 0) sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
