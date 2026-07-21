#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(){
	int n;
	int min;
	int max;
	int temp;
	int i;
		
	scanf("%d", &n);

	for(i=0 ; i<n ; i++){
		scanf("%d", &temp);

		if(i==0){
			min = temp;
			max = -1000000000;
		}
		else{
			if(max < temp - min){
				max = temp - min;
			}
			if(min > temp)
				min = temp;
		}
	}

	printf("%d\n", max);

	return 0;
}
