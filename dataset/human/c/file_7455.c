#include <stdio.h>


int main(void)
{
	long i = 0,t,j;
	long test[10000];
	do {
		scanf("%d", &t);
		test[i] = t;
		i++;
	} while (t != 0);
	i = i - 2;
	for (j = 0; j <= i; j++){
		printf("Case %d: %d\n",j + 1,test[j]);
	}
	return 0;
}
