#include <stdio.h>

int main(void){
	int n, d, x, i, j, cho, count;
	int a[100];

	scanf("%d", &n);
	scanf("%d %d", &d, &x);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
//	printf("%d %d %d\n", n, d, x);

	cho = 0;
	for(i=0; i<n; i++){
		j = 0;
		count = 0;
		while(a[i]*j+1<=d){
			j++;
		//	printf("pacpac  %d\n", j);
		}
		cho += j;
	}
	cho += x;
	printf("%d\n", cho);

	return 0;
}
