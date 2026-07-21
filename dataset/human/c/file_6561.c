#include <stdio.h>

int main(){
	int n,i,j;
	scanf("%d", &n);
	int num[n];
	for(i=0; i<n; i++){
		scanf("%d", &num[i]);
	}
	int max=num[1]-num[0], min=num[0];
	
	for(i=1; i<n; i++){
			if(max<num[i]-min){
				max=num[i]-min;
			}
			if(min>num[i]){
				min=num[i];
			}
	}
	
		printf("%d\n", max);
		
	return 0;
}
