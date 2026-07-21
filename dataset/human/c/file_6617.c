#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char argv[]){
	int num;
	
	scanf("%d", &num);

	int buf, i, max, min;

	scanf("%d", &min);	
	for(i = 1, max = INT_MIN; i < num; i++){
		scanf("%d", &buf);
		if(max < buf - min)
			max = buf - min;
		if(buf < min)
			min = buf;
	}
	printf("%d\n", max);

	return 0;
}
