#include <stdio.h>

int calculate_pattern(int , int );

int main(void){
	int konstante, sum;
	int pattern;

	scanf("%d %d", &konstante, &sum);
	
	pattern = calculate_pattern(konstante, sum);

	printf("%d\n", pattern);

	return 0;
}

int calculate_pattern(int konstante, int sum){
	int x, y, z;
	int pattern = 0;

	for (x = 0; x <= konstante; x++){
		for (y = 0; y <= konstante; y++){
			z = sum - x - y;
			if (0 <= z&&z <= konstante){
				pattern++;
			}
		}
	}
	return pattern;
}
