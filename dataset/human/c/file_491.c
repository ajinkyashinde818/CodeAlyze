#include <stdio.h>
#define DEBUG
int main(void){
	int n;
	scanf("%d", &n);
	long a[n];
	for(int i = 0; i < n; i++){
		scanf("%ld", &a[i]);
	}
	long sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	long min = sum - 2 * a[0];
	long snuke =	a[0], arai = sum - a[0];
	if(min < 0){
		min = -min;
	}
	for(int i = 1; i <= n-2; i++){//a[i]から上をすぬけが取る
		long div;
		snuke += a[i];
		arai -= a[i];
		div = snuke - arai;
		if(div < 0){
			div = -div;
		}
		if(div < min){
			min = div;
		}
	}
	printf("%ld\n", min);
}
