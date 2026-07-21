#include <stdio.h>


int main(void){
	int n;
	int max;
	
	scanf("%d",&n);
	
	int r[n];
	for(int i =0 ;i < n;i++){
		scanf("%d",&r[i]);
	}
	int min = r[0];
	max = r[1]-r[0];
	for(int i = 1;i<n;i++){
		max = (max > r[i]-min) ? max : r[i]-min;
		min = (min < r[i]) ? min : r[i];
	}
	printf("%d\n",max);
	return 0;
}
