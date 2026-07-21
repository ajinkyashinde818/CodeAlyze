#include <stdio.h>

#define NUM 200000

int main(void)
{
	int island, bin;
	int place_a, place_b;
	int pickup_a[NUM] = { 0 };
	int pickup_b[NUM] = { 0 };
	int i;
	
	/* ----- input ----- */
	scanf("%d %d", &island, &bin);
	for(i=0; i<bin; i++){
		scanf("%d %d", &place_a, &place_b);
		
		if(place_a == 1)
			pickup_b[place_b-1] = 1;
		if(place_b == island)
			pickup_a[place_a-1] = 1;
	}
	
	/* ----- to_do & output  ----- */
	for(i=0; i<island; i++){
		if(pickup_a[i]==1 && pickup_b[i]==1){
			printf("POSSIBLE");
			return 0;
		}
	}
	
	printf("IMPOSSIBLE");
	
	return 0;
}
