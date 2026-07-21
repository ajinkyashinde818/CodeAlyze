#include <stdio.h>
#include <stdlib.h>
	int main(){
		int n=0;
		int i=0;
		long long int sum = 0;
		long long int min = 0,x=0;	
		int a[200000];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			sum += a[i];
		}
		min = labs(sum - 2*a[0]);
		for(i=0;i<n-1;i++){
			x = x + a[i];
				if( labs(sum - 2*x) < min){
					min = abs(sum - 2*x);
				}
		}
		printf("%d",min);
		return 0;
	}
