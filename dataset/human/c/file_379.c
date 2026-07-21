#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int ASCttenannoryaku(const void *a,const void *b) {
	return *(int *)a - *(int *)b;
}
int main(void)
{
	int n, a;
	scanf("%d""%d",&n,&a);
	if (n < 10)
		a = a + 100 * (10 - n);

	printf("%d",a);
	return 0;
}
