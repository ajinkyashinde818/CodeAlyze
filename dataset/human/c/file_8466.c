#include<stdio.h>
int main(void)
{
	int n, m,a[1002],i,j=1,temp;
	scanf("%d %d",&n,&m);
	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	
	while (j != m+1) {
		i = 0;
		while (i != n-1) {
			if (a[i] % j > a[i + 1] % j) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	for (i = 0; i < n; i++)printf("%d\n",a[i]);
	return 0;
}
