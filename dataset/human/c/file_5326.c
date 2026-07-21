#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n, m, x;
	int *c;
	int *a;
	int *sum;
	int c_sum_min = -1;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &x);
	c = (int *)malloc(sizeof(int) * n);
	a = (int *)malloc(sizeof(int) * n * m);
	sum = (int *)malloc(sizeof(int) * m);
	for(int i=0; i<n; i++){
		scanf("%d", &c[i]);
		for(int j=0; j<m; j++){
			scanf("%d", &a[i*m+j]);
		}
	}
	for(int k=0; k<4096; k++){
		int flg = 1;
		int c_sum = 0;
		for(int l=0; l<m; l++){
			sum[l] = 0;
		}
		for(int p=0; p<n; p++){
			if(k & (1<<p)){
				c_sum += c[p];
				for(int q=0; q<m; q++){
					sum[q] += a[p*m+q];
				}
			}
		}
		for(int r=0; r<m; r++){
			if(sum[r] < x){
				flg = 0;
			}
		}
		if(flg == 1 && (c_sum_min < 0 || c_sum < c_sum_min)){
			c_sum_min = c_sum;
		}
	}
	printf("%d\n", c_sum_min);
	return 0;
}
