#include <stdio.h>
#include <math.h>

int main(){
	int k, n;
	scanf("%d%d", &k, &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int min = pow(10, 6);
	for(int i = 0; i < n; i++){
		int clock, counter, tmp;
		if(i == 0){
			clock = a[i+1] - a[i];
			counter = a[i] + (k - a[n-1]);
		}else if(i == n-1){
			clock = a[0] + (k - a[i]);
			counter = a[i] - a[i-1];
		}else{
			clock = a[i+1] - a[i];
			counter = a[i] - a[i-1];
		}
		tmp = k - fmax(clock, counter);
		if(tmp < min){
			min = tmp;
		}
	}
	printf("%d\n", min);
}
