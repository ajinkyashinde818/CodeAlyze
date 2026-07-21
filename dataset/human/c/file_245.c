#include <stdio.h>

int n;
int a[100000];
unsigned long int sum = 0;

int abs(int a) { if(a > 0) return a; return (-1)*a; }

int main(void)
{
	int i, min = 1000000000, cnt = 0;
	scanf("%d%*c", &n);
	for(i=0;i<n;i++) {
		scanf("%d%*c", &a[i]);
		if(a[i] <= 0) cnt++;
		int tmp = abs(a[i]);
		if(min > tmp) min = tmp;
		sum += tmp;
	}

	if(cnt%2 == 0) printf("%ld", sum);
	else printf("%ld", sum - min*2);
	
	return 0;
}
