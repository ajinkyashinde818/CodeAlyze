#include <stdio.h>

int a[1000001];

int main(void)
{
	int p[10000], i, j, n, ph;
	
	for (i = 2; i <= 1000000; i++)a[i] = 1;
	
	for (i = 2; i * i <= 1000000; i++){
		if (a[i] == 1){
			for (j = i * 2; j <= 1000000; j += i)a[j] = 0;
		}
	}
	
	for(ph = 0, i = 2; ph <= 10000; i++){
		if (a[i] == 1)p[ph++] = i;
	}
	
	for (i = 0; i <= 10000; i++){
		if (i != 0)p[i] += p[i - 1];
	}
	
	while (scanf("%d", &n), n != 0){
		printf("%d\n", p[n - 1]);
	}
	
	
	return (0);
}
