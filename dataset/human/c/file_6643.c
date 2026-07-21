#include <stdio.h>
#include <limits.h>

int main(){
	int line=0;
	scanf("%d", &line);
	long num[line];

	for(int i=0; i<line; i++){
		scanf("%ld",&num[i]);
	}

	long max = LONG_MIN;
	int min = num[0];
	for(int i=1;i <line;i++){
		if(num[i]-min>max){
			max = num[i]-min;
		}
		if(num[i] < min){
			min = num[i];
		}
	}
	printf("%ld\n", max);
	return 0;
}
