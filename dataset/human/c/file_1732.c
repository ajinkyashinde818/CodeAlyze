#include <stdio.h>


int main(void){
	int n;	// total
	int a[20];
	int b[50];
	int c[50];
	int s_sum;
	int k;

	scanf("%d", &n);

	for(k = 0; k < n; k++){
		scanf("%d", &a[k]);
	}
	for(k = 0; k < n; k++){
		scanf("%d", &b[k]);
	}
	for(k = 0; k < n-1; k++){
		scanf("%d", &c[k]);
	}

	s_sum = 0;
	for(k = 0; k < n; k++){
		s_sum += b[a[k]-1];
		if ((k >= 1)&&(a[k]-a[k-1]==1)) {
			s_sum += c[a[k-1]-1];
		}
	}

	printf("%d\n", s_sum);

	return 0;
}
