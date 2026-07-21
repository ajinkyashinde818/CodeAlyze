#include <stdio.h>
int main()
{
	int a[10001],i,k;
	i = 1;
	while (1) {
		scanf("%d",&a[i]);
		if (a[i] == 0) {break; }
		else { i++; }
	}
	k = 1;
	while (1) {
		if (a[k] != 0) { printf("Case %d: %d\n",k, a[k]); k++; }
		else { break; }
	}
	return 0;
}
