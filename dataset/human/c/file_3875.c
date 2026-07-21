#include<stdio.h>
int main(void)
{
	int a, b, k, c[1000], j, l, i=1;
	scanf("%d %d %d", &a, &b, &k);
	for(l=a;l>0;--l){
		if(a%l==0 && b%l==0){
			c[i]=l;
			++i;
		}
	}
			printf("%d", c[k]);
	return 0;
}
