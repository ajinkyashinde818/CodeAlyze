#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	int K=0,N=0,i=0,max=0,d=0;
	int A[200000];


	scanf("%d %d",&K,&N);

	while(i<N){
		scanf("%d",&A[i]);
		i++;
	}

	i=0;

	while(i<N-1){
		d = abs(A[i]-A[i+1]);
		if(2 * d > K){
			d= K - d;
		}

		if(d>max){
			max = d;
		}
		i++;
	}

	d = abs(A[N-1]-A[0]);
			if(2 * d > K){
				d= K - d;
			}

			if(d>max){
				max = d;
			}


	printf("%d", K-max);

	return 0;
}
